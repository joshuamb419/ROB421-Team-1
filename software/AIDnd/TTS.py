from gtts import gTTS
from playsound import playsound

def speak(text):
    tts = gTTS(text)
    tts.save('response.mp3')
    return

async def speak_async(text):
    tts = gTTS(text)
    tts.save('response.mp3')
    return