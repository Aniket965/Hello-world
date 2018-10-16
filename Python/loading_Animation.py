import time
import sys
import os

animation = "|/-\\"

for i in range(100):
    time.sleep(0.1)
    sys.stdout.write("\rLoading..............." + animation[i % len(animation)])
    sys.stdout.flush()

print "\n"
print ""

