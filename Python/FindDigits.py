import math
import os
import random
import re
import sys

def findDigits(n):
    count = 0
    for i in str(n):
        try:
            if n%int(i) == 0:
                count +=1
        except:
            pass
    return count
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        n = int(input())

        result = findDigits(n)

        fptr.write(str(result) + '\n')

    fptr.close()
