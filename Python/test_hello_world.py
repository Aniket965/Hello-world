# Hello Testing World

def add(num1, num2):
    sum = num1 + num2
    return sum


def test_add():
    assert add(10, 15) == 25, "Incorrect Sum"


# pytest command to run the test
# python -m pytest C:\python_tests\test_hello_world.py
