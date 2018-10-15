import socket
import sys 
try:
    s=(socket.socket(socket.AF_INET,socket.SOCK_STREAM))
    print ("Sokcket successfully Created")
except socket.error as err:
    print ("Socket creation failed with errors %s")%(err)
port = 80
try:
    host_ip=socket.gethostbyname('www.google.com')
except socket.gaierror:
    print ("Error in resolving Host")
sys.exit()
s.connect((host_ip,port))
print ("The socket is successfully connected to google on port ==%s") %host_ip
