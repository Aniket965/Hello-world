#!/bin/bash

echo -n "Enter the first number: "
read firstNum

echo -n "Enter the second number: "
read secondNum

echo -n "Enter the third number: "
read thirdNum

echo "Enter 1 to find the sum, or 2 to find the average";
read userChoice

sum=`expr $firstNum + $secondNum + $thirdNum`

if [ $userChoice -eq 1 ]

then

    echo "The sum is $sum"

elif [ $userChoice -eq 2 ]

then  

    average=$(echo "$sum / 3" | bc -l)

    echo "The Average is $average"

fi
