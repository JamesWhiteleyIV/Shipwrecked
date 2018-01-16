/*********************************************************************
 * File Name: JungleB.hpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Header file for JungleB.cpp.
 * *******************************************************************/

#ifndef JungleB_hpp
#define JungleB_hpp
#include "Space.hpp"
#include <stdio.h>

class JungleB: public Space {
private:
public:
    JungleB(){};
    ~JungleB();
    int menuA();
    int menuB();
};

#endif /* JungleB_hpp */
