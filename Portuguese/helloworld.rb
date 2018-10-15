class HelloWorld
   def initialize(name)
      @name = name.capitalize
   end
   def portugal
      puts "Ola #{@name}!"
   end
end

hello = HelloWorld.new("Mundo")
hello.portugal