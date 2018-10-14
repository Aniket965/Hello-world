#!/bin/bash
a=$1
b=$2
c=$3
if [ $a -gt $b -a $a -gt $c ]
then 
 echo "Largest Value: $a"
elif [ $b -gt $a -a $b -gt $c ]
then
 echo "Largest value: $b"
else [ $c -gt $a -a $c -gt $b ]
 echo "Largest value: $c"
fi
