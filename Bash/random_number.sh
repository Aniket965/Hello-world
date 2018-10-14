#!/bin/bash

# Prints a random positive integer. If MAX value is passed the number will be
# smaller than or equal MAX, if no MAX is passed, max will be 100

MAX="100"

if [ "$#" -ne  "0" ] && [ "$1" -gt "0" ]
  then MAX="$1"
fi

echo $(( ( RANDOM % MAX )  + 1 ))