#!/bin/bash

convert -version > /dev/null 2>&1 || { echo >&2 "You need to install imagemagick (can be done with homebrew)"; exit 1; }

cd "`dirname \"$0\"`"

clear
read -p "Ending of source files (only ending, no dot, case sensitive): " ending
read -p "Resize to? (Example format: 650x650): " size
read -p "Crop the image (y/n)?: " crop
read -p "Quality (Format: 0-100)?: " quality
read -p "Save as (Format: png, jpg, gif)?: " end_format

for file in *."$ending"; do
    filename="${file%.*}"

    if [[ $crop =~ ^(yes|y|Y|Yes|YES)$ ]]
    then
        convert "$file" -resize "$size^" -gravity center -crop "$size+0+0" "web_$filename.$end_format"
    else
        convert "$file" -resize "$size" -quality "$quality" "web_$filename.$end_format"
    fi
    echo "File converted: $file"
done

echo "Script finished."
exit 0;
