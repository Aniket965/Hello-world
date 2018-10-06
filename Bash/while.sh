#!/bin/bash

i=10
sum=0
while [ $i -gt 0 ]
do
        sum=$((sum+i))
        i=$((i-1))

done

echo "Sum = $sum"
