import socket
import sys
host="localhost"
port=9000
s=socket.socket() # s is the server socket
s.bind((host,port))
s.listen(1)      # here 1 specifies the number BACKLOG...i.e no of pending requests
                    #i.e number of requests b4 the server stops making new connections 
c, addr=s.accept() # c is the client socket
                    # addr is the address of the client
# server socket s used to accept new connections ,,,,,to
#communicate with the clients usse the client sockets

print("a client just connected")
count=0
while True:
    try:
        data=c.recv(1024)
        if not data:
            if count==2:
                print('{0:>15}'.format('Due to unavailability of the client, I am signing off. Hope to see you soon'))
                c.close()
                sys.exit(0)
            else:
                count+=1
                data='[[    NO DATA RECEIVED    ]]'
                print(data)
                message='[[   EMPTY REQUEST SEND TO VERIFY IF THE CLIENT IS STILL CONNECTED   ]]'
                print(message)
                data1='[[   PLEASE VERIFY YOUR PRESENCE BY SENDING A MESSAGE    ]]'
                c.send(data1.encode())
        
        elif data.decode()=='0':
            print('{0:>15}'.format('The client just logged off. The connection is shutting down. Thank you.'))
            c.close()
            sys.exit(0)

        else:
            print(" {0:>15} {2:>3} {1:<50}".format("RECEIVED", str(data.decode()),">>>"))
            data1=input(" {0:>15} ".format("SEND <<<"))
            c.send(data1.encode())

    except KeyboardInterrupt:
        error='KEYBOARD INTERRUPT'
        print('Due to {0}, I am signing off. Hope to see you soon'.format(error))
        data1='0'
        c.send(data1.encode())
        c.close()
        sys.exit(0)

    
