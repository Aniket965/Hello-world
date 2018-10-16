def perform(string)
	string.each_char do |letter|
		puts letter
	end
end

perform("hello")