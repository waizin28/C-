/**
 Author: Wai Zin Linn
 Email: wlinn@wisc.edu
 NetID: 9082616286
 Description:  This is header file for Instructor which contains all the fuction declarations which will be implemented in
 cpp class.
 Credits: None
 */

#ifndef Instructor_h
#define Instructor_h

#include <stdio.h>
#include "Employee.h"
#include <vector>

/**
 Instructor class inherenting from Employee
 */
class Instructor: public Employee{

/**
Defining new variables for Instructor class
*/
private:
    vector<int>* courses;

/**
Methods of the Instructor class
*/
public:
    
    /**
    Default constructor of Instructor class
     */
    Instructor();
    
    /**
    Instructor's parametrized constructor with default values name, int, officeNum and courses pointer,
    @param input_name name of the Instructor to be set
    @param input_ID ID of Instructor to be set
    @param input_officeNum officeNumber of Instructor to be set
    @param input_courses courses of Instructor to be set
     */
    Instructor(string input_name, int input_ID, int input_officeNum, const vector<int>& input_courses);
    
    /**
    Copy constructor of Instructor class
     */
    Instructor(const Instructor &);
    
    /**
    Operator overloader of Instructor class
     */
    Instructor& operator=(const Instructor &);
    
    /**
     Destructor of Student class
     */
    ~Instructor();
    
    /**
    Display function for class member variables (name, ID, officeNum, courses)
     */
    void displayDetails(std::ostream&) const;
};


#endif /* Instructor_h */
