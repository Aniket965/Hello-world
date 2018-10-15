
class FizzBuzz

	def initialize
		puts "Pick a number to know if its a Fizz or a Buzz?"
		@num = gets.chomp.to_i
	end

	def is_fizzbuzz?
	  case
	  when @num % 15 == 0 then puts "FizzBuzz"
	  when @num % 3  == 0 then puts "Fizz"
	  when @num % 5  == 0 then puts "Buzz"
	  else puts "Not a FizzBuzz"
	  end
	end
	
end


fb = FizzBuzz.new
fb.is_fizzbuzz?
