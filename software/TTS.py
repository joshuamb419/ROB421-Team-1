from gtts import gTTS
from playsound import playsound
text = "this is a test"

def speak(text):
    tts = gTTS(text)
    tts.save('response.mp3')
    return

speak(text)