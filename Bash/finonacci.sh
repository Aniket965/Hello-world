#!/bin/bash

declare -i var1=1
declare -i var2=1

read -p "Introduce un número: " num

for ((i=1; i<=$num; i++)); do

	echo -n "$var1 "
	result=$(($var1+$var2))
	var1=$var2
	var2=$result
done

echo

exit 0
