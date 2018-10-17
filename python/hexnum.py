#!/usr/bin/python
# -*- coding: utf-8 -*-

# Coded by Firman Fathoni
# hex404@programmer.net
import sys
import requests
import json
import time
import urllib
import os

class color:
   PURPLE = '\033[95m'
   CYAN = '\033[96m'
   DARKCYAN = '\033[36m'
   BLUE = '\033[94m'
   GREEN = '\033[92m'
   YELLOW = '\033[93m'
   RED = '\033[91m'
   BOLD = '\033[1m'
   UNDERLINE = '\033[4m'
   END = '\033[0m'
   HEADER = '\033[95m'
   OKBLUE = '\033[94m'
   OKGREEN = '\033[92m'
   WARNING = '\033[93m'
   FAIL = '\033[91m'

class config:
	key = "f7c485850db7755a80879c0914903a3f" #go to https://numverify.com/

def banner():
	os.system('clear')
	print color.YELLOW + "[+] " + color.BOLD + "Phone Number Information Gathering" + color.YELLOW + "[+] "
	print  color.YELLOW + """
██╗  ██╗███████╗██╗  ██╗███╗   ██╗██╗   ██╗███╗   ███╗
██║  ██║██╔════╝╚██╗██╔╝████╗  ██║██║   ██║████╗ ████║
███████║█████╗   ╚███╔╝ ██╔██╗ ██║██║   ██║██╔████╔██║
██╔══██║██╔══╝   ██╔██╗ ██║╚██╗██║██║   ██║██║╚██╔╝██║
██║  ██║███████╗██╔╝ ██╗██║ ╚████║╚██████╔╝██║ ╚═╝ ██║
╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝     ╚═╝                
	""" + color.END
	print  color.BLUE + """
┌═══════════════════════════════════════════════════════════════┐
█    Author   	: Firman Fathoni (./HEX404)			█
█    Github   	: https://github.com/HEX404			█
█    Email	: hex404@programmer.net				█
█		  hex404.ggwp@gmail.com				█
█		  firmanfathoni123@gmail.com			█
█    Pastebin	: https://pastebin.com/u/hex404			█
█    Codepen	: https://codepen.io/FirmanFathoni		█
█    Website	: https://hex404.zone.id			█
█    Facebook 	: https://web.facebook.com/firman.fathoni.37	█
█    Instagram	: https://instagram.com/firmanfathoni_		█
█    WhatsApp 	: +1 (234) 251-3998				█
█    Team     	: Banyumas Cyber Team				█         
█    Version  	: dev-1.0					█
└═══════════════════════════════════════════════════════════════┘                      
	""" + color.END

def main():
	banner()
	if len(sys.argv) == 2:
		number = sys.argv[1]
		api = "http://apilayer.net/api/validate?access_key=" + config.key + "&number=" + number + "&country_code=&format=1"
		output = requests.get(api)
		content = output.text
		obj = json.loads(content)
		country_code = obj['country_code']
		country_name = obj['country_name']
		location = obj['location']
		carrier = obj['carrier']
		line_type = obj['line_type']

		print color.YELLOW + "[+] " + color.END + "Phone Number Information Gathering"
		print "--------------------------------------"
		time.sleep(0.2)

		if country_code == "":
			print " - Getting Country		[ " + color.RED + "FAILED " + color.END + "]"
		else:
			print " - Getting Country		[ " + color.GREEN + "OK " + color.END + "]"

		time.sleep(0.2)
		if country_name == "":
			print " - Getting Country Name		[ " + color.RED + "FAILED " + color.END + "]"
		else:
			print " - Getting Country Name		[ " + color.GREEN + "OK " + color.END + "]"

		time.sleep(0.2)
		if location == "":
			print " - Getting Location		[ " + color.RED + "FAILED " + color.END + "]"
		else:
			print " - Getting Location		[ " + color.GREEN + "OK " + color.END + "]"

		time.sleep(0.2)
		if carrier == "":
			print " - Getting Carrier		[ " + color.RED + "FAILED " + color.END + "]"
		else:
			print " - Getting Carrier		[ " + color.GREEN + "OK " + color.END + "]"

		time.sleep(0.2)
		if line_type == None:
			print " - Getting Device		[ " + color.RED + "FAILED " + color.END + "]"
		else:
			print " - Getting Device		[ " + color.GREEN + "OK " + color.END + "]"

		print ""
		print color.YELLOW + "[+] " + color.END + "Information Output"
		print "--------------------------------------"
		print " - Phone number: " + str(number)
		print " - Country: " + str(country_code)
		print " - Country Name: " + str(country_name)
		print " - Location: " + str(location)
		print " - Carrier: " + str(carrier)
		print " - Device: " + str(line_type)
	else:
		print color.WARNING + "[?] Usage:"
		print "	./%s <phone-number>" % (sys.argv[0])
		print color.WARNING + "[?] Example:"
		print "	./%s +12342513998" % (sys.argv[0])
		print "	./%s +6281327252***" % (sys.argv[0])
		print color.DARKCYAN + "[*] Nb : You can use (+) before the number or not"

main()
