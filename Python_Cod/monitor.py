import serial
import time


ser = serial.Serial('COM3', 9600, timeout=1)
time.sleep(2)

print("Înregistrare date pornită...")

try:
    while True:
        if ser.in_waiting > 0:
            linia = ser.readline().decode('utf-8').rstrip()
            print(f"Date primite: {linia}")

            with open("consum_energie.txt", "a") as f:
                f.write(f"{time.strftime('%Y-%m-%d %H:%M:%S')} - {linia}\n")
except KeyboardInterrupt:
    print("Oprire monitorizare.")
    ser.close()
