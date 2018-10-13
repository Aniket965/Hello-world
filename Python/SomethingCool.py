def cool(name):
  if name == 'Peter':
      print("You are super cool!")
  elif name[0] == 'P':
      print("you are pretty cool!")
  else:
      print("Your name doesn't start with a P, you are soooooooo uncool!")
    
name = raw_input("What is your name?" )
cool(name)
