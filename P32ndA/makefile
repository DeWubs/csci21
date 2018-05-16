labTest: bst_node.o bs_tree.o main.o
	g++ -Wall -std=c++11 -g -o labTest  bst_node.o bs_tree.o main.o 
	
bst_node: bst_node.cpp
	g++ -Wall -std=c++11 -g -c bst_node.cpp
	
bs_tree: bs_tree.cpp
	g++ -Wall -std=c++11 -g -c bs_tree.cpp

main: main.cpp
	g++ -Wall -std=c++11 -g -c main.cpp


clean:
	rm *.o labTest