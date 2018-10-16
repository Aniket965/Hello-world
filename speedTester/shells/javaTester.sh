#!/bin/bash

javac ./readFromFile.java -d ./shells

number=0
while [ "$number" -lt 100 ]; do
    java -cp ./shells readFromFile zulu
    number=$((number + 1))
done
rm shells/readFromFile.class
