/**
 Author: Wai Zin Linn
 Email: wlinn@wisc.edu
 NetID: 9082616286
 Description:  This is class for TeachingAssistant which contains all the fuctions needed to create a teaching assistant and print out the info of teaching assistant such as name, id, office num, teaching coureses (if instructor) or learning courses (if student). This class is derived class from Insturctor and Student.
 Credits: None
 */
#include "TeachingAssistant.h"
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

TeachingAssistant::TeachingAssistant() = default;

TeachingAssistant::TeachingAssistant(string input_name, int input_ID, int input_officeNum, const vector<int>& teaching_courses, const vector<int>& learning_courses) : Person(input_name, input_ID), Instructor(input_name, input_ID, input_officeNum, teaching_courses), Student(input_name, input_ID, learning_courses){
}

TeachingAssistant::TeachingAssistant(const TeachingAssistant &p): Person(p), Instructor(p), Student(p){}

TeachingAssistant& TeachingAssistant::operator=(const TeachingAssistant &p){
    if(this != &p){
        Student::operator=(p);
        Instructor::operator=(p);
    }
    return *this;
}

TeachingAssistant::~TeachingAssistant()=default;

void TeachingAssistant::displayDetails(std::ostream& os) const{
    stringstream strm;
    
    Instructor::displayDetails(os);
    Student::displayDetails(strm);
    
    string temp;
    getline(strm,temp);
    getline(strm,temp);
    
    while(getline(strm,temp)){
        os << temp << endl;
    }
    
}

