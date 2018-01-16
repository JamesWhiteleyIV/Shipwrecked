/*********************************************************************
 * File Name: utility.hpp
 * Author: James Whiteley IV
 * Date: 2/21/2017
 * Description: header file for utility.cpp
 * ******************************************************************/

#ifndef utility_hpp
#define utility_hpp
#include <string>
using std::string;
#include <stdio.h>

int menu();
char getChar();
bool validChar(string);
int getInt(int, int);
bool validInt(string, int, int);
double getDoub();
bool validDoub(string);


#endif /* utility_hpp */
