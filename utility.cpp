/*********************************************************************
 * File Name: utility.cpp
 * Author: James Whiteley IV
 * Date: 2/21/2017
 * Description: reusable input validation functions, and menu function.
 * *******************************************************************/

#include "utility.hpp"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::cin;
using std::endl;

/*********************************************************************
 * returns char as uppercase letter.
 * *******************************************************************/
char getChar() {
    string input;
    
    do {
        cout << "> ";
        cin.clear();
        getline(cin, input);
    }
    while(!validChar(input));
    
    return toupper(input.at(0));
}

/*********************************************************************
 * returns true if upper case or lower case letter has been entered.
 * *******************************************************************/
bool validChar(string input) {
    //make sure something has been entered:
    if(int(input.length()) == 0) {
        cout << "You must enter a value." << endl;
        return false;
    }
    
    //make sure only one character entered:
    if(int(input.length()) > 1) {
        cout << "Please enter a valid input." << endl;
        return false;
    }
    
    char val = input.at(0);
    int asciiVal = val;
    //check uppercase letters
    for(int i = 65; i <= 90; i++) {
        if(asciiVal == i) {
            return true;
        }
    }
    //check lowercase letters
    for(int i = 97; i <= 122; i++) {
        if(asciiVal == i) {
            return true;
        }
    }
    
    cout << "Please enter a valid input." << endl;
    return false;  //return false if a value is not a char
    
}


/*********************************************************************
 * returns an integer.
 * *******************************************************************/
int getInt(int low, int high) {
    
    string input;
    
    do {
        cout << "> ";
        cin.clear();
        getline(cin, input);
    }
    while(!validInt(input, low, high));
    
    return stoi(input);

}


/*********************************************************************
 * returns true if input is valid integer.
 * *******************************************************************/
bool validInt(string input, int low, int high) {
    
    //make sure something has been entered:
    if(int(input.length()) == 0) {
       cout << "You must enter a value." << endl;
        return false;
    }
    
    for(int i=0; i < int(input.length()); i++) {
        //check if first value is a minus sign
        if(int(input.at(i)) == 45) {
            i++;
            //return false if minus sign is the only character entered
            if(int(input.length()) == 1) {
                cout << "Please enter a valid input." << endl;
                return false;
            }
        }
        char val = input.at(i);
        int asciiVal = val;
        if(asciiVal < 48 || asciiVal > 57) {
            cout << "Please enter a valid input." << endl;
            return false;  //return false if a value shows up that is not numeric
        }
    }
    
    if(stoi(input) < low || stoi(input) > high) {
        cout << "Input out of range." << endl;
        return false;
    }
    
    return true;
}


/*********************************************************************
 * returns a double.
 * *******************************************************************/
double getDoub() {
    string input;
    
    do {
        cout << "> ";
        cin.clear();
        getline(cin, input);
    }
    while(!validDoub(input));
    
    return stod(input);
}

          
/*********************************************************************
* returns true if input is valid double.
* *******************************************************************/
bool validDoub(string input) {
    
    //set dec to false showing there has not been a decimal yet
    bool dec = false;
    
    //make sure something has been entered:
    if(int(input.length()) == 0) {
        cout << "You must enter a value." << endl;
        return false;
    }
    
    for(int i=0; i < int(input.length()); i++) {
        //check if first value is a minus sign
        if(int(input.at(i)) == 45) {
            i++;
            //return false if minus sign is the only character entered
            if(int(input.length()) == 1) {
                cout << "Please enter a valid input." << endl;
                return false;
            }
        }
        char val = input.at(i);
        int asciiVal = val;
        
        if(asciiVal == 46) {
            if(dec == true) {
                cout << "Please enter a valid input." << endl;
                return false; //return false if two decimal points were entered in input
            }
            dec = true;
        }
        if((asciiVal < 48 && asciiVal != 46) || asciiVal > 57) {
            cout << "Please enter a valid input." << endl;
            return false;  //return false if a value shows up that is not numeric or a decimal
        }
    }
    
    //make sure input is not a single decimal point
    if (input.length() == 1 && dec == true) {
        cout << "Please enter a valid input." << endl;
        return false;
    }
    
    
    return true;  // return true if all values are numeric and is in range
}
