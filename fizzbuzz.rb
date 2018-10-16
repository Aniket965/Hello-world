class Fizzbuzz

  def play
    fizzbuzz?
    fizzbuzz(@int)
  end

  def fizzbuzz?
    print "Enter a number: "
    @int = gets.strip.to_i
  end

  def fizzbuzz(int)
    if int % 15 == 0
      puts "FizzBuzz"
    elsif int % 5 == 0
      puts "Buzz"
    elsif int % 3 == 0
      puts "Fizz"
    end
  end

end

Fizzbuzz.new.play
