import ollama

MODEL = "gemma3:1b"
PROMPT = "You are a dungeon master in charge of running a dnd session. You are running a short session where the players raid a bandit camp. Be sure to ask the players what they would like to do, never assume an action that they take. The players are here and ready to start the session, please begin by narrating the opening scene and asking the players what they want to do. Additionally you may express and gesture by placing emotes from the following list in square brackets like this. `[surprise]` You may only choose from this list: concert, double_wave, vibe, wave, surprise"

with open("ollama_credentials", 'r') as file:
    credentials = file.readline()

client = ollama.Client(
    host = "https://ollama.snakej.org",
    headers = {'Authorization': f'Basic {credentials}'}
)

messages = []
messages.append({'role': 'user', 'content':PROMPT})

print("Generating First Message...\n\n")
response = client.chat(model=MODEL, messages=messages).message.content
messages.append({'role': 'assistant', 'content':response})
print(response)

while True:
    user_input = input("\n\nEnter Your Response: ")
    messages.append({'role': 'user', 'content':user_input})
    print("Generating AI reponse...\n\n")
    response = client.chat(model=MODEL, messages=messages).message.content
    messages.append({'role': 'assistant', 'content':response})
    print(response)
