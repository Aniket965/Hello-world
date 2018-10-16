import sys
import time
file1 = open("./words_alpha.txt", 'r')
found = False
find = sys.argv[1]
start = time.process_time()

for line in file1:
  for word in line.split():
    if(word == find):
      found = True
      break
  if(found):
    break
end = time.process_time()
file1.close()
#print("time elapsed was", end-start)
#if found == False:
  #print(find, "was not found.")
#else:
  #print(find, "was found!")

file2 = open("./logs/pythonlog.txt", 'a')

file2.write(str(end-start) + "\n")
file2.close()
