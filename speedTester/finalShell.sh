#!/bin/bash
echo Starting...
echo Python
./shells/pyTester.sh
echo Python complete!
echo C
./shells/cTester.sh
echo C complete!
echo C++
./shells/cppTester.sh
echo C++ complete!
echo Java
./shells/javaTester.sh
echo Java complete!
echo All Done!
python3 ./logs/average.py
