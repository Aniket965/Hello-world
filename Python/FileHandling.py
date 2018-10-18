#First we will use open function to open a file and it returns a file object. 
#File objects contain methods and attribute to collect information of the file opened.Also the mode of the file should also be defined during opening.
#There are four modes - r,w,a,r+.

#file_object = open("filename", mode)
#print(f) #<_io.TextIOWrapper name='testfile.txt' mode='w' encoding='cp1252'>


#For Writing in file
f = open("testfile.txt", "w")
f.write("Hello World.\n")               	#For Writing in the file.
f.write("This is our new text file.\n")
lines_of_text = ["sup ", "buoy.\n"]
f.writelines(lines_of_text)					#takes a list or a single element as parameter.
f.close()


#Reading a text file
f = open("testfile.txt", "r")
print(f.read())								#For reading the file object.
print(f.read(5))						
print(f.readline()) 						#return the first line of the file.
print(f.readlines())						#returns the array of lines, with each element being a line.
f.close()


#To Append a file
f = open("testfile.txt", "a")
f.write("We meet again")
f.close()


###Usage of WITH statement is important. It handles exceptions and it closes the file automatically.###

with open("testfile.txt") as f:
	f.read()
#similarly rest operations can be performed




#For spliting the lines
with open("testfile.txt") as f:
	data = f.readline()

	for line in data:
		words = line.split()
		print(words)

