#include "Requirements.h"
#include <string>
#include <vector>

using namespace std;

bool Requirements::verify(CourseOfferings offerings, 
        Schedule schedule){
        bool good_schedule = true;
        //Checking if each course is offered
        /*for(int i = 0; i < schedule.size(); i++){
            string name = schedule[i][0];
            bool course_offered = false;
            for(int i = 0; i < offerings.size(); i++){
                if(offerings[i].name == name){
                    //implement the hash table and put it here so time
                    //complexity is better instead of this for loop
                    course_offered = true;
                }
            }
            if(!course_offered){
               return;
            }
          }
            //continue for other checks
        */
        return good_schedule;
}

void Requirements::make_graph();
