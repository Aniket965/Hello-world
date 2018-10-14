class Main
  def self.run
    even_or_odd(4)
  end

  def self.even_or_odd(number)
  	message = (number%2).zero? ? "#{number} is even" : "#{number} is odd"
  	puts message
  end
end


Main.run