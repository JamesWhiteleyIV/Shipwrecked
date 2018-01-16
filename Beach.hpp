/*********************************************************************
 * File Name: Beach.hpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Header file for Beach.cpp.
 * *******************************************************************/

#ifndef Beach_hpp
#define Beach_hpp
#include "Space.hpp"
#include <stdio.h>

class Beach: public Space {
private:
public:
    Beach() {};
    ~Beach();
    int menuA();
    int menuB();
};

#endif /* Beach_hpp */
