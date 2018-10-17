def even_no(a):
    if (a%2 == 0):
      return (True)
    else :
      return (False)

def check_even():
     assert even_no(2) == True
     assert even_no(5) == True
     print("UR CODE IS GOOD TO GO")

check_even()     
