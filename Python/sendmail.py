import smtplib
from email.mime.text import MIMEText

body="""this is the sample mail i am sending through a python program"""
sender="============sender email================="
receiver="===========receiver email==============="

msg=MIMEText(body)
msg["From"]=sender
msg["To"]=receiver
msg["Subject"]="test mail"

ss=smtplib.SMTP("smtp.gmail.com",587)
ss.starttls()
ss.login("=========sender email==========","==========password=============")

ss.send_message(msg)
print("mail sent")
ss.quit()