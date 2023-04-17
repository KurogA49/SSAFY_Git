from gpiozero import Button
from gpiozero import LED
from time import sleep
from signal import pause

btn1 = Button(6)
lazer = LED(27)

mode = 0
def lazer_on():
    global mode
    if mode == 0:
        mode = 1
        lazer.on()
    else:
        mode = 0
        lazer.off()

btn1.when_pressed = lazer_on

pause()