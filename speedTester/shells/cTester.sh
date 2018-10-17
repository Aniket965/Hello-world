#!/bin/bash

gcc ./readFromFile.c -o ./shells/readFromFileC.out

number=0
while [ "$number" -lt 100 ]; do
    ./shells/readFromFileC.out "zulu"
    number=$((number + 1))
done
rm ./shells/readFromFileC.out
