from gpiozero import Button
from gpiozero import LED
from signal import pause

flag = 0

def go():
    global flag
    if flag == 0:
        flag = 1
        print("YO")
    else:
        flag = 0
        print("CHECK")

def prsd():
    print("PRESSED")

def rlsd():
    print("RELEASED")

button = Button(27)
button.when_pressed = prsd
button.when_released = rlsd

pause()