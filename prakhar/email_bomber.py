import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.base import MIMEBase
from email import encoders

email_user='your email address'
email_send='enter the target email address'
subject='python!'

text_amount=50

msg=MIMEMultipart()
msg['from']=email_user
msg['to']=email_send
msg['subject']=subject

body="hi , your mail id is hacked"
msg.attach(MIMEText(body,'plain'))

filename='document.txt'
attachment=open(filename,'rb')

part=MIMEBase('application','octet-stream') #for encription
part.set_payload((attachment).read())
encoders.encode_base64(part)
part.add_header('Content-Disposition',"attachment; filename= "+filename)
msg.attach(part)
text=msg.as_string()

server=smtplib.SMTP('smtp.gmail.com',587)
server.starttls()
server.login(email_user,'your mail-id password')
for _ in range(0,text_amount)
server.sendmail(email_user,email_send,text)
print("send")
time.sleep(2)
print('{} text were not sent,hope you enjoy the script'.format(text_amount)
server.quit()
