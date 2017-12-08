#include "Requirements.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

std::string Requirements::verify(const CourseOfferings& offerings,
        const Schedule& schedule){
        bool good_schedule = false;
        //Checking if each course is offered
        for(size_t i = 0; i < schedule.semesters.size(); i++){
            for(size_t j = 0; j < schedule.semesters[i].classes.size(); j++){
                std::string name = schedule.semesters[i].classes[j];
                if (offerings.look_up.count(name)>0){
                    good_schedule = true;
                } else{
                    //return std::string("Course not found: ") + name;
                }
            }
        }
        //check that the course schedule works with prereqs
        
        for(auto sem: schedule.semesters){
            for(auto course: sem.classes){
                if(!take_class(course))
                    return std::string("Prereqs not met: ") + course;
            }
        }
        
        //If we find a reason for the schedule to fail we return false earlier
        //if program reaches here its valid
        return "Success";
}

bool Requirements::take_class(std::string name){
    for(auto c: courses){
        if(c.name == name){
            bool prereqs_completed = true;
            for(auto pr: c.prereq_ptr){
                if(!(pr->completed)){
                    prereqs_completed = false;
                    return false;
                }
            }
            if(prereqs_completed){
                c.completed = true;
                return true;
            }
        }
    }
    return false;
}

void Requirements::make_graph(){
    for(auto& course: courses){
        for(std::string& name: course.prereqs){
            auto prereq = std::find_if(courses.begin(), courses.end(),
                    [&](Course c){
                    return c.name == name;
                    });
            if(prereq != courses.end())
                course.prereq_ptr.push_back(&(*prereq));
        }
    }
}
