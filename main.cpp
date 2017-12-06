#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#include "Course.h"
#include "CourseOfferings.h"
#include "Requirements.h"

std::vector<std::vector<std::string> > read_schedule(std::string path){
    std::vector<std::vector<std::string> > ret;
    std::string line;

    std::ifstream read(path);
    
    while(read.good()){
        std::getline(read, line);
        std::istringstream in(line);
        std::vector<std::string> semester;
        //split a string, taken from internet
        std::copy(std::istream_iterator<std::string>(in),
        std::istream_iterator<std::string>(),
        std::back_inserter(semester));

        ret.push_back(semester);
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
            ret.credits.push_back(std::make_pair(c, n));
        }
        else if(word == "COURSE"){
            in >> word;
            in >> c;
            Course course;
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
    return 0;
}
