#!/usr/bin/env python2
# -*- coding: utf-8 -*-
import requests
import sys

URL = sys.argv[1]
VALUES = list()

for i in xrange(100):
    request = requests.get(URL)
    sys.stdout.write(str(request.status_code))
    if i != 99:
        sys.stdout.write(' ')
    sys.stdout.flush()
    VALUES.append(int(request.elapsed.total_seconds()))

print
average = sum(VALUES) / float(len(VALUES))
print 'Average response time for ' + URL + ' is ' + str(average)
