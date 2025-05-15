import asyncio

from ollama_wrapper import OllamaWrapper
from sami_controller import SamiControll
import STT
import TTS

async def talk_while_moving(text, behavior):
    asyncio.gather(sami.perform_behavior_async(behavior), TTS.speak_async(text))

def create_character():
    # Prompt the player for a class    
    asyncio.run(talk_while_moving("What class do you want to be? You can select from the following", "GestureWithRightHand.json"))
    asyncio.run(talk_while_moving("Wizard", "RightPointTop.json"))
    asyncio.run(talk_while_moving("Fighter", "RightPointMiddle.json"))
    asyncio.run(talk_while_moving("Wizard", "RightPointBottomMiddle.json"))
    asyncio.run(talk_while_moving("Or any other dnd class", "RightPointBottom.json"))

    # Save class and prompt ai for a message
    character_class = STT.transcribe()
    ai_response = ai_client.chat(f"Write a one sentence welcome for a dnd player of class {character_class}")
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
        characters_txt = f"Player {i+1}: Class {character[0]}, Race {character[1]}, Name {character[2]}\n"
        ai_client.reset()

    ai_response = ai_client.chat(f"You are a dungeon master for a dnd campaign. Welcome your breifly players to the campaign and in three sentences or less describe the opening scene. The following is a list of the players character:\n{characters_txt}")
    TTS.speak(ai_response)

sami = SamiControll(arduino_port='/dev/tty/USB0')

credentials = open("ollama_credentials", "r").readline()
ai_client = OllamaWrapper(model="gemma3:1b", credentials=credentials)

create_character()