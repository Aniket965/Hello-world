from __future__ import print_function
from sys import exit

try:
    input = raw_input

except NameError:
    pass

def start():
    print("You are in your safe house\n"+
		"safe from the nuclear fallout\n"+
		"But you cant remain in here forever\n"+
		"You have to reach your vault\n"+
		"You have started your journey to the vault")

    trap()

def trap():
    print("You have encountered some zombie's affected by the radiaation\n"+
        "You have to fight them\n"+
        "You have two options\n"+
        "Input A to kill them, B to distract them")
	
    while True:
        next = input("> ")

        if next == 'A' or next == 'a':
            lake()

        elif next == 'B' or next == "b":
            b_room()

        else:
            death("You only had two options but since you did'nt choose any you are dead")

def b_room():
	print("You choose the second option thus you have made it safely to the b room now\n"+
	    "You cant stay here forever tough and must move forward to survive\n"+
	    "You have two options now\n"+
	    "You may see your options below\n"+
	    "option A - you break the door gather all the food you have and leave\n"+
	    "option B - you stay here and wait for passing by lookout troops to rescue you")

	while True:
		next = input("> ")

		if next == 'A' or next == 'a':
			lake()

		elif next == 'B' or next == 'b':
			d_room()

		else:
			death("You only had two options but since you did'nt choose any you are dead")

def d_room():
	print()
	print("you have spawned into the d room\n"+
	"This is the medic room where you can treat all your wounds\n"+
	"you have two choices\n"+
	"option A - parkhour to the safe house risking death\n"+
	"option B - take the long road and reach safely")
			
	while True:
		next = input("> ")

		if next == 'A' or next == 'a':
			safe_house()

		elif next == 'B' or next == 'b':
			b_room()

		else:
			death("You were eaten by all the zombies around you")


def lake():
	print("You have moved forward to the lake\n"+
	    "Batelling zombies fighting bears\n"+
	    "Dont think your troubles are over yet\n"
	    "The lake is all foggy\n"+
	    "there are dangerous animals in the lake\n"+
	    "you only have two options\n"+
	    "A - gather raw material from trees and build a boat\n"+
	    "B - risk swimming but end up going to a inbetween safehouse deep in the forest to")
		 	
		  

	while True:
		next = input("> ")

		if next == "A":
			c_room()

		elif next == "B":
			d_room()

		else:
			death("You were eaten by all the zombies around you")

def c_room():
	print("you have moved to the c room\n"+
	    "This is a final frontier before you are in the safe zone\n"+
	    "Altough everything depends on what decisions you make\n"+
	    "option A - you parkhour through the forest but risk stumbling and killing yourself\n"+
	    "option B - you go slow and take the long cut ")
			


		  	
	while True:
		next = input("> ")

		if next == 'A' or next == 'a':
			start()

		elif next == 'B' or next == 'b':
			safe_house()

		else:
			death("You were eaten by all the zombies around you")

def death(why):
	print(why, "Good job!")
	exit()

def safe_house():

	print("you have safely reached the safe house")
	print("Thank you for playing")

	exit(2)

start ()