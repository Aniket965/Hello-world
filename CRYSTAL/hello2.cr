# hello2.cr
# "Hello, world!" in Crystal, using type annotations
# (c) 2018, Jacopo Maltagliati ~ j.maltagliati@campus.unimib.it

class HelloWorldType

	@helloWorldMsg : String
	
	def initialize(@helloWorldMsg = "Hello, world!") 		
	end

	def to_s
		return @helloWorldMsg
	end

end

HelloWorldObject = HelloWorldType.new()
CrystalTypeSystem = HelloWorldType.new("Welcome to Crystal's type system!")

puts "#{HelloWorldObject.to_s}\n#{CrystalTypeSystem.to_s}"