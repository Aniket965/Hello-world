import textwrap
import pyperclip
from threading import Thread
from tkinter import Tk, Label, Button, Frame
from time import sleep

import db


def copy_from_history(text):
    print("Copy", text)
    pyperclip.copy(text)


def delete_all():
    db.delete_all()


def set_pastes():
    pastes = list(db.get_pastes())

    for index, element in enumerate(paste_elements):
        # To few pastes available
        if index >= len(pastes):
            element["text"].config(text="")
            element["date"].config(text="")
            element["button"].config(text="")
            element["button"].bind("<Button-1>", lambda x: None)
            element["button"].lower()
            continue

        element["text"].config(text=textwrap.shorten(pastes[index].text, width=50, placeholder="..."))
        element["date"].config(text=pastes[index].date.strftime("%d. %B %Y %H:%M:%S"))
        element["button"].config(text="Copy")
        element["button"].bind("<Button-1>", lambda x: copy_from_history(pastes[index].text))


def update(event=None):
    while do_run:
        print("Update")
        set_pastes()
        sleep(0.5)


def stop():
    global do_run
    do_run = False
    root.destroy()


do_run = True

root = Tk()
root.minsize(750, 500)
root.title("Clipboard")

update_button = Button(root, text="Update", command=update)

pastes_heading = Label(root, text="Pastes", font=(None, 15))
pastes_heading.pack()

pastes_frame = Frame(root, borderwidth=2, height=5000)

paste_elements = [
    {
        "text": Label(pastes_frame, text=""),
        "date": Label(pastes_frame, text=""),
        "button": Button(pastes_frame, text="Copy"),
    }
    for i in range(10)
]

for index, element in enumerate(paste_elements):
    element["text"].grid(row=index, column=0, columnspan=2)
    pastes_frame.pack()
    element["date"].grid(row=index, column=2)
    pastes_frame.pack()
    element["button"].grid(row=index, column=3)
    pastes_frame.pack()

delete_button = Button(root, text="Delete all pastes", command=delete_all)
delete_button.pack()

thread = Thread(target=update)
thread.start()

root.protocol("WM_DELETE_WINDOW", stop)
root.mainloop()
