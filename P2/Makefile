# Makefile for BookDB
# Name: Wai Zin Linn
# ID: 9082616286

CXX = g++
CXXFLAGS = -Wall

all: build

BookDB.o: BookDB.h

clean:
	-rm BookDB.o
	-rm bookDB

build: demo.cpp BookDB.o
	$(CXX) $(CXXFLAGS) -o bookDB demo.cpp BookDB.o
