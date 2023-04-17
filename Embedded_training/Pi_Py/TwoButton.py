from gpiozero import Button
from gpiozero import LED
from time import sleep
from signal import pause

btn1 = Button(6)
btn2 = Button(5)

leds = [LED(27), LED(17), LED(24), LED(23)]

idx = 0
def go():
    global idx
    for i in range(4):
        if i % 2 == idx % 2:
            leds[i].on()
        else:
            leds[i].off()
    sleep(0.1)
    for i in range(4):
        if i % 2 == idx % 2:
            leds[i].off()
        else:
            leds[i].on()
    sleep(0.1)
    for i in range(4):
        leds[i].off()
    idx += 1


def init():
    for i in range(4):
        leds[i].on()
    sleep(0.1)
    for i in range(4):
        leds[i].off()
    sleep(0.1)

mode = 0
def changeMode():
    global mode
    if mode == 0:
        mode = 1
    else:
        mode = 0
    

btn1.when_pressed = changeMode

while True:
    if mode == 0:
        go()
    elif mode == 1:
        init()

pause()