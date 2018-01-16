/*********************************************************************
 * File Name: Ship.hpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Header file for Ship.cpp.
 * *******************************************************************/

#ifndef Ship_hpp
#define Ship_hpp
#include "Space.hpp"
#include <stdio.h>


class Ship: public Space {
public:
    Ship();
    ~Ship();
    int menuA();
    int menuB();
};

#endif /* Ship_hpp */
