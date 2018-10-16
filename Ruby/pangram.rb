# Determine if a sentence is a pangram (contains every letter in the English alphabet)
class Pangram
  def initialize
    puts "Enter phrase to be evaluated:"
    @phrase = gets.chomp.to_s
    pangram(@phrase)
  end

  def pangram(phrase)
    #create array of a-z
      x = ('a'..'z').to_a
    # split out letters in phrase
      y = @phrase.downcase.split('')
    #find differences
    z = (x - y).empty?
    if z == true
      puts "'#{@phrase}' is a pangram"
    else
      puts "'#{@phrase}' is not a pangram"
    end
  end
end

Pangram.new
