import socket
 
#create an INET, raw socket
s = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.IPPROTO_TCP)
 
# receive a packet
while True:
  print s.recvfrom(65565)
  #raw socket is capable of receiving all (of its type , like AF_INET) incoming traffic in Linux
