#!/usr/bin/env bash


while [ "$inp" != 4 ]
do
	echo -en "Please guess the number: "
	read inp
	
	echo $inp | grep "[^0-9]" > /dev/null 2>&1
	if [ "$?" -eq "0" ]; then
		echo "Sorry, you have to enter a number."
	elif [ $inp -ne 4 ]; then
		echo "Wrong! Try again."
	fi
done

echo "Correct!"
