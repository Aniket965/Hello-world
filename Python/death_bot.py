# -*- coding: utf-8 -*-
"""
Created on Sun Jul 29 12:13:53 2018

@author: Ishaan
"""

import tkinter
from tkinter.filedialog import askopenfilename
from tkinter import messagebox

def Browse():
    tkinter.messagebox.showinfo("","It's where you die")
def kill():
    tkinter.messagebox.showinfo("I warned you","Now I will kill you")

root=tkinter.Tk()
root.title("First Program")
label=tkinter.Label(root,text="This is my first app")
label.pack()
button=tkinter.Button(root,text="Don't click me",command=kill)
b1=tkinter.Button(root,text='Click Me',command=Browse)
b1.pack()
button.pack()
root.mainloop()
