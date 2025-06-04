import random
import time
import asyncio

from sami_controller import SamiControll

def face_roll(robot: SamiControll, rolls: int = 10, roll_range=(1, 20)):
    roll = 0
    for i in range(rolls):
        roll = random.randint(roll_range[0], roll_range[1])
        robot.send_emote(robot.emote_mapping.get(f"D_{str(roll)}", 0))
        time.sleep(0.2)

    for i in range(2):
        robot.send_emote(0)
        time.sleep(0.2)
        robot.send_emote(robot.emote_mapping.get(f"D_{str(roll)}", 0))
        time.sleep(0.2)

    return roll

if __name__ == "__main__":
    robot = SamiControll(arduino_port='/dev/ttyUSB0')
    print(face_roll(robot))