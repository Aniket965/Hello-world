import os,sys,hashlib,md5,time,itertools

os.system("cls") # if windows
#os.system("clear") # if linux
print ""
print " ______     ______     ______     ______     __  __     ______   ______     ______     ______   " 
print "/\  ___\   /\  == \   /\  __ \   /\  ___\   /\ \/ /    /\  == \ /\  __ \   /\  ___\   /\  ___\  " 
print "\ \ \____  \ \  __<   \ \  __ \  \ \ \____  \ \  _'-.  \ \  _-/ \ \  __ \  \ \___  \  \ \___  \  "
print " \ \_____\  \ \_\ \_\  \ \_\ \_\  \ \_____\  \ \_\ \_\  \ \_\    \ \_\ \_\  \/\_____\  \/\_____\ "
print "  \/_____/   \/_/ /_/   \/_/\/_/   \/_____/   \/_/\/_/   \/_/     \/_/\/_/   \/_____/   \/_____/ "
print ""
print "		CODE : Daniel Victor Freire Feitosa | @DanielFreire00"
                                                                                                 
if len(sys.argv)>=4:
	hashtext = sys.argv[1]
	try:
		wordlist = open(sys.argv[2], "r")
	except:
		print "\nArquivo nao encontrado"
	formato = sys.argv[3]
	count=0
	try:
		print "\n[*] Script iniciado ..."
		if formato == "md5" or formato == "MD5":
			print "\n[+] Formato : MD5"
			for password in wordlist:
				md5file = md5.new(password.strip()).hexdigest()
				if hashtext == md5file:
					print "\n[+] Senha Crackeada : " + password
					count=1
					print ('\n[-] Termino do script : %s' % time.strftime('%H:%M:%S'))
			if count == 0:
				print "\n[-] Sua hash nao pode ser crackeada, tente novamente ... :("
		elif formato == "sha1" or formato == "SHA1":
			print "\n[+] Formato : SHA1"
			for password in wordlist:
				sha1file = hashlib.sha1(password.strip()).hexdigest()
				if hashtext == sha1file:
					print "\n[+] Senha Crackeada : " + password
					count=1
					print ('\n[-] Termino do script : %s' % time.strftime('%H:%M:%S'))
			if count == 0:
				print "\n[-] Sua hash nao pode ser crackeada, tente novamente ... :("
	except KeyboardInterrupt:
		print "\n[x] Saindo ..."
else:
	print "\nUso : crackpass.py hash wordlist formato"
