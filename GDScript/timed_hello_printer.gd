extends Node

var timer = 0
var printed_count = 0

func _process(delta):
  timer += 100 * delta
  
  if timer >= 200:
    printed_count += 1
    print("Hello World! Printed " + str(printed_count) + "time(s)")
    timer = 0
