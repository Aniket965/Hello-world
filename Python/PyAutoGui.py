import pyautogui
from random import randint
from time import sleep

pyautogui.position()  # POSITION IN IDLE
count = 0
while True:
    x = 203
    y = 360
    sleep(0.01)
    count += 1
    pyautogui.click(x, y)  # Ctrl + f2 KILL PROCESS
    #if count % 300 == 0:
     #   sleep(5)
