FLAGS = -g -Wall -std=c++14

all: main
	g++ $(FLAGS) main.o Requirements.cpp Schedule.o -o main

main: main.cpp Course.h Requirements.h CourseOfferings.h Schedule.h
	g++ $(FLAGS) -c main.cpp Requirements.cpp Schedule.cpp

clean:
	rm -f main *.o
