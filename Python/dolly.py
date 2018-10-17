#
# dolly.py
#
# PS.: This code must be runned on the terminal ;)
#

import os
import time
import platform

N = 50
grass = ""
osSystem = platform.system()

for i in range(N) : grass += "\""

def clear(osSystem):
    if osSystem == "Windows":
        os.system("cls")
    else:
        os.system("clear")
    

def printGrass():
    print(grass)
    
while True:
    clear(osSystem)

    print("\n\n\n")
    print("                 __  _")
    print("             .-.'  `; `-._  __  _")
    print("            (_,         .-:'  `; `-._")
    print("          ,'o\"(        (_,           )")
    print("         (__,-'      ,'o\"(            )>")
    print("            (       (__,-'            )")
    print("             `-'._.--._(             )")
    print("                ///  ///`-'._.--._.-'")
    print("                           ///  ///")
    printGrass()

    time.sleep(1)

    clear(osSystem)

    print("              __  _")
    print("          .-.'  `; `-._  __  _")
    print("         (_,         .-:'  `; `-._")
    print("       ,'o\"(        (_,           )")
    print("      (__,-'      ,'o\"(            )>")
    print("         (       (__,-'            )")
    print("          `-'._.--._(             )")
    print("             |||  |||`-'._.--._.-\'")
    print("                        |||  |||")
    print("\n\n\n");
    printGrass()

    time.sleep(1)

    clear(osSystem)

    print("\n\n\n")
    print("           __  _")
    print("       .-.'  `; `-._  __  _")
    print("      (_,         .-:'  `; `-._")
    print("    ,'o\"(        (_,           )")
    print("   (__,-'      ,'o\"(            )>")
    print("      (       (__,-'            )")
    print("       `-'._.--._(             )")
    print("          \\\\\\  \\\\\\`-\'._.--._.-\'")
    print("                     \\\\\\    \\\\\\ ")
    printGrass()

    time.sleep(1)

