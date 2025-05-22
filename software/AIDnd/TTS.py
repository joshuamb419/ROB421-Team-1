from gtts import gTTS
import playsound
import asyncio
import sounddevice as sd
import soundfile as sf

def speak(text):
    tts = gTTS(text)
    tts.save('response.wav')

    data, fs = sf.read('response.wav', dtype='float32')
    sd.play(data, fs)
    sd.wait()
    return

async def speak_async(text):
    tts = gTTS(text)
    tts.save('response.wav')

    data, fs = sf.read('response.wav', dtype='float32')
    time = len(data) / fs
    # print(f'Samples: {len(data)}, Sampling Frequency: {fs}, {time}')
    sd.play(data, fs)
    await asyncio.sleep(time)
    return
