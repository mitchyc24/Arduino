import serial
import time
import argparse

# Configure the serial connection (adjust the port as necessary)
ser = serial.Serial('/dev/ttyUSB0', 9600)


def send_command(command):
    ser.write((command + '\n').encode())
    time.sleep(0.1)  # Small delay to ensure the command is processed

def main():
    try:
        while True:
            text = input("Enter text: ")
            send_command(text)

    finally:
        ser.close()

if __name__ == "__main__":
    main()
