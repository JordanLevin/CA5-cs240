#ifndef COURSEOFFERING_H
#define COURSEOFFERING_H

#include <string>

class CourseOffering{
    public:
        std::string name;
        int credits;
        char semester;
        std::string tags;

        CourseOffering() = default;
        ~CourseOffering() = default;
};
#endif /* ifndef SYMBOL */
