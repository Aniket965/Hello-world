import pyperclip
from time import sleep

import db


def main():
    text = db.get_lastest_paste()

    while True:
        if text == pyperclip.paste():
            sleep(1)
            continue

        text = pyperclip.paste()
        print("Detected new text", text)
        db.save_new_paste(text)
        sleep(0.5)


if __name__ == "__main__":
    main()
