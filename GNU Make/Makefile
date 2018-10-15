input=/home/piyush/Desktop/codes/input.txt
output=/home/piyush/Desktop/codes/output.txt
flags=-Warray-bounds -std=c++17 -g

all:${name}
	$ ./${name} <${input} >${output} 


${name}:${name}.cpp
	$ g++ ${flags} -o $@ $^