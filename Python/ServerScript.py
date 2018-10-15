import socket
import select
import sys
from thread import *
import hashlib
 
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
 
server.bind(("127.0.0.1", 7000))

server.listen(3)
 
clientMap = {}
groupMap = {}


userIP = ""
userName = ""
userTarget = ""
 
def clientthread(conn, addr,init_mssg):
 

    conn.send("Diprivi Welcomes you!\r")

    init_list = init_mssg.split("$$")

    userIP = init_list[0]
    userName = init_list[1]
    userTarget = init_list[2]

    if(len(init_list)==3):
    	clientMap[userName] = conn

    elif(len(init_list)==4):
	groupName = init_list[3]
	if groupName in groupMap :
		groupMap[groupName].append(conn)
	else:
		groupMap[groupName]=[]
		groupMap[groupName].append(conn)
 
    while True:
            try:
                message = conn.recv(2048)
                if message!="":
 		    if(message==(hashlib.md5("typing").hexdigest())):
			print addr[0] + ">> " +"typing...."
			message_to_send = addr[0] + ">> " +"typing....\r"
			if(len(init_list)==4):
				send_all(message_to_send,conn,groupName,0)
			else:
		                kaala(message_to_send, conn,userTarget)
		    else:	
	                    print addr[0] + ">> " + message
 
        	            message_to_send =  addr[0] + ">> " + message +"\r"
			
			    if(len(init_list)==4):
				send_all(message_to_send,conn,groupName,1)
			    else:
		                kaala(message_to_send, conn,userTarget)
 
                else:
                    remove(conn,userTarget)
 
            except:
                continue
 
def kaala(message, connection,target):
    
    client = clientMap[target]
    try:
       	client.send(message)
    except:
        client.close()
 
        remove(clients,target)
 
def remove(connection,target):
    if connection in list_of_clients:
        del clientMap[target]

def send_all(message,conn,groupName,option):
     target_ips = groupMap[groupName]
     print(option)
     for ips in target_ips:
	if(option==0):
		if(ips!=conn):
			try:
				ips.send(message)
        		except:
                		ips.close()
	elif(option==1):
		try:
			ips.send(message)
        	except:
               		ips.close()
 
                	remove_from_group(ips,target_ips)

def remove_from_group(connection,group):
    if connection in group:
        group.remove(connection)
 
while True:
 
    conn, addr = server.accept()
 
    print addr[0] + " connected"

    init_mssg = conn.recv(1024)
 
    start_new_thread(clientthread,(conn,addr,init_mssg))    
 
conn.close()
server.close()
