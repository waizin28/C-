/**
 Author: Wai Zin Linn
 Email: wlinn@wisc.edu
 NetID: 9082616286
 Description:  This is header file for TeachingAssitant which contains all the fuction declarations which will be implemented in
 cpp class.
 Credits: None
 */

#ifndef TeachingAssistant_h
#define TeachingAssistant_h

#include <stdio.h>
#include <string>
#include "Student.h"
#include "Instructor.h"

/**
 TeachingAssistant class inherenting from Instructor and Student classes
 */
class TeachingAssistant: public Instructor, public Student{

/**
 Defining all of the methods for TeachingAssistant
 */
public:
    
    /**
    Default constructor for TeachingAssistant
     */
    TeachingAssistant();
    
    /**
    TeachingAssistant's parametrized constructor
    @param input_name name of the TeachingAssistant to be set
    @param input_ID ID of TeachingAssistant to be set
    @param input_officeNum office identification for TeachingAssistant
    @param teaching_courses courses that TeachingAssistant would teach
    @paramlearning_courses courses that TeachingAssistant would learn
     */
    TeachingAssistant(string input_name, int input_ID, int input_officeNum, const vector<int>& teaching_courses, const vector<int>& learning_courses);
    
    /**
    Copy constructor of TeachingAssistant class
     */
    TeachingAssistant(const TeachingAssistant &);
    
    /**
    Operator overloader of TeachingAssistant class
     */
    TeachingAssistant& operator=(const TeachingAssistant &);
    
    /**
     Destructor of TeachingAssistant class
     */
    ~TeachingAssistant();
    
    /**
    Display function for class member variables
     */
    void displayDetails(std::ostream&) const;
};


#endif /* TeachingAssistant_h */
