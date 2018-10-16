puts "Hello there! Please write your name!"
name = gets
puts "Great! So #{name}, write your favorite number!"

number = gets.to_s.to_i64?

if number.nil?
  puts "That's not a Number!!"
  exit
else
  i = number || 0
end

while i > 0
  puts "There is #{i} Crystals on the wall, take one down now there is #{i - 1} Crystals on the wall!"
  i -= 1
end

puts "There is no more Crystals on the wall, time to write some more!"

