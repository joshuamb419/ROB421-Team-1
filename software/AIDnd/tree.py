class DnDCharacterWizard:
    def __init__(self):
        self.characters = []
        self.num_players = 0

    def run(self):
        self.ask_num_players()
        for player in range(1, self.num_players + 1):
            print(f"\n--- Player {player} ---")
            char_class = self.ask_class()
            race = self.ask_race()
            self.characters.append({
                "Player": player,
                "Class": char_class,
                "Race": race
            })
        self.show_summary()

    def ask_num_players(self):
        while True:
            try:
                num = int(input("Q1: How many players are creating characters? (e.g., 1, 2, 3): "))
                if num < 1:
                    raise ValueError
                self.num_players = num
                break
            except ValueError:
                print("❌ Please enter a valid number (1 or more).")

    def ask_class(self):
        while True:
            char_class = input("Q2: What class? (e.g., Fighter, Wizard, Rogue): ").strip().capitalize()
            if char_class:
                return char_class
            else:
                print("❌ Please enter a class.")

    def ask_race(self):
        while True:
            race = input("Q3: What race? (e.g., Elf, Human, Dwarf): ").strip().capitalize()
            if race:
                return race
            else:
                print("❌ Please enter a race.")

    def show_summary(self):
        print("\n✅ Character Creation Complete!")
        print("Here are your characters:")
        for char in self.characters:
            print(f"Player {char['Player']}: {char['Race']} {char['Class']}")

if __name__ == "__main__":
    wizard = DnDCharacterWizard()
    wizard.run()
