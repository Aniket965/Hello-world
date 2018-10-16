extends Node

onready var childNode_label = $Label

func _ready():
 childNode_label.text = "Hello World!"
