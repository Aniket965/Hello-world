# Python example to demonstrate word count using inbuilt word count
from collections import Counter
counter = Counter()
colors = ['red', 'blue', 'red', 'green', 'blue', 'blue']
for color in colors:
  counter[color] += 1

print(counter)
