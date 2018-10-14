#!/bin/bash
#this script allows you to change all files ending with a specific extension to another extension
#example usage : to change all files in current directory with .flac extension to .mp3 extension : bash extension_changer.sh flac mp3

for f in *.$1; do
    mv -- "$f" "${f%.$1}.$2"
    done
