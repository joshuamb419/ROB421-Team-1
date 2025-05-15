from gtts import gTTS
import playsound

def speak(text):
    tts = gTTS(text)
    tts.save('response.wav')

    playsound.playsound('response.wav')
    return

async def speak_async(text):
    tts = gTTS(text)
    tts.save('response.wav')

    playsound.playsound('response.wav')
    return
