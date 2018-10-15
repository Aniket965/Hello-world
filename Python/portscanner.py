import argparse
import socket
from socket import *

def connScan(tgtHost, tgtPort):
    try:
        connSkt = socket(AF_INET, SOCK_STREAM)
        connSkt.connect((tgtHost, tgtPort))
        connSkt.send(b'PortScanner by Jay\r\n')
        results = connSkt.recv(100)
        print('[+]%d/tcp open'% tgtPort)
        print('[+] ' + str(results))
        connSkt.close()
    except Exception as ex:
        print(ex)
        print('[-]%d/tcp closed'% tgtPort)

def portScan(tgtHost, tgtPorts):
    try:
        tgtIP = gethostbyname(tgtHost)
    except:
        print("[-]Cannot resolve '%s': Unknown host"%tgtHost)
        return
    try:
        tgtName = gethostbyaddr(tgtIP)
        print('\n[+] Scan results for : ' + tgtName[0])
    except:
        print('\n[+] Scan results for : ' + tgtIP)
    setdefaulttimeout(1)
    for tgtPort in tgtPorts:
        print('Scanning port ' + tgtPort)
        connScan(tgtHost, int(tgtPort))

def main():
    parser = argparse.ArgumentParser(description='usage -H <target host> -p <target port>')

    parser.add_argument(
        "-H",
        "--tgtHost",
        type=str,
        help="specify target host"
    )
    parser.add_argument(
        "-p",
        "--tgtPort",
        type=str,
        help="specify target port"
    )
    args = parser.parse_args()
    tgtHost = args.tgtHost
    tgtPorts = str(args.tgtPort).split(", ")
    if not tgtHost and not tgtPorts:
        print('[-]You must specify a target host and port[s].')
        exit(0)
    portScan(tgtHost, tgtPorts)

if __name__ == '__main__':
    main()
