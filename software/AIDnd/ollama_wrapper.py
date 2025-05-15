import ollama

class OllamaWrapper:
    # PROMPT = "You are a dungeon master in charge of running a dnd session. You are running a short session where the players raid a bandit camp. Be sure to ask the players what they would like to do, never assume an action that they take. The players are here and ready to start the session, please begin by narrating the opening scene and asking the players what they want to do. Additionally you may express and gesture by placing emotes from the following list in square brackets like this. `[surprise]` You may only choose from this list: concert, double_wave, vibe, wave, surprise"

    def __init__(self, model="gemma3:1b", host="https://ollama.snakej.org", credentials=None):
        self.model = model
        self.host = host

        self.messages = []

        if credentials is not None:
            self.client = ollama.Client(
                host = self.host,
                headers = {'Authorization': f'Basic {credentials}'}
            )
        else:
            self.client = ollama.Client(
                host = self.host
            )

    # Returns response to 'msg'
    # This function takes into account and updates the message history
    def chat(self, msg):
        self.messages.append({'role': 'user', 'content':msg})

        response = self.client.chat(model=self.model).message

        self.messages.append(response)

        return response.content
    
    # Returns the message history
    def getMessageHistory(self):
        return self.messages
    
    # Sets the message history
    def setMessageHistory(self, history):
        self.messages = history
    
    # Resets the message history
    def reset(self):
        self.messages = []
