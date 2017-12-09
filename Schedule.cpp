#include "Schedule.h"
#include <iostream>
#include <string>

using namespace std;

void Schedule::sort_semesters(){
  vector<Semester> sorted;
  while (semesters.size() >0) {
    int min = 0;
    for (unsigned int i = 0; i < semesters.size(); i++){
       char sem1 = semesters[i].s; 
       char sem2 = semesters[min].s; 
       int year_1 = stoi(semesters[i].year.substr(1,4));
       int year_2 = stoi(semesters[min].year.substr(1,4)); 

       if ( year_1 == year_2 && sem1 > sem2){
          min = i;
          //sorted.push_back(semesters[i]);
          //semesters.erase(semesters.begin()+i)
       } else if (year_1 < year_2){
          min = i;
       }
    }
    sorted.push_back(semesters[min]);
    semesters.erase(semesters.begin()+min);
  }
  semesters = sorted;
  for (unsigned int i = 0; i < semesters.size(); i++){
    cout << "sorted: " << sorted[i].s << " " << sorted[i].year << endl;
  }
}
