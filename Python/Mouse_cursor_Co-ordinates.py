# Operating system: Windows 10

import pyautogui, sys,time,os

print('Press Ctrl-C to quit.')
try:
    while True:
        x, y = pyautogui.position()
        time.sleep(1)
        x1, y1 = pyautogui.position()
        os.system('CLS')
        print(x1,y1)
        if(x==x1 and y==y1):
            pass
        else:
            os.system('CLS')
            print(x1,y1)
            
except KeyboardInterrupt:
    print('\n')
    
