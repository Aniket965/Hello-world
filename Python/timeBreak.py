import time
import webbrowser
from random import randint

videos=["https://www.youtube.com/watch?v=qwIH7p9oJVM&list=RDqwIH7p9oJVM&start_radio=1","https://www.youtube.com/watch?v=nZhLM-FeV9A&list=RDqwIH7p9oJVM&index=2","https://www.youtube.com/watch?v=BJWTzYPWINw&index=6&list=RDqwIH7p9oJVM","https://www.youtube.com/watch?v=rkWJyMhIWLo&index=10&list=RDqwIH7p9oJVM","https://www.youtube.com/watch?v=cE94ppRCxdc&start_radio=1&list=RDcE94ppRCxdc","https://www.youtube.com/watch?v=cE94ppRCxdc&list=RDcE94ppRCxdc&index=1"]

print("This script keeps running and entertains you with random videos over YouTube to decrease your workload")

while True:
    time.sleep(20)
    v=randint(0,len(videos)-1)
    webbrowser.open(videos[v])
