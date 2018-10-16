import os
import csv
import io

# os.walk returns three tuples- dirpath, dirname, filenames.
# We can use them and get the list of the files and folders of the current directory.
 
filenames = []

for root, dirs, files in os.walk(".",topdown = False):
	for name in files:
		print(os.path.join(root,name))

		filenames.append(name)

	for name in dirs:
		print(os.path.join(root,name))


# For writing in a csv the name of the files in the directory
with io.open("details.csv", "w", encoding="utf-8") as csvfile:

	csvwriter = csv.writer(csvfile, delimiter = "\n")
	csvwriter.writerow(filenames)
	print("")
	print("Csv Created.")