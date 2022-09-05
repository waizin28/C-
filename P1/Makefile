# Makefile for MathLib
# Name: Wai Zin Linn
# ID: 9082616286

CXX = g++
CXXFLAGS = -Wall

all: build

MathLib.o: MathLib.h

clean:
	-rm MathLib.o
	-rm mathLib

build: demo.cpp MathLib.o
	$(CXX) $(CXXFLAGS) -o mathLib demo.cpp MathLib.o
