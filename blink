import wiringpi	                # import library WiringPi-Python
from time import sleep          # import library sleep

wiringpi.wiringPiSetup()        # Must be called before using IO function
wiringpi.pinMode(0,1)           # Set pin 0 to 1 (OUTPUT) / 0 (INPUT)

while True:                     # endless loop
  wiringpi.digitalWrite(0,1)    # Write 1 (High) / 0 (Low) to pin 0
  sleep(1)                      # delay for 1 second
  wiringpi.digitalWrite(0,0)    # Write 0 (Low) / 1 (High) to pin 0
  sleep(1)                      # delay for 1 second
