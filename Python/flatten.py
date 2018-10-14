#!/usr/bin/env python3.5

li = [['a','b','c'],['a','c','d']]
flattened_list = [y for x in li for y in x]
print(flattened_list)