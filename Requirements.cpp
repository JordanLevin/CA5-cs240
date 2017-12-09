#include "Requirements.h"
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

std::string Requirements::verify(CourseOfferings& offerings,
        const Schedule& schedule){
    //Checking if each course is offered
    for(auto sem: schedule.semesters){
        for(auto course: sem.classes){
            std::string name = course; 
            if (offerings.look_up.count(name)<=0){
                return std::string("Error: course not found: ") + name;
            } else if (offerings.look_up[name].semester != 'E'){
                //cout << "this is sem.s: " << sem.s << endl;
                if (offerings.look_up[name].semester != sem.s){
                   return std::string("Error: course " + name + " is not offered in " + sem.s);
               } 
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
	for(auto choice: choices){
		int num_of_classes = 0;
        for(auto semester: schedule.semesters){
            for(auto course: semester.classes){
                if(std::find(choice.classes.begin(), choice.classes.end(),
                    course) != choice.classes.end()){
                    num_of_classes++;
                }
            }
        }
		
		if(num_of_classes != choice.amount){
			cout<<"Error: Haven't taken required amount of: ";
			for(auto optional_course_again : choice.classes)
				cout<< optional_course_again << " ";
			cout<<endl;
			return std::string("Schedule will not work until you choose ") + std::to_string(choice.amount) + std::string(" of these.");

	    }
    }
	
	
    //check that every mandatory/required class is taken
    for(auto course: courses){
        if((course.req == 'M' || course.req == 'R')
                && !(course.completed)){
            return std::string("Error: missing required/mandatory class: ") 
                + course.name;
        }
    }


    //If we find a reason for the schedule to fail we return false earlier
    //if program reaches here its valid
    return "Success";
}

bool Requirements::take_class(std::string name){
    bool class_found = false;
    for(auto& c: courses){
        if(c.name == name){
            class_found = true;
            bool prereqs_completed = true;
            for(auto& pr: c.prereq_ptr){
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
    //add special case for a class not listed in prereqs file
    if(!class_found){
        for(auto& c: courses){
            if(!c.completed && c.req == 'R'){
                return false;
            }
        }
        return true;
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
