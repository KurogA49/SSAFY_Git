from gpiozero import LED
from time import sleep
from gpiozero import Button
from signal import pause

a = LED(27)
b = LED(17)
c = LED(16)
d = LED(20)
e = LED(21)
f = LED(22)
g = LED(10)
DP = LED(12)

btn = Button(6)
blink = LED(23)
lazer = LED(24)

lst = [g, f, a, b, e, d, c, DP]
nums = [[a, b, c, d, e, f], #0
       [b, c], #1
       [a, b, g, e, d], #2
       [a, b, g, c, d], #3
       [f, g, b, c], #4
       [a, f, g, c, d], #5
       [a, f, g, e, c, d], #6
       [f, a, b, c], #7 
       [a, b, c, d, e, f, g], #8
       [a, b, c, d, g, f]] #9

def lightNum(num):
    for led in nums[num]:
        led.on()

def offall():
    for led in nums[8]:
        led.off()

def catch():
    if nowNum == 7:
        print("good!")
        for i in range(30):
            blink.on()
            sleep(0.05)
            blink.off()
            sleep(0.05)

btn.when_pressed = catch

for i in range(1, 10):
    global nowNum
    nowNum = i
    print(i)
    lightNum(i)
    sleep(0.1)
    offall()

sleep(0.5)

for i in range(9, -1, -1):
    nowNum = i
    print(i)
    lightNum(i)
    sleep(0.1)
    offall()
