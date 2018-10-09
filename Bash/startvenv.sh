#!/bin/bash
# This code starts a python virtual environment from anywhere
# Replace the path in line 13 with the path where you have stored all your virtual environments (dont replace $1)
# Usage source startvenv <name of virtual environment>
# Ex: source startvenv hello_world
# This will start a virtual environment with the name hello_world (if it exists)

if [ $# -lt 1 ]; then
	echo "Please specify the name of Virtual Environment you want to start"
		
else

	vir_path=/media/coderdude/Adwait/virtual_environs/$1
  # this should be replaced with vir_path = <path to virtual environments>/$1
	if [ ! -d $vir_path ]; then
		echo "Virtual Environment of this name does not exist "
		
		
	else
		echo "Starting "$1 "..."
		source $vir_path/bin/activate
		echo "If the Virtual Environment does not start , execute startvir by preceding with 'source' or a '.'"
		echo "Example : "
		echo ". startvir name_of_VE "
		echo "source startvir name_of_VE" 
	fi
fi
