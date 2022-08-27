import serial
import time
import keyboard

# arduino = serial.Serial('/dev/ttyACM0', 9600) #Serial USB port on Linux
# arduino = serial.Serial('/dev/rfcomm0', 57600) #Bluetooth on Linux

arduino = serial.Serial('COM3', 57600) #Bluetooth on Windows
# arduino = serial.Serial('COM22', 9600) #Serial USB port on Windows

manualEnabled = False
time.sleep(1)
print('arduino connected')
print(arduino.name)


def sendKey(key):
    arduino.write(key) #Need to encode string to bytes

while True:
    #ASCII = 119
    if keyboard.read_key() == 'w':
        print("Forward")
        sendKey(b'w')
    #ASCII = 97
    elif keyboard.read_key() == 'a':
        print("Left")
        sendKey(b'a')
    #ASCII = 115
    elif keyboard.read_key() == 's':
        print("Backwards")
        sendKey(b's')
    #ASCII = 100
    elif keyboard.read_key() == 'd':
        print("Right")
        sendKey(b'd')
    elif keyboard.read_key() == 'x':
        print("Stop")
        sendKey(b'x')
    elif keyboard.read_key() == 'q':
        print("Manual ON")
        sendKey(b'y')
        sendKey(b'x')
    elif keyboard.read_key() == 'e':
        print("Manual OFF")
        sendKey(b'n')
    time.sleep(0.01)

    # if keyboard.is_pressed("q"):
    #     print("You pressed q")

        