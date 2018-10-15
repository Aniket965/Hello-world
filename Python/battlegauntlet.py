import os
import random

# Class that stores resources for making the enemies more difficult every time
class Resources:
    def __init__(self):
        self.enemyLowerLimit = 1
        self.enemyUpperLimit = 10
        self.enemyLimits = []
        for i in range(self.enemyLowerLimit, self.enemyUpperLimit+1):
            self.enemyLimits.append(i)

# Class that manages all the player things
class Player:
    
    # Initialise all the required variables
    def __init__(self, hp, strength, magic, defense, resistance, speed):
        self.maxHp = hp*20
        self.currentHp = self.maxHp
        self.strength = strength*10
        self.magic = magic*10
        self.defense = defense*10
        self.resistance = resistance*10
        self.speed = speed*10
        self.victories = 0

    # Return max HP
    def getMaxHP(self):
        return self.maxHp
    
    # Return current HP
    def getCurrentHP(self):
        return self.currentHp
    
    # Return Strength
    def getStrength(self):
        return self.strength
    
    # Return Magic
    def getMagic(self):
        return self.magic
    
    # Return Defense
    def getDefense(self):
        return self.defense
    
    # Return Resistance
    def getResistance(self):
        return self.resistance
    
    # Return Speed
    def getSpeed(self):
        return self.speed
    
    # Return Victories
    def getVictories(self):
        return self.victories
        
    # Calculate and return damage taken by player
    def damageTaken(self, enemyAttack, kind):
        damageTaken = 1
        if kind == 'physical':
            if self.defense > enemyAttack:
                damageTaken = 1
            else:
                damageTaken = enemyAttack - self.defense
        
        if kind == 'magical':
            if self.resistance > enemyAttack:
                damageTaken = 1
            else:
                damageTaken = enemyAttack - self.resistance
            
        self.currentHp -= damageTaken
        return damageTaken
    
# Stats and methods for the enemy
class Enemy:
    
    # Initialise all variables and set up the AI
    def __init__(self, hp, strength, magic, defense, resistance, speed):
        
        self.maxHp = hp*25
        self.currentHp = self.maxHp
        self.strength = strength*20
        self.magic = magic*20
        self.defense = defense*20
        self.resistance = resistance*20
        self.speed = speed*20
        self.preference = ''
        self.heal = True
        self.AI()
     
    def getMaxHP(self):
        return self.maxHp
    
    def getCurrentHP(self):
        return self.currentHp
    
    def getStrength(self):
        return self.strength
    
    def getMagic(self):
        return self.magic
    
    def getDefense(self):
        return self.defense
    
    def getResistance(self):
        return self.resistance
    
    def getSpeed(self):
        return self.speed
    
    # Calculates and returns damage taken
    def damageTaken(self, enemyAttack, kind):
        damageTaken = 1
        if kind == 'physical':
            if self.defense > enemyAttack:
                damageTaken = 1
            else:
                damageTaken = enemyAttack - self.defense
        
        if kind == 'magical':
            if self.resistance > enemyAttack:
                damageTaken = 1
            else:
                damageTaken = enemyAttack - self.resistance
            
        self.currentHp -= damageTaken
        return damageTaken
    
    # Decides which type of damage the enemy prefers to use
    def AI(self):
        if self.strength > self.magic:
            self.preference = 'physical'
        else:
            self.preference = 'magical'
        
        if self.maxHp < 0.25*self.currentHp and self.heal:
            self.currentHp = self.maxHp/0.75
            self.heal = False
    
    # Returns the damage done by the enemy and allows the enemy to heal
    def combat(self):
        
        if self.maxHp < 0.25*self.currentHp and self.heal:
            print('The enemy spends its turn healing itself')
            self.currentHp = self.maxHp/0.75
            self.heal = False
        
        elif self.preference == 'physical':
            return (self.strength, self.preference)
        
        elif self.preference == 'magical':
            return (self.magic, self.preference)

        
# Creating the enemy stat range globally as it is a constant
enemyStatBounds = []
for i in range(100):
    enemyStatBounds.append(i+1)

# Checking if either the player or enemy scored a critical hit, and displaying
# the appropriate message
def checkForCrit(crit):
    if crit:
        print('CRITICAL HIT!!!!!!')

# Conducts the battle between the player and the enemy     
def battle(player, enemy):
    victory = True
    print('Time to fight! It\'s your turn first!')
    while victory:
        # Player turn
        playerCrit = False
        critChance = random.randint(0, 1000)
        if critChance <= player.speed:
            critical = 75
            playerCrit = True
        else:
            critical = 0
        playerMove = input('What would you like to do? Attack[A] or use Magic[M]? ')
        if playerMove == 'A':
            if enemy.defense > player.strength:
                damageTaken = 1 + critical
                checkForCrit(playerCrit)
            else:
                damageTaken = player.strength - enemy.defense + critical
                checkForCrit(playerCrit)
            enemy.currentHp -= damageTaken
            print('The enemy took ', damageTaken, 'damage!!!')
            
        elif playerMove == 'M':
            if enemy.resistance > player.magic:
                damageTaken = 1 + critical
                checkForCrit(playerCrit)
            else:
                damageTaken = player.magic - enemy.resistance + critical
                checkForCrit(playerCrit)
            enemy.currentHp -= damageTaken
            print('The enemy took ', damageTaken, 'damage!!!')
        
        else:
            print('Wrong input! You lose your turn!')

        print('The enemy has ', enemy.currentHp, 'HP left!')
        
        # Enemy turn
        # (DAMAGE, PREFERENCE)
        enemyCrit = False
        critChance = random.randint(0, 1000)
        if critChance <= enemy.speed:
            critical = 75
            enemyCrit = True
        else:
            critical = 0
        enemyAttack = enemy.combat()
        if enemyAttack[1] == 'physical':
            if player.defense > enemy.strength:
                damageTaken = 1 + critical
                checkForCrit(enemyCrit)
            else:
                damageTaken = enemy.strength - player.defense + critical
                checkForCrit(enemyCrit)
            player.currentHp -= damageTaken
            print('The enemy does ', damageTaken, 'physical damage!!!')
            print('You have', player.currentHp, 'HP left!')
            
        elif enemyAttack[1] == 'magical':
            if player.resistance > enemy.magic:
                damageTaken = 1 + critical
                checkForCrit(enemyCrit)
            else:
                damageTaken = enemy.magic - player.resistance + critical
                checkForCrit(enemyCrit)
            player.currentHp -= damageTaken
            print('The enemy does ', damageTaken, 'magical damage!!!')
            print('You have', player.currentHp, 'HP left!')
        
        # Check if player lost
        if player.currentHp <= 0:
            print('You ran out of HP and so you lost!')
            return False
        
        if enemy.getCurrentHP() <= 0:
            print('You defeated the enemy!! Congratulations! Prepare for the next enemy!\n')
            keypress = input('Press any key when ready for the next enemy. ')
            player.victories += 1
            return True
            
# Randomly creates an enemy and returns it
def createEnemy():
    resources = Resources()
    hp = random.choice(resources.enemyLimits)
    strength = random.choice(resources.enemyLimits)
    defense = random.choice(resources.enemyLimits)
    magic = random.choice(resources.enemyLimits)
    resistance = random.choice(resources.enemyLimits)
    speed = random.choice(resources.enemyLimits)
    enemy = Enemy(hp, strength, magic, defense, resistance, speed)

    # Making the next enemy more powerful than the last
    if resources.enemyLowerLimit < 90 and resources.enemyUpperLimit < 100:
        resources.enemyLowerLimit += 10
        resources.enemyUpperLimit += 10
    return enemy
    
# Run the program        
def main():
    os.system('afplay Ominosity.mp3 &')
    availableStatDistribution = 60
    playerName = input('Welcome to the Famous Battle Gauntlet of DOOM. What is your name, challenger? ')
    print('You have 60 points available to distribute among your six stats, those being hp, strength, magic, defense, resistance, and speed')
    
    print('You may distribute them in any way you wish. You will not be allowed to extend the limit of 60.')
    
    hp = int(input('Enter your hit point score: '))
    availableStatDistribution -= hp
    if availableStatDistribution < 0:
        print('You cannot enter that many points into that stat. You have been disqualified. Run the program again.')
        return
    print('You have', availableStatDistribution, 'points left.')
    
    strength = int(input('Enter your strength score: '))
    availableStatDistribution -= strength
    if availableStatDistribution < 0:
        print('You cannot enter that many points into that stat. You have been disqualified. Run the program again.')
        return
    print('You have', availableStatDistribution, 'points left.')
    
    magic = int(input('Enter your magic score: '))
    availableStatDistribution -= magic
    if availableStatDistribution < 0:
        print('You cannot enter that many points into that stat. You have been disqualified. Run the program again.')
        return
    print('You have', availableStatDistribution, 'points left.')
    
    defense = int(input('Enter your defense score: '))
    availableStatDistribution -= defense
    if availableStatDistribution < 0:
        print('You cannot enter that many points into that stat. You have been disqualified. Run the program again.')
        return
    print('You have', availableStatDistribution, 'points left.')
    
    resistance = int(input('Enter your resistance score: '))
    availableStatDistribution -= resistance
    if availableStatDistribution < 0:
        print('You cannot enter that many points into that stat. You have been disqualified. Run the program again.')
        return
    print('You have', availableStatDistribution, 'points left.')
    
    speed = int(input('Enter your speed score: '))
    availableStatDistribution -= speed
    if availableStatDistribution < 0:
        print('You cannot enter that many points into that stat. You have been disqualified. Run the program again.')
        return
    
    player = Player(hp, strength, magic, defense, resistance, speed)
    
    defeated = False
    while defeated is False:
        enemy = createEnemy()
        victory = battle(player, enemy)
        if victory is True:
            continue
        else:
            defeated = True
            print('You lost!! You have ', player.victories, 'victories! Try again by running the program again!')
            
            # Access the terminal from the python program
            os.system('killall afplay')
            os.system('afplay Nevermore.mp3 &')
    file = open('leaderboards.txt', 'a')
    winner = '\n' + playerName + '\t' + str(player.victories)
    # Add player name and victories to leaderboard
    file.write(winner)
    file.close()
    request = input('Would you like to see the leaderboards? [Y/N] ')
    if request == 'Y':
        os.system('open leaderboards.txt')
    os.system('killall afplay')
    print('\nThank you for playing!!!')

    
if __name__ == '__main__':
    main()
