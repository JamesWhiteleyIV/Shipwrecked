/*********************************************************************
 * File Name: JungleA.hpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Header file for JungleA.cpp.
 * *******************************************************************/

#ifndef JungleA_hpp
#define JungleA_hpp
#include "Space.hpp"
#include <vector>
#include <stdio.h>

class JungleA: public Space {
private:
public:
    JungleA();
    ~JungleA();
    int menuA();
    int menuB();
};


#endif /* JungleA_hpp */
