/**
 Author: Wai Zin Linn
 Email: wlinn@wisc.edu
 NetID: 9082616286
 Description:  This is header file for Student which contains all the fuction declarations which will be implemented in
 cpp class.
 Credits: None
 */

#ifndef Student_h
#define Student_h

#include <stdio.h>
#include <vector>
#include "Person.h"

/**
 Student class inherenting from Person
 */
class Student: virtual public Person{

/**
Defining new variables for Student class
*/
private:
    vector<int>* courses;

/**
Methods of the Student class
*/
public:
    
    /**
     Default constructor for student
     */
    Student();
    
    /**
    Student's parametrized constructor with default values name, int, and courses pointer
    @param input_name name of the Student to be set
    @param input_ID ID of Student to be set
    @param input_courses courses of Student to be set
     */
    Student(string input_name, int input_ID, const vector<int>& input_courses);
    
    /**
    Copy constructor of Student class
     */
    Student(const Student &);
    
    /**
    Operator overloader of Student class
     */
    Student& operator=(const Student &);
    
    /**
     Destructor of Student class
     */
    ~Student();
    
    /**
    Display function for class member variables (name, ID, officeNum, courses)
     */
    void displayDetails(std::ostream&) const;
};


#endif /* Student_h */
