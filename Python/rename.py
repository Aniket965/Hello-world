'''
Author : Vidyadhar Sharma // @justvidyadhar // justvidyadhar@gmail.com

Scripts takes in a source and destination path and moves files from Source A to Dest B with new names. 

When Source and Destination are same, the script just renames the files in numeric order. 

Useful for sorting large sets of images.

'''

import os
from sys import argv

script_name, src_path , save_path = argv

for i, image in enumerate(os.listdir(src_path)):
    if image.endswith('.jpg') | image.endswith('.jpeg'):
        print("Renaming {} to {}.jpg".format(image,i))
        os.rename(path + image, save_path + str(i) + ".jpg")

print("Done.")
