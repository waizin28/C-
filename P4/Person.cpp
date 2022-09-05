/**
 Author: Wai Zin Linn
 Email: wlinn@wisc.edu
 NetID: 9082616286
 Description: This program contains all of the functions to create a Person and print out the details of person such as name and id. This will be base class.
 Credits: None
 */

#include "Person.h"
#include <string>
#include <iostream>

using namespace std;

Person::Person():name("Unknown Person"),ID(-1){}

Person::Person(string input_name, int input_ID):name(input_name),ID(input_ID){}

Person::Person(const Person &p){
    this->name = p.name;
    this->ID = p.ID;
}

Person& Person::operator=(const Person &p){
    if (this != &p){
        name = p.name;
        ID = p.ID;
     }
    return *this;
}

void Person::displayDetails(std::ostream& os) const{
    os << "Name: " << name << endl;
    os << "ID: " << ID << endl;
}

Person::~Person() = default;
