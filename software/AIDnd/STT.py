import whisper
import Record

def transcribe():
    model = whisper.load_model("tiny.en")
    Record.record()
    result = model.transcribe('input.wav')
    return result["text"]