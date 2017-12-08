#include "Requirements.h"
#include <string>
#include <vector>

using namespace std;

bool Requirements::verify(CourseOfferings offerings, 
        Schedule schedule){
        bool good_schedule = false;
        //Checking if each course is offered
        for(unsigned int i = 0; i < schedule.semesters.size(); i++){
            for(unsigned int j = 0; j < schedule.semesters[i].second.size(); j++){
              string name = schedule.semesters[i].second[j];
              if (offerings.look_up.count(name)>0){
                good_schedule = true;
              } else{
                return false;
              }
            }
        }
          
            //continue for other checks
        
        return good_schedule;
}

void Requirements::make_graph();
