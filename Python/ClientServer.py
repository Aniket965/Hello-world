import tty
import termios
import socket
import select
from thread import *
import sys
import hashlib 	
 
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

if(len(sys.argv)!=2 and len(sys.argv)!=3):
	exit()

user_name_temp = sys.argv[1]

has_group=""

IP_address = "127.0.0.1"
Port = 7000
server.connect(("127.0.0.1", 7000))

init_mssg = socket.gethostbyname(socket.gethostname())

init_other_user = raw_input("To: ")

final_init_mssg=""
if(len(sys.argv)>2):
	has_group = sys.argv[2]
	final_init_mssg=init_mssg+"$$"+user_name_temp+"$$"+init_other_user+"$$"+has_group
else:
	final_init_mssg = init_mssg+"$$"+user_name_temp+"$$"+init_other_user

server.send(final_init_mssg)

def keyLogger(server):
	orig_settings = termios.tcgetattr(sys.stdin)
	line = ""
	tty.setraw(sys.stdin)
	x = ""
	ct = 1
	while x != "\r":
	    if(x==chr(27)):
		termios.tcsetattr(sys.stdin, termios.TCSANOW, orig_settings) 
		exit()
	    x=sys.stdin.read(1)[0]
	    if(ct==1):	
	  	#sys.stdout.write(x) 	
		server.send(hashlib.md5("typing").hexdigest())
		line+=x
		break
	termios.tcsetattr(sys.stdin, termios.TCSANOW, orig_settings) 
	return line

def listener():
   
     while True:
     	sockets_list = [server]
     	read_sockets,write_socket, error_socket = select.select(sockets_list,[],[])
   
     	for socks in read_sockets:
        	if socks == server:
        	    message = socks.recv(2048)
        	    print message


start_new_thread(listener,())    
 
while True:
    	
     mssg = keyLogger(server)
     print(mssg+"\r")
#     sys.stdout.write(mssg)
     while True:
     	sockets_list = [sys.stdin]
     	read_sockets,write_socket, error_socket = select.select(sockets_list,[],[])
	state = 0
   
     	for socks in read_sockets:
        	if socks == sys.stdin:
        	    message = sys.stdin.readline()
	            server.send(mssg+	message)
		    state=1	 
          	    #sys.stdout.write("YOU SAID:  ")
            	    #sys.stdout.write(message)
                    #sys.stdout.flush()
	if(state==1):
		break

#    sockets_list = [sys.stdin, server]
 
#    read_sockets,write_socket, error_socket = select.select(sockets_list,[],[])
 
#    for socks in read_sockets:
#        if socks == server:
#            message = socks.recv(2048)
#            print message
#        else:	    		
#            message = sys.stdin.readline()
#            server.send(message)
            #sys.stdout.write("YOU SAID:  ")
            #sys.stdout.write(message)
            #sys.stdout.flush()
server.close()




