


labtest:  temperature.o lab_10_unit_test.o
	g++ -Wall -g -o labtest temperature.o lab_10_unit_test.o

lab: temperature.cpp
	g++ -Wall -g -c temperature.cpp

unittest: lab_10_unit_test.cpp
	g++ -Wall -g -c lab_10_unit_test.cpp	

clean:
	rm *.o *test