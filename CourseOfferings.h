#ifndef COURSEOFFERINGS_H
#define COURSEOFFERINGS_H

#include <string>
#include <vector>

class CourseOfferings{
    public:
        class Offering{
            public:
            std::string name;
            int credits;
            char semester;
            std::string tags;
        };

        std::vector<Offering> offerings;

        CourseOfferings() = default;
        ~CourseOfferings() = default;
};
#endif /* ifndef SYMBOL */
