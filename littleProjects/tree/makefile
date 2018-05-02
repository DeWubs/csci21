CXX = g++
CXXFLAGS = -Wall -std=c++11 -g

main: bst_node.o bs_tree.o lab_24_unit_test.o
	$(CXX) $(CXXFLAGS) -o main bst_node.o bs_tree.o lab_24_unit_test.o

bst_node.o: bst_node.cpp
	$(CXX) $(CXXFLAGS) -c bst_node.cpp
	
bs_tree.o: bs_tree.cpp
	$(CXX) $(CXXFLAGS) -c bs_tree.cpp
	
lab_24_unit_test.o: lab_24_unit_test.cpp bst_node.cpp bs_tree.cpp
	$(CXX) $(CXXFLAGS) -c lab_24_unit_test.cpp bst_node.cpp bs_tree.cpp

#cleans up old .o files	
clean:
	rm *.o *test