puts "Hello guys! Welcome to the Super Mario Bros Pyramid!"
print "> "
userNumber = Integer(gets.chomp)
puts "Here is the pyramid: "
pyramidBlock = "#"
counterEmptySpace = userNumber
EmptySpace = " "

userNumber.times do
	counterEmptySpace = counterEmptySpace-1

		counterEmptySpace.times do
			print EmptySpace
		end

		print pyramidBlock

		10.times do
		print EmptySpace
		end
		if counterEmptySpace == userNumber - 1
			print "<"
		else
			print "|"
		end

		pyramidBlock = pyramidBlock + "#"
		puts ""
end