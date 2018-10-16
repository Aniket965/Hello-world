extends Node

var random_number = 0

func _ready():
  random_number = rand_range(0, 100)
  
  if random_number > 50:
    print("Hello World!")
   else:
    print("Hi World!")
