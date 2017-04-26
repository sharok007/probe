all: lab1
lab1: Log.o Board.o main.o Contact.o
	g++ Log.o Board.o main.o Contact.o -o lab
Log.o: Log.cpp
	g++ -c Log.cpp 
Board.o: Board.cpp
	g++ -c Board.cpp
main.o: main.cpp
	g++ -c main.cpp
Contact.o: Contact.cpp
	g++ -c Contact.cpp
clean:
	rm -rf *.o lab

debug:
	g++ -g main.cpp Student.cpp Teacher.cpp  Serv.cpp -o lab
