# Returns no. of times the 'char' appears in the 'string'
#
# Note:
# This will behave differently if the value of 'char' is of length more than one.
# Check this link for more info: https://ruby-doc.org/core-2.2.0/String.html#method-i-count
def count_char(string, char)
  string.count(char)
end

puts "Enter a string: "
string = gets.chomp
puts "Enter a char to find count: "
char = gets.chomp

puts "Count of char in the string: #{count_char(string, char)}"
