import random

def PiCalculator(n):
    pts_inside = 0
    for val in range(n):
        x = random.uniform(0,1)
        y = random.uniform(0,1)
        if (x**2 + y**2 <= 1):
            pts_inside += 1
    ratio = (4*(pts_inside/(val+1)))
    return(ratio)
