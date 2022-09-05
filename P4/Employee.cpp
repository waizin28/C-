/**
 Author: Wai Zin Linn
 Email: wlinn@wisc.edu
 NetID: 9082616286
 Description:  This is class for Employee which contains all the fuctions needed to create an employee and print out the employee details such as name, id and office number. This class is the derived class from person. 
 Credits: None
 */

#include "Employee.h"
#include <string>
#include <iostream>

using namespace std;

Employee::Employee(){}

Employee::Employee(string input_name, int input_ID, int input_officeNum):Person(input_name,input_ID),officeNum(input_officeNum){
}

Employee::Employee(const Employee &p):Person(p){
    this->officeNum = p.officeNum;
}

Employee& Employee::operator=(const Employee &p){
    if(this != &p){
        Person::operator=(p);
        officeNum = p.officeNum;
    }
    return *this;
}

Employee::~Employee() = default;

void Employee::displayDetails(std::ostream& os) const{
    Person::displayDetails(os);
    os << "Employee details: " << endl;
    os << "\tOffice: " << officeNum << endl;
}


