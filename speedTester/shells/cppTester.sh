#!/bin/bash

g++ ./readFromFile.cpp -o shells/readFromFile.out

number=0
while [ "$number" -lt 100 ]; do
    ./shells/readFromFile.out "zulu"
    number=$((number + 1))
done
rm shells/readFromFile.out
