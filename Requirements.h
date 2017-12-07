#ifndef REQUIREMENTS_H
#define REQUIREMENTS_H

#include <string>
#include <vector>
#include "Course.h"
#include "CourseOfferings.h"
#include "Schedule.h"

class Requirements {
    public:
        class Choice{
            public:
            int amount;
            std::vector<std::string> classes;
        };
        int total;
        std::vector<std::pair<char, int> > credits;
        std::vector<Course> courses;
        std::vector<Choice> choices;

        bool verify(CourseOfferings offerings, 
               Schedule sched);
};
#endif /* ifndef SYMBOL */
