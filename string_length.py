def string_length(string):
    count = 0
    for letter in string:
        count = count+1
        print (letter)
    return count
    
def test_cases():
    assert string_length('hello') == 5
    assert string_length('aeshna') == 6
    print("UR CODE IS RUNNING")

test_cases()    
