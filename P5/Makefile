# Makefile for P5
# Name: Wai Zin Linn
# ID: 9082616286

CXX = g++
CXXFLAGS = -Wall -std=c++11

all: build

InfiniteInt.o: InfiniteInt.h

clean:
	-rm InfiniteInt.o
	-rm InfiniteInt

build: demo.cpp InfiniteInt.o 
	$(CXX) $(CXXFLAGS) -o demo demo.cpp InfiniteInt.o
