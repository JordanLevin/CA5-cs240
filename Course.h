#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>

class Course{
    public:
        std::string name;
        char req;
        std::vector<std::string> prereqs;

        Course() = default;
        ~Course() = default;
};
#endif /* ifndef SYMBOL */
