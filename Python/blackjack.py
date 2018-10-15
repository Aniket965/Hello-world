#BLACKJACK GAME

#IMPORT LIBRARIES
import random

#DEFINE VARIABLES
suits = ("Hearts", "Diamonds", "Spades", "Clubs")
ranks = ("Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace")
values = {"Two":2, "Three":3, "Four":4, "Five":5, "Six":6, "Seven":7, "Eight":8, "Nine":9, "Ten":10, "Jack":10, "Queen":10, "King":10, "Ace":11}

playing = True

#CARD CLASS
class Card():
	
	def __init__(self,suit,rank):
		self.suit = suit
		self.rank = rank
	
	def __str__(self):
		return self.rank + " of " + self.suit

#DECK CLASS
class Deck():
	
	def __init__(self):
		self.deck = []
		for suit in suits:
			for rank in ranks:
				self.deck.append(Card(suit,rank))

	def __str__(self):
		deck_comp = ''

		for card in self.deck:
			deck_comp += "\n" + Card.__str__()
		return "The deck has: " + deck_comp

	def shuffle(self):
		random.shuffle(self.deck)

	def deal(self):
		single_card = self.deck.pop()
		return single_card

#HAND CLASS
class Hand():

	def __init__(self):
		self.cards = []
		self.value = 0
		self.aces = 0
	def add_card(self, card):
		self.cards.append(card)
		self.value += values[card.rank]

		if card.rank == "Ace":
			self.aces += 1
	def adjust_for_ace(self):

		while self.value > 21 and self.aces:
			self.value -= 10
			self.aces -= 1

#CHIPS CLASS
class Chips():
	def __init__(self,total=100):
		self.total = total
		self.bet = 0
	def win_bet(self):
		self.total += self.bet
	def lose_bet(self):
		self.total -= self.bet

#BET FUNCTION
def take_bet(chips):

	while True:
		try:
			chips.bet = int(input("How many chips would you like to bet? "))
		except:
			print("Sorry, please provide an integer.")
		else:
			if chips.bet > chips.total:
				print(f"Sorry, you do not have enough chips. You have {chips.total}")
			else:
				break

#HIT FUNCTION
def hit(deck, hand):
	hand.add_card(deck.deal())
	hand.adjust_for_ace

#HIT OR STAND
def hit_or_stand(deck, hand):
	global playing

	while  True:
		x = input("Hit or Stand? Enter h or s : ")

		if x[0].lower() == "h":
			hit(deck, hand)

		elif x[0].lower() == "s":
			print("Player stands. Dealer's Turn")
			playing = False

		else:
			print("Sorry, I didn't enter understand that. Please enter h or s only!.")
			continue

		break

#INITIAL DISPLAY
def show_some(player, dealer):
	print("\nDealer's hand: \n" + "<card hidden>" + " \n" + dealer.cards[1].__str__())
	print("\nPlayer's hand:", *player.cards , sep = "\n")

def show_all(player, dealer):
	print("\nDealer's hand:", *dealer.cards , sep = "\n")
	print("Dealer's hand = ",dealer.value)
	print("\nPlayer's hand:", *player.cards , sep = "\n")
	print("Player's hand = ",player.value)

#OUTPUT SCENARIOS
def player_busts(player, dealer, chips):
	print("BUST Player!")
	chips.lose_bet()

def player_wins(player, dealer, chips):
	print("Player WINS!")
	chips.win_bet()

def dealer_busts(player, dealer, chips):
	print("PLAYER WINS! DEALER BUSTED!")
	chips.win_bet()

def dealer_wins(player, dealer, chips):
	print("BUST PLAYER! DEALER WINS!")
	chips.lose_bet()

def push(player, dealer):
	print("Dealer and player tie! PUSH")

#DEFINE LOGIC
while True:
	
	print("Welcome to Blackjack!")

	#CREATE A DECK, PLAYER AND A DEALER
	deck = Deck()
	deck.shuffle()

	player_hand = Hand()
	player_hand.add_card(deck.deal())
	player_hand.add_card(deck.deal())

	dealer_hand = Hand()
	dealer_hand.add_card(deck.deal())
	dealer_hand.add_card(deck.deal())

	#SET UP THE PLAYER'S CHIPS
	player_chips = Chips()

	#PROMPT THE PLAYER FOR THEIR BET
	take_bet(player_chips)

	#SHOW CARDS BUT KEEP ONE DEALER CARD HIDDEN
	show_some(player_hand, dealer_hand)

	while playing:

		#PROMPT FOR PLAYER TO HIT OR STAND
		hit_or_stand(deck, player_hand)

		#SHOW CARDS BUT KEEP ONE DEALER CARD HIDDEN
		show_some(player_hand, dealer_hand)

		#IF PLAYER'S HAND EXCEEDS 21, RUN PLAYER_BUSTS() AND BREAK OUT OF LOOP
		if player_hand.value > 21:
			player_busts(player_hand, dealer_hand, player_chips)

			break

	#IF PLAYER HASN'T BUSTED PLAY DEALER'S HAND UNTIL HE REACHES 17
	if player_hand.value <= 21:

		while dealer_hand.value < 17:
			hit(deck, dealer_hand)

		#SHOW ALL CARDS
		show_all(player_hand, dealer_hand)

		#RUN DIFFERENT WINNING SCENARIOS
		if dealer_hand.value > 21:
			dealer_busts(player_hand, dealer_hand, player_chips)
		elif dealer_hand.value > player_hand.value:
			dealer_wins(player_hand, dealer_hand, player_chips)
		elif dealer_hand.value < player_hand.value:
			player_wins(player_hand, dealer_hand, player_chips)
		else:
			push(player_hand, dealer_hand)

	#INFORM PLAYER OF THEIR TOTAL CHIPS
	print(f"\nPlayer total chips are at: {player_chips.total}")

	#ASK TO PLAY AGAIN
	new_game = input("Would like to play another hand? y/n")

	if new_game[0].lower() == "y":
		playing = True
		continue
	else:
		print("Thanks for playing.")
		break