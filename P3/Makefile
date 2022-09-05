# Makefile for SummarizeGrades
# Name: Wai Zin Linn
# ID: 9082616286

CXX = g++
CXXFLAGS = -Wall

all: build

SummarizeGrades.o: SummarizeGrades.h

clean:
	-rm SummarizeGrades.o
	-rm summarizeGrades

build: demo.cpp SummarizeGrades.o
	$(CXX) $(CXXFLAGS) -o summarizeGrades demo.cpp SummarizeGrades.o

