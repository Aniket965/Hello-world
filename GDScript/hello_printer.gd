extends Node

func _process(delta):
  if Input.is_action_just_pressed("ui_accept"): #when user presses "ui_accept" button (the default is spacebar)
    print("Hello World! This is made with GD Script #godot")
