#!/bin/bash
#syntax:
#gitshortcut message
#change /var/www to your proyect folder you want to push.
echo "function gitshortcut() {	
	cd /var/www/ 	
	git add .
	git commit -m "$1"
	git push -u origin master
}" >> $HOME/.bashrc
