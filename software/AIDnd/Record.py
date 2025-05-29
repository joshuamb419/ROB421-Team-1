#base code from https://realpython.com/playing-and-recording-sound-python/

import pyaudio
import wave
import Keyboard as Key
import time

def key_press(hotkey):
    if Key.is_pressed(hotkey):
        return True
    else:
        return False

def record(chunk=1024, sample_format = pyaudio.paInt16, channels=2, fs=44100, seconds=3, filename="input.wav", hotkey = 'space'):
    p = pyaudio.PyAudio()  # Create an interface to PortAudio

    stream = p.open(format=sample_format,
                    channels=channels,
                    rate=fs,
                    frames_per_buffer=chunk,
                    input=True)
    
    print(f'Press {hotkey} to begin listening')

    frames = []  # Initialize array to store frames

    # Store data in chunks
    Key.wait(hotkey)
    time.sleep(0.1)
    print(listening)
    while key_press(hotkey):
        data = stream.read(chunk)
        frames.append(data)
        
    print('Listening Stopped')
    
    # Stop and close the stream 
    stream.stop_stream()
    stream.close()

    # Terminate the PortAudio interface
    p.terminate()
    
    # Save the recorded data as a WAV file
    wf = wave.open(filename, 'wb')
    wf.setnchannels(channels)
    wf.setsampwidth(p.get_sample_size(sample_format))
    wf.setframerate(fs)
    wf.writeframes(b''.join(frames))
    wf.close()
        
