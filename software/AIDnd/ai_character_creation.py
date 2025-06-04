import asyncio

from ollama_wrapper import OllamaWrapper
from sami_controller import SamiControll
import STT
import TTS
import DiceRoll

async def talk_while_moving(text, behavior):
    await asyncio.gather(sami.perform_behavior_async(behavior), TTS.speak_async(text))

def create_character():
    # Prompt the player for a class    
    asyncio.run(talk_while_moving("What class do you want to be? You can select from the following", "GestureWithRightHand.json"))
    asyncio.run(talk_while_moving("Wizard", "RightPointTop.json"))
    asyncio.run(talk_while_moving("Fighter", "RightPointMiddle.json"))
    asyncio.run(talk_while_moving("Druid", "RightPointBottomMiddle.json"))
    asyncio.run(talk_while_moving("Or any other dnd class", "RightPointBottom.json"))

    # Save class and prompt ai for a message
    character_class = STT.transcribe()
    print(character_class)
    ai_response = ai_client.chat(f"Write a one sentence welcome for a dnd player of class {character_class}")
    print(ai_response)
    TTS.speak(ai_response)

    # Prompt player for a race
    asyncio.run(talk_while_moving("What race do you want to be? Choose any of the following", "ReturnHandsToSides.json"))
    asyncio.run(talk_while_moving("Elf", "LeftPointTop.json"))
    asyncio.run(talk_while_moving("Dwarf", "LeftPointMiddle.json"))
    asyncio.run(talk_while_moving("Human", "LeftPointBottomMiddle.json"))
    asyncio.run(talk_while_moving("Or some other dnd race", "LeftPointBottom.json"))

    # Save race and prompt ai for a message
    character_race = STT.transcribe()
    ai_response = ai_client.chat(f"Write a one sentence welcome for this player having chosen to be the {character_race} race")
    asyncio.run(talk_while_moving(ai_response, "ReturnHandsToSides.json"))

    # Take the characters name
    TTS.speak("What is your name?")
    name = STT.transcribe()

    return (character_class, character_race, name)

def characterCreation():
    ai_client.reset()
    player_count = int(input("How many characters are we creating?\n"))
    characters = []
    characters_txt = ""
    for i in range(player_count):
        character = create_character()
        characters.append(character)
        characters_txt += f"Player {i+1}: Class {character[0]}, Race {character[1]}, Name {character[2]}\n"
        print(characters_txt)
        ai_client.reset()

    return characters_txt

def interpretResponse(response):
    print(f"Response: {response}")    
    if '{' in response:
        dice_string = response.split('"Sides": ')[1]
        dice_string = dice_string[:-2]
        print(response[response.index("{")+1:response.index("}")])
        side_count = int(dice_string)

        dice_result = DiceRoll.face_roll(sami, roll_range=(1, side_count))
        interpretResponse(response[:response.index("{")] + ai_client.chat(str(dice_result)))
        return

    last_emote = None
    speech_txt = ""
    while ']' in response:
        end_idx = response.index(']')
        start = response[:end_idx]
        response = response[(end_idx+1):]

        start_idx = start.index('[')
        speech_txt = start[:start_idx]

        if last_emote is None and len(speech_txt) != 0:
            print("here")
            TTS.speak(speech_txt)
        elif len(speech_txt) != 0:
            print("here2")
            asyncio.run(talk_while_moving(speech_txt, last_emote))

        last_emote = start[start_idx+1:] + ".json"

    speech_txt = response
    if last_emote is None:
        TTS.speak(speech_txt)
    else:
        asyncio.run(talk_while_moving(speech_txt, last_emote))

def runSession(characters):
    initial_prompt = "Say error occured"
    with open('AIDnd/gemma3_prompt.txt', 'r') as file:
        initial_prompt = "\n".join(file.readlines())
        initial_prompt += f"\nIn your campaign are the following characters:\n{characters}"

    ai_client.reset()
    response = ai_client.chat(initial_prompt)

    while True:
        # TTS.speak(response)
        interpretResponse(response)
        input = STT.transcribe()
        response = ai_client.chat(input)

sami = SamiControll(arduino_port='/dev/ttyUSB0')

credentials = open("ollama_credentials", "r").readline()
ai_client = OllamaWrapper(model="gemma3:4b", credentials=credentials)
# print(ai_client.chat("Hello?"))

# characters = characterCreation()
runSession("Name: Bob, Class: Rouge")