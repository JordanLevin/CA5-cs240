FLAGS = -g -Wall -std=c++14

all: main Requirements Schedule
	g++ $(FLAGS) main.o Requirements.o Schedule.o -o main

main: main.cpp Requirements.h CourseOfferings.h Schedule.h
	g++ $(FLAGS) -c main.cpp

Requirements: Requirements.cpp Requirements.h
	g++ $(FLAGS) Requirements.cpp -c

Schedule: Schedule.cpp Schedule.h
	g++ $(FLAGS) Schedule.cpp -c

clean:
	rm -f main *.o
