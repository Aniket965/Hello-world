#!/bin/bash
# This code allows you to give random name to all files in a directory having a perticular extention
# Usage - random_files.sh mp3
# This would give random names to all files ending with .mp3
if [ $# -lt 1 ]; then
    echo "Please specify all the different types of extentions that exist (space seperated) as command line arguments"
else
    
    for ext in "$@"
    do
        for fname in *.$ext
        do
        mv "$fname" $RANDOM.$ext
        echo mv "$fname" $RANDOM.$ext
        done 
    done
fi
