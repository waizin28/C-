/**
 Author: Wai Zin Linn
 Email: wlinn@wisc.edu
 NetID: 9082616286
 Description:  This is class for Student which contains all the fuctions needed to create a student and print out the details of the students such as name, id and courses taking. The student class is derived  from person.
 Credits: None
 */

#include "Student.h"

#include <stdio.h>
#include <vector>
#include <iostream>

Student::Student():courses(new vector<int>()){};

Student::Student(string input_name, int input_ID, const vector<int>& input_courses):Person(input_name,input_ID),courses{new vector<int>(input_courses)}{
}

Student::Student(const Student &p):Person(p){
    this->courses = new vector<int>(*p.courses);
}

Student& Student::operator=(const Student &p){
    if(this != &p){
        Person::operator=(p);
        courses = new vector<int>(*p.courses);
    }
    return *this;
}

Student::~Student(){delete courses;}

void Student::displayDetails(std::ostream& os) const{
    Person::displayDetails(os);
    os << "Student details: " << endl;
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

