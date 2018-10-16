#!/usr/bin/env python
# -*- encoding: utf-8 -*-
from __future__ import print_function

import sys


def tshirt(name):
    print(("%s would like to have a t-shirt!" % name))


if __name__ == '__main__':
    tshirt(sys.argv[1])
