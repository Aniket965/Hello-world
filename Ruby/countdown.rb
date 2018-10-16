def countdown(value)
	while value > 0
		puts value
		value -= 1
	end
	puts "BOOOOOOOOMMMMMMMMM !"
end

puts "What's your value ?"
print "> "
value = gets.chomp.to_i
countdown(value)