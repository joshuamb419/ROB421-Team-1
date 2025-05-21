from gtts import gTTS
import playsound
import sounddevice as sd
import soundfile as sf

def speak(text):
    tts = gTTS(text)
    tts.save('response.wav')

    data, fs = sf.read('response.wav', dtype='float32')  
    sd.play(data, fs)
    status = sd.wait()
    return

async def speak_async(text):
    # tts = gTTS(text)
    # tts.save('response.wav')

    # playsound.playsound('response.wav')
    speak(text)
    return
