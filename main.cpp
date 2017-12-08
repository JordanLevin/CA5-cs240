#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include "CourseOfferings.h"
#include "Requirements.h"
#include "Schedule.h"

Schedule read_schedule(std::string path){
    Schedule ret;
    std::string line, word;
    std::string s;

    std::ifstream read(path);
    while (read.good()){
        Schedule::Semester s;
        std::getline(read, line);
        std::istringstream in(line);
        in >> word;
        s.s = word[0];
        s.year = word;
        while (in >> word){
            s.classes.push_back(word);
        }
        //std::cout << "print" <<  s << std::endl;
        ret.semesters.push_back(s);
        //courses.clear();
    }
    return ret;
}

CourseOfferings read_offerings(std::string path){
    CourseOfferings ret;
    //values for storing input data in
    std::string line, word;
    int n;
    char c;

    std::ifstream read(path);
    while(read.good()){
        CourseOfferings::Offering course;

        std::getline(read, line);
        std::istringstream in(line);

        in >> word;
        course.name = word;
        in >> n;
        course.credits = n;
        in >> c;
        course.semester = c;
        in >> word;
        course.tags = word;

        ret.offerings.push_back(course);
        ret.look_up[course.name] = course;
    }

    return ret;
}

Requirements read_req(std::string path){
    Requirements ret;
    //values for storing input data in
    std::string line, word;
    int n;
    char c;

    std::ifstream read(path);
    while(read.good()){
        std::getline(read, line);
        std::istringstream in(line);
        in >> word;
        if(word == "TOTAL"){
            in >> n;
            ret.total = n;
        }
        else if(word == "CREDIT"){
            in >> c;
            in >> n;
            ret.credits[c] = n;
        }
        else if(word == "COURSE"){
            in >> word;
            in >> c;
            Requirements::Course course;
            course.name = word;
            course.req = c;
            while(in >> word){
                course.prereqs.push_back(word);
            }
            ret.courses.push_back(course);
        }
        else if(word == "CHOOSE"){
            in >> n;
            Requirements::Choice choice;
            choice.amount = n;
            while(in >> word){
                choice.classes.push_back(word);
            }
            ret.choices.push_back(choice);
        }


    }
    return ret;
}

int main(int argc, char *argv[]){
    auto req = read_req("./samples/req.txt"); 
    auto off = read_offerings("./samples/courses.txt"); 
    auto sched = read_schedule("./samples/schedule.txt");

    std::cout << req.verify(off, sched) << std::endl;
    //for (unsigned int i =0; i<req.courses.size(); i++){
        //std::cout << req.courses[i].name << std::endl;
    //}
    //for (unsigned int i =0; i<req.credits.size(); i++){
        //std::cout << req.credits[i].first << " " << req.credits[i].second << std::endl;
    //}
    //for (unsigned int i =0; i<sched.semesters.size()-1; i++){
        //std::cout << sched.semesters[i].year << std::endl;
    //}
    //sched.sort_semesters();
    return 0;
}
