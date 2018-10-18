from tkinter import filedialog
import tkinter
import cv2
import os

root = tkinter.Tk()
root.withdraw()

currdir = os.getcwd()
tempdir = filedialog.askopenfilenames(parent=root, initialdir=currdir, title='Select the image(s)')

pathList = root.tk.splitlist(tempdir)

if len(pathList) > 1:
    tempPath = filedialog.askdirectory(parent=root, initialdir=currdir, title='Choose a destination folder')
    for i in range(len(pathList)):
        img = cv2.imread(pathList[i], 0)
        imgName = tempPath + '/image_' + str(i) + '.jpg'
        cv2.imwrite(imgName,img)

else:
    img = cv2.imread(pathList[0], 0)
    root.filename =  filedialog.asksaveasfilename(initialdir = currdir,title = "Save image",filetypes = (("jpeg","*.jpg"),("all files","*.*")))
    extention = root.filename.split('.')
    if len(extention) > 1:
        savePath = root.filename
    else:
        savePath = root.filename + '.jpg'

    cv2.imwrite(savePath, img)
