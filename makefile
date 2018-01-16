# Author: James Whiteley IV
# Final Project Makefile
# 3/10/2017

PROJ = Final
SRC = main utility Game Backpack Space Item Player Beach Ship OceanA OceanB OceanC JungleA JungleB JungleC

CXX = g++
CXXFLAGS = -std=c++11 
CXXFLAGS += -Wall -g
CXXFLAGS += -pedantic-errors
CPP = $(SRC:=.cpp)
OBJ = $(SRC:=.o)

all:
	$(CXX) $(CXXFLAGS) $(CPP) -o $(PROJ)

clean:
	rm $(OBJ)
