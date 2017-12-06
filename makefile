FLAGS = -g -Wall -std=c++14

all: main
	g++ $(FLAGS) main.o -o main

main: main.cpp Course.h Requirements.h CourseOffering.h
	g++ $(FLAGS) -c main.cpp

clean:
	rm -f main *.o
