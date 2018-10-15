#searches google with keywords from terminal
#!/usr/bin/env python
# Still under construction feel free to edit

import sys
from optparse import OptionParser
parser = OptionParser(
	version=" %prog V0.1 Ben Holroyd",   
	description = "%prog - google results in the terminal.",
	usage = "%prog [-vr] [--view] [--results][--help] [--version]")
parser.add_option("-r","--results",action="store",type = "int",dest="results",help="display specified number of results, default is 10." )
parser.add_option("-v","--view",action="store",type = "int",dest="view",help="view page by index number." )    
(options,args) = parser.parse_args()
    
if options.view != None: #opens selected entry in browser, then exit
	file = open("/tmp/google",'r')
	text = file.readlines()	
	counter = 1
	for lines in text:
		if counter == options.view: 
			from subprocess import call
			call("w3m %s" % lines, shell = True)
			sys.exit(0)
		counter += 1
    		
    		    
print ("loading...")
option = ""
for arg in args: option += arg+"+"
if len(option) == 0: parser.error("please enter a search term")

from urllib import FancyURLopener
class MyOpener(FancyURLopener): version = '' #google doesn't like the user agent so send blank it blank
try:   
	s = MyOpener().open('http://www.google.com/search?q=%s'% option).read()
except IOError:
	print ('could not connect to google, check your connection')
import re
dict = {}
entry = re.split('<li class=g><h3 class=r>',s) #split page by results
entry = entry[1:]                              #get rid of first bit
counter = 1
for s in entry:
	s = s.replace(''',''')                 #hack hack hack
	s = s.replace('&amp;',"&")
	s = s.replace('&middot;',"\302\267")
	s = s.replace('&quot;','"')
	s = s.replace('&lt;','<')
	s = s.replace('&gt;','>')
	s = s.replace('本','\346\234\254')
	s = s.replace('日','\346\227\245')
	s = s.replace('&nbsp;',' ')

    	
	entry = re.split('<br>',s)# gets rid of last bits #cached and similar pages  etc
	s=entry[0]
    	
	a = s.find("<a href")     #get web address
	b = s.find("</a>")
	address = s[a:b]
	title = s[a:b]            # get title
	a = address.find('"')
	address = address[a+1:]
	b = address.find('"')
	address = address[:b]
    
	b = s.find("</a>")
	s = s[b:]                  #clean up main description string 
    
	s = re.sub('<.*?>','',s)
	title = re.sub('<.*?>','',title)    	                        
    	
	print ("\033[34;04m[%d] %s\033[00;00m" % (counter , title))
	print (s)
	print ("\033[32;01m%s\033[00;00m" % address)
	print ( "-----------------------------------------------------------")
	dict[counter] = address
	if options.results == counter: break
	counter += 1
file = open("/tmp/google",'w')
for entries in range(1,len(dict)+1): file.write(dict[entries]+'\n')
