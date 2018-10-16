file1 = open("./logs/pythonlog.txt", 'r+')
avg1 = 0.0
lines1 = 0.0
for line in file1:
    lines1 = lines1 + 1.0
    avg1 = (avg1 + float(line))
avg1 = avg1/lines1
print(avg1, "for Python with", lines1, "lines")


file2 = open("./logs/clog.txt", 'r+')
avg2 = 0.0
lines2 = 0.0
for line in file2:
    lines2 = lines2 + 1.0
    avg2 = (avg2 + float(line))
avg2 = avg2/lines2
print(avg2, "for C with", lines2, "lines")


file3 = open("./logs/cpplog.txt", 'r+')
avg3 = 0.0
lines3 = 0.0
for line in file3:
    lines3 = lines3 + 1.0
    avg3 = (avg3 + float(line))
avg3 = avg3/lines3
print(avg3, "for C++ with", lines3, "lines")


file4 = open("./logs/javalog.txt", 'r+')
avg4 = 0.0
lines4 = 0.0
for line in file4:
    lines4 = lines4 + 1.0
    avg4 = (avg4 + float(line))
avg4 = avg4/lines4
print(avg4, "for Java with", lines4, "lines")

word = ""
while(word.lower() != "y" and word.lower() != "n"):
    word = input("Do you want to wipe the previous log? [Y/N]")
    if(word.lower() == "y"):
        file1.truncate(0)
        file3.truncate(0)
        file2.truncate(0)
        file4.truncate(0)
print("Done.")

file4.close()
file3.close()
file2.close()
file1.close()
