#ifndef COURSEOFFERINGS_H
#define COURSEOFFERINGS_H

#include <string>
#include <vector>
#include <unordered_map>

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
        std::unordered_map<std::string, Offering> look_up; 

        CourseOfferings() = default;
        ~CourseOfferings() = default;
};
#endif /* ifndef SYMBOL */
