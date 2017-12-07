#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <string>
#include <vector>
class Schedule {
  public:
    std::vector<std::pair<std::string, std::vector<std::string> > > semesters;  
    void sort_semesters();
};

#endif
