#!/usr/bin/env  python2

import  sys
from ast import literal_eval

#taking input from user in inline method

userinp = sys.argv

#restricting input to two values only
data = userinp[1:]

#seperating inputs from data in seperate variables
x,y=data

#checking datatype of inputs

def checkinput(input_data):
    try:
        return type(literal_eval(input_data))
    except (ValueError, SyntaxError):
        # error when we are giving unrecognisable datatype
	# so we are considering it as string
        return str

#now adding two inputs only if they are integers otherwise throwing msg about wrong datatype we have used

try:
	print int(x)+int(y)
except ValueError:
	print "both inputs should be of type int but here:-"
	print "x is :",checkinput(x)
	print "and"
	print "y is :",checkinput(y)


