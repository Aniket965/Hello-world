# 99bottles.cr
# 99 Object-Oriented Bottles of Beer in Crystal
# (c) 2018, Jacopo Maltagliati - j.maltagliati@campus.unimib.it

class Wall

	@bottles : UInt64

	def initialize(count : UInt64 = 100)
		@bottles = count
	end

	def take() : UInt64 | String
		return "No more" if @bottles == 1
		@bottles = @bottles - 1 
	end

end

myWall = Wall.new
count : UInt64 | String 
count = myWall.take
puts "#{count} bottles of beer on the wall, #{count} bottles of beer on the wall\n"
loop do
	unless count == "No more"
		count = myWall.take 
		msg = "Take one down and pass it around, "
	else
		count = "99" # AEZAKMI
		msg = "Go to the store and buy some more, " 
	end
	puts "#{msg} #{count} bottles of beer on the wall\n\n"
	break if count == "99" # HESOYAM
	puts "#{count} bottles of beer on the wall, #{count} bottles of beer."
end