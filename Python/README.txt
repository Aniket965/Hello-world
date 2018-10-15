
THIS PROJECT WAS MADE BY ANKIT SANGHI, CLASS OF 2021, CARLETON COLLEGE

Welcome to the Battle Gauntlet of DOOM!! In this gruesomely difficult game, you are challenged to defeat as many enemies as you can in a gauntlet of battles. You will not be allowed to rest or heal, and must jump into the next battle bravely, or die trying.

The game allows you to create your own character by allocating points to the 5 relevant stats. You have 60 points available. Those stats are:

HP - How many hit points you have (your health). The number you input is multiplied by 20, and that becomes the number of hit points you have. If your hit points drop to or go below zero, you lose the game.

Strength - Your physical combat ability. This stat determines how much damage you can do with physical attacks. The higher it is, the more damage you are able to do. The number you input is multiplied by 10 for damage calculation.

Magic - Your magical combat ability. This stat determines how much damage you can do with magical attacks. The higher it is, the more damage you are able to do. The number you input is multiplied by 10 for damage calculation.

Defense - Your ability to withstand physical attacks. This stat determines how little damage you take from physical attacks. If your defense is higher than the opponent’s strength, you only take 1 point of damage. If it isn’t, then your defense is subtracted from their strength stat and that is the amount of damage you take from the enemy’s attack. It is multiplied by 10 for damage calculation.

Resistance - Your ability to withstand magical attacks. This stat determines how little damage you take from magical attacks. If your resistance is higher than the opponent’s magic, you only take 1 point of damage. If it isn’t, then your resistance is subtracted from their magic stat and that is the amount of damage you take from the enemy’s attack. It is multiplied by 10 for damage calculation.

Speed - Your ability to move quickly and agilely to strike the enemy in the right place. This stat increases your chance of scoring a critical hit. Scoring a critical hit adds 75 points of damage to an attack. This damage is added to both magical and physical attacks. The chance of scoring a critical hit is determined as follows: critical chance = speed/100. 


Each enemy you face is completely randomized in terms of stats, and the enemies are intelligent and will fight to their strengths. For example, if the enemy has a higher strength score than magic score, it will use magic instead of strength. Thus, you will have to come up with a strategy to allocate your points into the right stats in order to get as far as possible. Every time you defeat an enemy, it gets stronger.

At the end of the game, i.e. once you lose, your name and the number of enemies that you defeated will be recorded on the leaderboard. You can view it at the end of the game. 

Gameplay:
You can make an attack with either strength[A] or magic[M]. If you enter any other input, your turn will be skipped. The 	gauntlet has no room for dillydallying. 


DOCUMENTATION:

Resources - class that holds attributes related to scaling enemy difficulty.
	
Player - class that holds all the methods related to the player character

Enemy - Class that holds all methods related to the enemy, including the AI() method, which allows the enemy to know which type of damage to use, as well as the combat() method, which returns the damage and damage type when fighting. 

checkForCrit(crit) - Checks if a critical hit has occurred. If it has then print a message to let the player know.

battle(player, enemy) - Conducts the entire battle.

createEnemy() - Creates a newly randomized enemy and returns it.

main() - Runs the program

CURRENT STATUS:
The program works perfectly. There are no noticeable bugs and everything seems to be running smoothly.

CITATIONS:
Music by Tanner Helland. http://www.tannerhelland.com/music-directory/

Libraries used - os, random. These are built in libraries in python.






























