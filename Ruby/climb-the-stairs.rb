#!/usr/bin/ruby
#
#   climb_the_stairs.rb
#       by - MacDesu -
#

def visualiser()
	height = 10
	block = 1
	until height == 0
		if @position == height
			(height - 1).times { print " " }
			print " => "
		else
			(height + 3).times { print " " }
		end
		block.times { print "#" }
		puts ""
		block += 2
		height -= 1
	end
end

def game()
	until @position == 10
		unless @position == 10
			puts "\nPress RETURN to launch the dice !"
			gets && system("clear")
		end
		dice = rand(1..6)
		puts ("You did " + dice.to_s + "!")
		if (dice == 1)
			if (@position > 1)
				@position -= 1
				puts "Bad luck ! You fall 1 floor lower..."
			else
				puts "You can't go lower..."
			end
		elsif (dice == 5 || dice == 6)
			@position += 1
			puts "You climb to the next floor !"
		else
			puts "You don't move"
		end
		puts "Your current position : FLOOR nb" + @position.to_s + ".\n\n"
		visualiser()
	end
end

def game_init
	@position = 1
	game()
	puts "\n\nCongratulation ! You reached the top !"
end

game_init()
