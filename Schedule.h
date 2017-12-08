#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include <vector>
class Schedule {
    public:
        class Semester {
            public:
            char s;
            std::string year; //add code to convert to int later
            std::vector<std::string> classes;
        };
        std::vector<Semester> semesters;  
        void sort_semesters();
};

#endif
