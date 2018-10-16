extends Node

onready var childNode_label = null

func _ready():
 childNode_label = $Label
 childNode_label.text = "Hello World!"
