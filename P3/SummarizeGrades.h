/**
 Author: Wai Zin Linn
 Email: wlinn@wisc.edu
 NetID: 9082616286
 Description:  This is header file for SummarizeGrades which contains all the fuction declaration.
 Credits: None
 */

#ifndef SummarizeGrades_h
#define SummarizeGrades_h

#include <stdio.h>
#include <vector>
#include <string>
#include <map>
using namespace std;
using std::vector;

/**
 Creating a new type Name for firstName and lastName of student
 */
typedef struct{
    string firstName;
    string lastName;
} Name;

/**
 This function takes the path of the input file and
 references to some data structures that will hold the student names and scores for other func-
 tions to process. It also contains pointers to variables that will keep track of the number of
 students and assignments.
 
 @param inputFile The file to be read
 @param numAssignments To store numAssignements value that we get from file into there
 @param studentNames Store the student name with the student ID as the key, and the value
 as a Name structure containing the first name and last name.
 @param studentScores Store the scores of each student with the student ID as the key, and the
 value is a vector of ints to hold the scores.
 */
void readGradeFile(const string inputFile, int *numAssignments,
                   map<int, Name> &studentNames, map<int, vector<int> > &studentScores);

/**
 This function takes the student names map and changes the first and last name strings in the struct (values in map) so
 that the first letter of each string is a capital letter and all other letters are lower case.
 @param names Student name with the student ID as the key, and the value as a Name
 structure containing the first name and last name.
 */
void formatCaseOfNames(map<int, Name> &names);

/**
 This function takes the scores map and computes the total score (the sum of all points earned) as well as the
 final percentage as a float and stores these computed results in total and percent maps respectively
 where key is the key from the scores map.
 @param scores Contain a vector that have list of scores
 @param total Store the total score where key is ID and value is total score calculared from scores
 @param percent Store the total percent where key is ID and value is percent calculared from scores
 @param numAssignments Total number of assignments from scores
 */
void computeTotalAndPercent(const map<int, vector<int> > &scores, map<int, int> &total,
                            map<int, double> &percent, int numAssignments);

/**
 This function will output the formatted grades to the file designated in outputFile, overwriting any contents if the file
 exists as follows.
 @param outputFile File to write out to
 @param names Have a vector of student names
 @param total Have a vector of total score for each students
 @param percent Have a vector of  percent for each students
 */
void writeFormattedGrades(const string outputFile, const map<int, Name> &names,
                          const map<int, int> &total, const map<int, double> &percent);

#endif /* SummarizeGrades_h */
