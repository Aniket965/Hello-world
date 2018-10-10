import socket
from time import sleep

class BroadcastServer():
    def __init__(self):
        self.server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.server.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        self.server.bind(("", 37404))

        while True:
            data, addr = self.server.recvfrom(1024)
            print('%s => %s' % (addr, data))
    

class BroadcastClient():
    def __init__(self):
        self.client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
        self.client.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
        self.client.settimeout(0.2)
        self.client.bind(('', 47404))

        while True:
            self.client.sendto(b'das ist ein test',('<broadcast>', 37404))
            print('message sent!')
            sleep(4)
            
def main():
    #server = BroadcastServer()
    client = BroadcastClient()
    
if __name__ == '__main__':
    main()
