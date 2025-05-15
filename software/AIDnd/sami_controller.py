import time
import serial
import os
import json
import asyncio

# Adapted from JamieControl and JamieUI to remove UI components

class SamiControll:
    def __init__(self,
                 arduino_port='/dev/tty/USB0',
                 baud_rate=115200,
                 joint_config_file='Joint_config.json',
                 behavior_folder='behaviors',
                 emote_file='Emote.json'):
        self.arduino_port = arduino_port
        self.baud_rate = baud_rate
        self.joint_map = self.load_joint_config(joint_config_file)
        self.joint_config = json.load(open(joint_config_file, 'r'))['JointConfig']
        self.behavior_folder = behavior_folder
        self.emote_mapping = self.load_emote_mapping(emote_file)
        self.ser = None

        self.initialize_serial_connection()
    
    # Taken from JamieControl
    def load_joint_config(self, joint_config_file):
        with open(joint_config_file, 'r') as file:
            config = json.load(file)
        joint_map = {}
        for joint in config["JointConfig"]:
            joint_map[joint["JointName"]] = joint["JointID"]
        return joint_map
    
    # Taken from JamieControl
    def load_emote_mapping(self, emote_file):
        with open(emote_file, 'r') as file:
            data = json.load(file)
        return data["Emotes"]
    
    # Taken from JamieControl
    def send_joint_command(self, joint_ids, joint_angles, joint_time):
        if len(joint_ids) != len(joint_angles):
            raise ValueError("Mismatch in joint IDs and angles.")
        packet = [0x3C, 0x4A, joint_time]
        for jid, angle in zip(joint_ids, joint_angles):
            packet.extend([jid, angle])
        packet.append(0x3E)
        self.ser.write(bytearray(packet))
        print("Sent joint command:", bytearray(packet))
    
    # Taken from JamieControl
    def send_emote(self, emote_id):
        packet = [0x3C, 0x45, emote_id, 0x3E]
        self.ser.write(bytearray(packet))
        print("Sent emote command:", bytearray(packet))
        time.sleep(1)

    # Taken from JamieControl
    def initialize_serial_connection(self):
        try:
            self.ser = serial.Serial(self.arduino_port, self.baud_rate, timeout=1)
            time.sleep(2)
            print("Serial connection established.")
            packet = [0x3C, 0x50, 0x01, 0x45, 0x3E]
            self.ser.write(bytearray(packet))
            print("Sent packet:", bytearray(packet))
            if self.ser.in_waiting > 0:
                msg = self.ser.readline().decode()
                print("Arduino response:", msg)
        except serial.SerialException as e:
            print("Error connecting to Arduino:", e)
    
    # Taken from JamieControl
    def close_connection(self):
        if self.ser:
            self.ser.close()
            print("Serial connection closed.")

    # Modified from JamieUI
    def perform_behavior(self, behavior):
        behavior_path = os.path.join(self.behavior_folder, behavior)
        behavior_motion = self.load_behavior(behavior_path)
        for frame in behavior_motion:
            # Process Emote if available.
            if frame["HasEmote"] == "True":
                expression = frame.get("Expression", "Neutral")
                emote_value = self.emote_mapping.get(expression, 0)
                self.send_emote(emote_value)
            # Process Joint Commands if available.
            if frame["HasJoints"] == "True":
                joint_ids = [self.get_joint_id(j['Joint']) for j in frame['JointAngles']]
                angles = [j['Angle'] for j in frame['JointAngles']]
                move_time = frame["JointMoveTime"]
                self.send_joint_command(joint_ids, angles, move_time)
            time.sleep(frame["WaitTime"] / 1000)
    
    # Modified from JamieUI
    async def perform_behavior_async(self, behavior):
        behavior_path = os.path.join(self.behavior_folder, behavior)
        behavior_motion = self.load_behavior(behavior_path)
        for frame in behavior_motion:
            # Process Emote if available.
            if frame["HasEmote"] == "True":
                expression = frame.get("Expression", "Neutral")
                emote_value = self.emote_mapping.get(expression, 0)
                self.send_emote(emote_value)
            # Process Joint Commands if available.
            if frame["HasJoints"] == "True":
                joint_ids = [self.get_joint_id(j['Joint']) for j in frame['JointAngles']]
                angles = [j['Angle'] for j in frame['JointAngles']]
                move_time = frame["JointMoveTime"]
                self.send_joint_command(joint_ids, angles, move_time)
            asyncio.sleep(frame["WaitTime"] / 1000)

    # Taken from JamieUI
    def load_behavior(self, behavior_file):
        with open(behavior_file, 'r') as file:
            return json.load(file)['Keyframes']

    # Taken from JamieUI
    def move_to_home(self):
        joint_ids = [joint['JointID'] for joint in self.joint_config]
        home_angles = [joint['HomeAngle'] for joint in self.joint_config]
        self.send_joint_command(joint_ids, home_angles, 1)
    
    # Taken from JamieControl
    def get_joint_id(self, joint_name):
        return self.joint_map.get(joint_name, 0)
