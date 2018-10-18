'''In this code you can find out address on google maps only by copying text and running the script'''
import webbrowser,sys,pyperclip

sys.argv
if len(sys.argv)>1:
    address=' '.join(sys.argv[1:])
else:
    address=pyperclip.paste()

webbrowser.open("https://www.google.co.in/maps/place/"+ address)
