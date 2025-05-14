import whisper

audio = 'response.mp3'

model = whisper.load_model("tiny.en")
result = model.transcribe(audio)
text = result["text"]

print(text)