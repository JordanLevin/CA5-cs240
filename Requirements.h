#ifndef REQUIREMENTS_H
#define REQUIREMENTS_H

#include <string>
#include <vector>
#include "Course.h"

class Requirements {
    public:
        int total;
        std::vector<std::pair<char, int> > credits;
        std::vector<Course> courses;
        std::vector<std::pair<int, std::vector<std::string> > > choices;
};
#endif /* ifndef SYMBOL */
