import socket
s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
print"Enter website address: "
x=raw_input()
ip1=socket.gethostbyname(x)
print "ip address of "+x 
print ip1
