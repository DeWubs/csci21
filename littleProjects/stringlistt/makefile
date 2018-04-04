stackTest:  node stack test 
	g++ -Wall -std=c++11 -g -o stackTest node.o stack.o test.o 

node: node.cpp
	g++ -Wall -std=c++11 -g -c node.cpp

stack: stack.cpp
	g++ -Wall -std=c++11 -g -c stack.cpp

test: test.cpp
	g++ -Wall -std=c++11 -g -c test.cpp

clean:
	rm *.o stackTest
	
	
	
	