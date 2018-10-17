#!/bin/bash

number=0
while [ "$number" -lt 100 ]; do
    python3 ./readFromFile.py zulu
    number=$((number + 1))
done
