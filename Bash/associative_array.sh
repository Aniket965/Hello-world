#!/bin/bash
# Print out the header
read -p 'Please enter the name of the program to monitor(partial names are ok): ' processInput

 
declare -A continent
declare -a test

# test=( `ps --no-headers -o pid,comm -C $processInput` )
# echo "$(( ${#test[@]} / 2 ))"
# echo "${test[@]}" | wc -l

IFS=$'\n'       # make newlines the only separator
for j in $(ps --no-headers -o pid,comm -C $processInput)    
do
        IFS=$' ' read value key <<< $j
        echo $key-$value
    continent[$value]=$key
done

echo "#############"

echo "${#continent[@]}"

echo "#############"

for c in "${!continent[@]}"; do
    printf "Program %s has PID of %s \n" "${continent[$c]}" "$c" 
done
