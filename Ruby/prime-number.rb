=begin
This program checks if the given number is prime or not.
However, ruby comes with a pre-defined Prime class which can be used to check if the number is prime or not.
It can be executed by importing the "prime" class. 
=end
class Main
  def input
    #num = gets.to_i
    result = check_prime(5)
    if result == true
        puts "prime"
    else
        puts "composite"
    end
  end
  def check_prime(num)
    (2..(num-1)).each do [i]
      if num%i == 0
        return false
      end
    end
    return true
  end
end
