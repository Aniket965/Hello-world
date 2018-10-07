from sys import exit

def start():
	print "You are in your safe house"
	print "safe from the nuclear fallout"
	print "But you cant remain in here forever"
	print "You have to reach your vault"
	print "You have started your journey to the vault"
	trap() 

def trap():
	print "You have encountered some zombie's affected by the radiation"
	print "You have to fight them"
	print "You have two options"
	print "Input A to kill them, B to distract them"
	
	while True:
		next = raw_input("> ")

		if next == "A":
			lake()
		elif next == "B":
			b_room()
		else: 
			death("You only had two options but since you did'nt choose any you are dead")

def b_room():
	print "You choose the second option thus you have made it safely to the b room now"
	print "You cant stay here forever tough and must move forward to survive"
	print "You have two options now"
	print "You may see your options below"
	print "option A - you break the door gather all the food you have and leave"
	print "option B - you stay here and wait for passing by lookout troops to rescue you"

	while True:
		next = raw_input("> ")

		if next == "A":
			lake()
		elif next == "B":
			d_room()
		else:
			death("You only had two options but since you did'nt choose any you are dead")

def d_room():
	print 	
	print	"you have spawned into the d room"
	print	"This is the medic room where you can treat all your wounds"
	print	"you have two choices"
	print	"option A - parkhour to the safe house risking death"
	print	"option B - take the long road and reach safely"
			
	while True:
			next = raw_input("> ")

			if next == "A":
				safe_house()
			elif next == "B":
				b_room()
			else:
				death("You were eaten by all the zombies around you")


def lake():
	print   "You have moved forward to the lake"
	print	"Batelling zombies fighting bears"
	print	"Dont think your troubles are over yet"
	print	"The lake is all foggy"
	print	"there are dangerous animals in the lake"
	print	"you only have two options"
	print	 "A - gather raw material from trees and build a boat"
	print	 "B - risk swimming but end up going to a inbetween safehouse deep in the forest to"
		 	
		  

	while True:
		next = raw_input("> ")

		if next == "A":
			c_room()
		elif next == "B":
			d_room()
		else:
			death("You were eaten by all the zombies around you")

def c_room():
	print   "you have moved to the c room"
	print	"This is a final frontier before you are in the safe zone"
	print	"Altough everything depends on what decisions you make"
	print	"option A - you parkhour through the forest but risk stumbling and killing yourself"
	print	"option B - you go slow and take the long cut "
			


		  	
	while True:
		next = raw_input("> ")

		if next == "A":
			start()
		elif next == "B":
			safe_house()
		else:
			death("You were eaten by all the zombies around you")

def death(why):
	print why, "Good job!"
	exit(safe)

def safe_house():

	print "you have safely reached the safe house"
	print "Thank you for playing"
			
			
	exit(2)

start ()
