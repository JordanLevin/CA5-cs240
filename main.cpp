#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Course.h"
#include "Requirements.h"


int main(int argc, char *argv[]){
    
    return 0;
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
            auto p = std::make_pair(n, std::vector<std::string>());
            while(in >> word){
                p.second.push_back(word);
            }
            ret.choices.push_back(p);
        }

        
    }
}
