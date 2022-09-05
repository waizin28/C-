/**
 Author: Wai Zin Linn
 Email: wlinn@wisc.edu
 NetID: 9082616286
 Description: This program contains all of the functions to reads a file with student information and their homework scores,
 manipulate that data to compute the total score and percentage for each student and then write a summary file with the computed scores for each student.
 Credits: None
 */

#include "SummarizeGrades.h"
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
using std::vector;

void readGradeFile(const string inputFile, int *numAssignments,
                   map<int, Name> &studentNames, map<int, vector<int> > &studentScores){
    
    ifstream inFile;
    inFile.open(inputFile.c_str());
    
    string variable;
    string numOfAssignment;
    string studentNum;
    string firstName;
    string lastName;
    
    inFile >> numOfAssignment >> *numAssignments;
    inFile >> studentNum >> firstName >> lastName;
    
    int possibleScores;
    for(int i = 0; i < *numAssignments; i++){
        inFile >> possibleScores;
    }
    
    //loop through end of the file
    while(!inFile.eof()){
        
        int id;
        Name stdName;
        vector<int> scores;
        
        inFile >> id >> stdName.firstName >> stdName.lastName;
        studentNames.insert(pair<int, Name>(id,stdName));
        
        for(int j = 0; j < *numAssignments; j++){
            int score;
            inFile >> score;
            scores.push_back(score);
        }
        
        studentScores.insert(pair<int, vector<int> >(id,scores));
        
    }
    
    inFile.close();
}

void formatCaseOfNames(map<int, Name> &names){
    
    map<int, Name>::iterator iter = names.begin();
    
    while(iter != names.end()){
        
        if(!isupper(iter->second.firstName[0])){
            iter->second.firstName[0] = toupper(iter->second.firstName[0]);
        }
        
        if(!isupper(iter->second.lastName[0])){
            iter->second.lastName[0] = toupper(iter->second.lastName[0]);
        }
        
        for(int i = 1; i < iter->second.firstName.length(); i++){
            if(isupper(iter->second.firstName[i])){
                iter->second.firstName[i] = tolower(iter->second.firstName[i]);
            }
        }
        
        for(int j = 1; j < iter->second.lastName.length(); j++){
            if(isupper(iter->second.lastName[j])){
                iter->second.lastName[j] = tolower(iter->second.lastName[j]);
            }
        }
        
        ++iter;
    }

}

void computeTotalAndPercent(const map<int, vector<int> > &scores, map<int, int> &total, map<int, double> &percent, int numAssignments){
    
    map<int, vector<int> >::const_iterator iter = scores.begin();
    
    while(iter != scores.end()){
        
        int totalScore = 0;
        double calPercent = 0;
        
        for(int i = 0; i < numAssignments; i++){
            totalScore += iter->second[i];
        }
        
        calPercent = totalScore/(numAssignments * 10.0);
        calPercent *= 100.0;
        
        total.insert(pair<int, int>(iter->first,totalScore));
        percent.insert(pair<int,double>(iter->first,calPercent));
        
        ++iter;
    }
    
}

void writeFormattedGrades(const string outputFile, const map<int, Name> &names, const map<int, int> &total, const map<int, double> &percent){
    
    ofstream outFile;
    outFile.open(outputFile.c_str());
    
    map<int, Name>::const_iterator iter = names.begin();
    
    while(iter != names.end()){
        
        outFile << iter->second.lastName << ", " << iter->second.firstName;
        
        int spacesIndent;
        spacesIndent = 20 - static_cast<int>(iter->second.lastName.length()) - static_cast<int>(iter->second.firstName.length()) - 2;
        
        
        for(int h = 0; h < spacesIndent; h++){
            outFile << " ";
        }
        
        outFile << total.at(iter->first);
        
        int spaceIndent2;
        
        if(percent.at(iter->first) == 100.0){
            spaceIndent2 = 2;
        }else if(percent.at(iter->first) < 10.0){
            spaceIndent2 = 4;
        }else{
            spaceIndent2 = 3;
        }
        
        for(int g = 0; g < spaceIndent2; g++){
            outFile << " ";
        }
        
        if(percent.at(iter->first) == 100.0){
            outFile << setprecision(4) << showpoint << static_cast<double>(percent.at(iter->first));
        }else if(percent.at(iter->first) < 10.0){
            outFile << setprecision(2) << showpoint << static_cast<double>(percent.at(iter->first));
        }else{
            outFile << setprecision(3) << showpoint << static_cast<double>(percent.at(iter->first));
        }
        
        outFile << endl;
        iter++;
    }
    
    outFile.close();
    
}
