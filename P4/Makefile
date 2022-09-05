# Makefile for P4
# Name: Wai Zin Linn
# ID: 9082616286

CXX = g++
CXXFLAGS = -Wall -std=c++11

all: build

Person.o: Person.h
Employee.o: Employee.h
Student.o: Student.h
Instructor.o: Instructor.h
TeachingAssistant.o: TeachingAssistant.h

clean:
	-rm Person.o
	-rm person
	-rm Employee.o
	-rm employee
	-rm Student.o
	-rm student
	-rm Instructor.o
	-rm instructor
	-rm TeachingAssistant.o
	-rm teachingAssistant

build: demo.cpp Person.o Employee.o Student.o Instructor.o TeachingAssistant.o
	$(CXX) $(CXXFLAGS) -o demo demo.cpp Person.o Employee.o Student.o Instructor.o TeachingAssistant.o

