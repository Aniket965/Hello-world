def fibonacci(value)  
  return (fibonacci(value - 1) + fibonacci(value - 2))
end

puts "How many number of fibonacci do you want?"
nbr = gets.chomp.to_i
puts fibonacci(nbr)
