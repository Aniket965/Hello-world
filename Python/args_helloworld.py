#!/usr/bin/python

import sys
from datetime import datetime

dt_ini = datetime.now()
hello = None

if len(sys.argv) > 1:
    arg = sys.argv[1]
    if arg in ("-hello", "--hello", "-hi", "--hi"):
        hello = True
    elif arg in ("-bye", "--bye", "-goodbye", "--goodbye", "-b", "-gb"):
        hello = False

if hello is True:
    s = "Hello"
elif hello is False:
    s = "Bye"
else:
    s = "Hey"

print(s, "world!")
dt_end = datetime.now()
dt_diff = dt_end - dt_ini
print("Execution time:", dt_diff.seconds)

