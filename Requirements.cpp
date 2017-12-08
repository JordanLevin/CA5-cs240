#include "Requirements.h"
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

std::string Requirements::verify(CourseOfferings& offerings,
        const Schedule& schedule){
    //Checking if each course is offered
    //TODO also check that the course offerings have it in the right semester
    for(auto sem: schedule.semesters){
        for(auto course: sem.classes){
            std::string name = course; 
            if (offerings.look_up.count(name)<=0){
                return std::string("Error: course not found: ") + name;
            }
        }
    }
    //check that the course schedule works with prereqs
    for(auto sem: schedule.semesters){
        for(auto course: sem.classes){
            if(!take_class(course))
                return std::string("Error: prereqs not met for ") + course;
        }
    }

    //check that correct total credit count is being taken
    int total_credits;
    for(auto sem: schedule.semesters){
        for(auto course: sem.classes){
            total_credits += offerings.look_up[course].credits;
        }
    }
    if(total_credits < total)
        return "Error: too few credits taken";

    //check that the right amount of special credits is taken
    //TODO potential edge case if there is a tag that doesnt have a required amnt at top
    std::unordered_map<char, int> special_reqs;
    for(auto sem: schedule.semesters){
        for(auto course: sem.classes){
            for(char c: offerings.look_up[course].tags){
                special_reqs[c] += offerings.look_up[course].credits;
            }
        }
    }
    for(auto tag: credits){
        if(tag.second > special_reqs[tag.first]){
            return std::string("Error: too few ") + tag.first + std::string(" credits ") +
                std::to_string(special_reqs[tag.first]) + "/" + std::to_string(tag.second);
        }
    }


    //check that the choices are being taken

    //check that every mandatory/required class is taken




    //If we find a reason for the schedule to fail we return false earlier
    //if program reaches here its valid
    return "Success";
}

//TODO add special case for a class not listed in prereqs file
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
