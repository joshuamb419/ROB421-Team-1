import whisper
import Record

def transcribe():
    model = whisper.load_model("tiny.en")
    Record.record()
    result = model.transcribe('input.wav')['text']
    print(f"Transcribed: {result}")
    return result

# print(transcribe())