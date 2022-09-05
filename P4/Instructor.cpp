/**
 Author: Wai Zin Linn
 Email: wlinn@wisc.edu
 NetID: 9082616286
 Description:  This is class for Instructor which contains all the fuctions needed to create an instructor
 Credits: None
 */

#include "Instructor.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;
using std::vector;

Instructor::Instructor():courses(new vector<int>()){};

Instructor::Instructor(string input_name, int input_ID, int input_officeNum, const vector<int>& input_courses) : Person(input_name, input_ID), Employee(input_name, input_ID, input_officeNum), courses{new vector<int>(input_courses)} {
}

Instructor::Instructor(const Instructor &p): Person(p), Employee(p), courses(new vector<int>(*p.courses)){}

Instructor& Instructor::operator=(const Instructor &p){
    if(this != &p){
        Employee::operator=(p);
        courses = new vector<int>(*p.courses);
    }
    return *this;
}

Instructor::~Instructor(){
    delete courses;
}

void Instructor::displayDetails(std::ostream& os) const{
    Employee::displayDetails(os);
    os << "Instructor details: " << endl;
    os << "\tCourses: ";
    for(int i = 0; i < courses->size();i++){
        if(i+1 != courses->size()){
        os << courses->at(i) << ", ";
        }else{
            os << courses->at(i);
        }
    }
    os << "\n";
}
