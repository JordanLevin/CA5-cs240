#ifndef REQUIREMENTS_H
#define REQUIREMENTS_H

#include <string>
#include <vector>
#include "CourseOfferings.h"
#include "Schedule.h"

class Requirements {
    public:
        class Choice{
            public:
            int amount;
            std::vector<std::string> classes;
        };
        class Course{
            public:
                std::string name;
                char req;
                std::vector<std::string> prereqs;

                Course() = default;
                ~Course() = default;
        };
        int total;
        std::vector<std::pair<char, int> > credits;
        std::vector<Course> courses;
        std::vector<Choice> choices;

        bool verify(CourseOfferings offerings, 
               Schedule sched);
};
#endif /* ifndef SYMBOL */
