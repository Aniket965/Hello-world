import socket
import sys
host="localhost"
port=9000
s=socket.socket()
s.connect((host,port))

while True:
    try:   
        str=input(" {0:>15} {1:<3} ".format("SEND","<<<"))
        if str =='exit':
            print('{0:^50}'.format('Thank you for connecting to the server.'))
            str='0'
            s.send(str.encode())
            s.close()
            sys.exit(0)
        else:
            s.send(str.encode())

        data=s.recv(1024)
        data=data.decode()
        if data=='0':
            print('{0:^50}'.format('The server just logged off. The connection is shutting down. Thank you.'))
            s.close()
            sys.exit(0)
        else:
            print(" {0:>15} {2:>3} {1:<50}".format('RECEIVED',data,'>>>'))

    except KeyboardInterrupt:
        error='KEYBOARD INTERRUPT'
        print('Due to {0:5}, The connection is shutting down. Hope to see you soon'.format(error))
        str='0'
        s.send(str.encode())
        s.close()
        sys.exit(0)

s.close()


