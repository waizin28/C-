/**
 Author: Wai Zin Linn
 Email: wlinn@wisc.edu
 NetID: 9082616286
 Description:  This is header file for Employee which contains all the fuction declarations which will be implemented in
 cpp class.
 Credits: None
 */

#ifndef Employee_h
#define Employee_h

#include <stdio.h>
#include "Person.h"

/**
 Employee class inherenting from Person
 */
class Employee : virtual public Person {
    
/**
 Defining new variables for Employee class
 */
private:
    int officeNum = 0;

/**
Methods of the Employee class 
*/
public:
    
    /**
    Default constructor of Employee class
     */
    Employee();
    
    /**
    Employee's parametrized constructor with default values name, int, and officeNum
    @param input_name name of the Employee to be set
    @param input_ID ID of Emplyee to be set
    @param input_officeNum office number of Employee to be set
     */
    Employee(string input_name, int input_ID, int input_officeNum);
    
    /**
    Copy constructor of Employee class
     */
    Employee(const Employee &);
    
    /**
    Operator overloader of Employee class
     */
    Employee& operator=(const Employee &);
    
    /**
     Destructor of Employee class
     */
    ~Employee();
    
    /**
     Pure virtual function display class member variables (name, ID, officeNum)
     */
    virtual void displayDetails(std::ostream&) const = 0;
    
};

#endif /* Employee_h */
