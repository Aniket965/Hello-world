# client_process.py

# create a client socket which will connect with the server socket with ip address and port
# usage:-- python client_process.py <server-ip> <port>


import socket
import sys

if len(sys.argv) < 3:
    print 'error:--Usage python client.py <ip of server> <port>'
    sys.exit()
try:
    client_socket = socket.socket()                        # create a socket
    server_ip = (sys.argv[1])                              # server ip address to connect
    port = int(sys.argv[2])                                # port number on which socket is listening
    print port
    client_socket.connect((server_ip,port))                #connect to the server socket
    while True:
        command_to_server = raw_input("Enter the commands to the server and type 'quit' for temination:-")
        if command_to_server == 'quit':
            client_socket.close()                           # terminate the connection
            sys.exit()
        client_socket.send(command_to_server)                # send command to the server
        print client_socket.recv(1024)                       # receive the message from the server

except socket.error as error_message:
    print 'Socket Error:--', error_message

except Exception as error_message:
    print 'Error:--', error_message
