value = input()

while True:
    foo = input()
    if foo == "=": break
    bar = input()
    if bar == "=": break
    
    try:
        value = eval(str(value)+bar+foo)
    catch:
        value = "Error!"
        break

print("\nOutput:\n\t%.2f" % value)

"""
For example, putting in:
>>> 4
>>> 5
>>> +
>>> 6
>>> -
>>> =
would be evaluated to (4+5)-6, or 4

Putting in:
>>> 3
>>> 2
>>> *
>>> 4
>>> /
>>> =
would be evaluated to (3*2)/4, or 1.5

"""
