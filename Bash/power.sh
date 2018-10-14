#!/usr/bin/env bash

read -p "Enter number: " n
read -p "Enter index: " i
res=1

if((i==0));
then
  res=1
fi

if((n==0));
then
  res=0
fi

c=1

if((n>=1 && i>=1));
then
  while((c<=i))
  do
    res=$((res*n))
    c=$((c+1))
  done
fi

echo "$n raised to the power $i = $res"
