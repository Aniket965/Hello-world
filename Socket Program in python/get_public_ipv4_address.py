from urllib2 import urlopen
my_ip = urlopen('http://ip.42.pl/raw').read()
print "your public ipv4 adderss is: "+my_ip
