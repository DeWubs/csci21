
labtest:  board.o player.o human.o computer.o main.o
	g++ -Wall -std=c++11 -g -o labtest board.o player.o human.o computer.o main.o

main.o: main.cpp
	g++ -Wall -std=c++11 -g -c main.cpp

board.o: board.cpp
	g++ -Wall -std=c++11 -g -c board.cpp	

computer.o: computer.cpp
	g++ -Wall -std=c++11 -g -c computer.cpp
	
human.o: human.cpp
	g++ -Wall -std=c++11 -g -c human.cpp
	
player.o: player.cpp
	g++ -Wall -std=c++11 -g -c player.cpp

clean:
	rm *.o *test