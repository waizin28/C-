/**
 Author: Wai Zin Linn
 Email: wlinn@wisc.edu
 NetID: 9082616286
 Description:  This is header file for Person which contains all the fuction declarations which will be implemented in
 cpp class.
 Credits: None
 */
#ifndef Person_h
#define Person_h

#include "Person.h"
#include <string>

using namespace std;

/**
 Class Person which contains name and id which other people can inherit from
 */
class Person{

/**
 Variables of Person class that people will have access to when inherited
 */
private:
    string name = "Unknown Person";
    int ID = -1;
    
/**
 Methods of the Person class that people will have access to when inherited
 */
public:
    
    /**
    Default constructor
     */
    Person();
    
    /**
    Person's parametrized constructor with default values name and int
    @param input_name name of the person to be set
    @param input_ID ID of person to be set
     */
    Person(string input_name, int input_ID);
    
    /**
    Explicit copy constructor to prevent copying of objects at function calls or with the copy-initialization syntax
     */
    explicit Person(const Person&);
    
    /**
    Operator overloader of Person class
     */
    Person& operator=(const Person &);
    
    /**
     Destructor of Person class
     */
    virtual ~Person();
    
    /**
     Pure virtual function display class member variables (name, ID)
     */
    virtual void displayDetails(std::ostream&) const = 0; //enforce it will not change the field "const"
    
};

#endif /* Person_h */
