/**
 Author: Wai Zin Linn
 Email: wlinn@wisc.edu
 NetID: 9082616286
 Description: This class is a tester class testing functions from SummarizeGrades
 Credits: None
 */

#include "demo.h"
#include <iostream>
#include <fstream>
#include "SummarizeGrades.h"

int main(void){
    map<int,Name> studentNames;
    map<int, vector<int> > studentScores;
    int numAssignments;
    
    //read the file
    readGradeFile("unformatted_grades.txt", &numAssignments,studentNames,studentScores);
    
    map<int,Name>::iterator iter = studentNames.begin();
    
    while(iter != studentNames.end()){
        cout << iter->first << " " << iter->second.firstName << " " << iter->second.lastName << endl;
        iter++;
    }
    
    formatCaseOfNames(studentNames);
    
    map<int, int> totalScore;
    map<int, double> percent;
    
    computeTotalAndPercent(studentScores, totalScore, percent, numAssignments);
    
    //printing out score
    map<int, int>::iterator iter1 = totalScore.begin();
    while(iter1 != totalScore.end()){
        cout << iter1->first << " " << iter1->second << endl;
        iter1++;
    }
    
    //printing out percentage
    map<int, double>::iterator iter2 = percent.begin();
    while(iter2 != percent.end()){
        cout << iter2->first << " " << iter2->second << endl;
        iter2++;
    }
    
    //testing writeFormattedGrades method
    writeFormattedGrades("output.txt", studentNames, totalScore, percent);
    
    return 0;
}
