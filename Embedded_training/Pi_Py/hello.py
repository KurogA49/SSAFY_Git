from gpiozero import LED
from time import sleep

leds = [LED(17), LED(27), LED(22)]
prev = leds[0]

while True:
    print("INPUT >>", end=" ")
    raw = input()
    if(raw == "exit"):
        break
    num = int(raw)
    if num < 3 :
        prev.off()
        leds[num].on()
        prev = leds[num]