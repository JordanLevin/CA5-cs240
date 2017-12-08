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
            bool completed;
            std::string name;
            char req;
            std::vector<std::string> prereqs;
            std::vector<Course*> prereq_ptr;

            Course() = default;
            ~Course() = default;
        };
        int total;
        std::vector<std::pair<char, int> > credits;
        std::vector<Course> courses;
        std::vector<Choice> choices;

        void make_graph();
        bool take_class(std::string name);
        std::string verify(const CourseOfferings& offerings, 
               const Schedule& sched);


};
#endif /* ifndef SYMBOL */
