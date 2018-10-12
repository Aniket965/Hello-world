#!/usr/bin/env python3

"""
__author__ = "Jonathan Chiou"
__version__ = "1.0.1"

This is a simple stopwatch script that records a start and stop time.
It also calculates the difference between the two times.
The user can also supply a description of the event.
The results are ithen written to a .csv as a tuple.

Simply run this script from the command line as 
$python3 TimeKeeper.py

"""

import datetime, os

def getTimes():
    start = datetime.datetime.now()
    print("========================================")
    print("Time began at " + str(start))
    print("========================================\n")
    type =input("\nType of event: \n")
    interrupt = input("\nPress any key to stop timer...\n\n")
    if interrupt is not None:
        end = datetime.datetime.now()
        print("========================================")
        print("Time ended at " + str(end))
        print("========================================\n")
        total_time = end - start
        print("========================================")
        print("Total time: " + str(total_time))
        print("========================================\n")
    values = (type,str(start),str(end),str(total_time))
    return values

def startTimeKeeper():
    input_file = "Times.csv"
    
    values = getTimes()

    try:
        lines = []
        temp_filename = os.path.splitext(input_file)[0] + ".bak"
        os.rename(input_file, temp_filename) 
        with open(temp_filename,"r") as input_file: 
            for line in input_file:
                    lines.append(line)
            #print(lines)
        input_file.close()
    except IOError:
        print("No backup file")
    
    with open("Times.csv","w+") as output_file:
        print("\nHISTORY")
        print("========================================")
        for line in lines:
            output_file.write(line)
            print(line)
        print("========================================")
        print("\nNEWEST")
        print("========================================")
        print(values)
        print("========================================")
        output_file.write(str(values)+"\n")
    output_file.close()
    try:
        os.remove(temp_filename)
    except OSError:
        pass

startTimeKeeper()

