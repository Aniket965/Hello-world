#!/bin/bash

count=0
while [ $count -ne 10 ]; do
    sl || ( [ $count -eq 0 ] && sudo apt install -y sl)
    count=$((count+1))
done