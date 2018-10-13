# server_process.py

# create a socket connect with which many client can connect and ask for the query.
# usage:-- python server_process.py  <port>


import socket,select
import sys

if len(sys.argv) < 2:
    print 'Error:--Usage python server.py <port>'
    sys.exit()

# start the connection
try:
    port = int(sys.argv[1])
    server_socket = socket.socket(socket.AF_INET,socket.SOCK_STREAM) # create an AF_INET(Ipv4), STREAM socket (TCP)
    server_socket.bind(('',port))                                    #bind the socket to the port
    server_socket.listen(5)                                          # now wait for client connection
    connection_list = []                                             # list of available connection including server socket
    connection_list.append(server_socket) 
    print 'Server Listening'
    commands = {                                                     # commands to respond to the client
    'PING': 'PING_OK',
     'LIST': 'LIST_OK',
      'HELLO':'WORLD',
      'QUIT':'QUIT_ERR'
    }

    while True:

       # get the list of socket which are ready to read from the socket
        read_sockets,write_sockets,error_sockets = select.select(connection_list,[],[])
        for sock in read_sockets:
            if sock == server_socket:                            # if server socket is expecting new client socket
                conn,addr = server_socket.accept()
                connection_list.append(conn)
                print 'Got connection from:--%s and port is %s'%(addr,port)     # print ip address of client socket
            else:
      # when there is any message from the clients
                try:
                    command_from_client =  sock.recv(1024)
                    if commands.get(command_from_client):
                        send_to_client = commands[command_from_client]                  #search for response message for client
                        print 'Response send to client is:--',send_to_client
                        sock.send(send_to_client)                                       # send message to client
                    else:
                        sock.send('UNKNOWN_CMD')
                except socket.error as e:
                    sock.close()                                                       # close the connection if client disconnect
                    connection_list.remove(sock)
                    num_of_connection = len(connection_list)
                    if num_of_connection == 1:                                        # close the server socket if all client disconnected
                        print 'Server is closing'
                        server_socket.close()
                        sys.exit()
                    print ' Client disconnect,'
                except Exception as error_message:
                    print 'Error:--', error_message

except socket.error as error_message:
    print 'Error creating socket,',error_message
except Exception as error_message:
    print 'Error:--',error_message
