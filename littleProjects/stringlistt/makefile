list: node.o test1.o
	g++ -Wall -std=c++11 -g -o list node.o test1.o

node: node.cpp
	g++ -Wall -std=c++11 -g -c node.cpp

test1: test1.cpp
	g++ -Wall -std=c++11 -g -c test1.cpp

clean:
	rm *.o list