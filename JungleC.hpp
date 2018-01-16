/*********************************************************************
 * File Name: JungleC.hpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Header file for JungleC.cpp.
 * *******************************************************************/

#ifndef JungleC_hpp
#define JungleC_hpp
#include "Space.hpp"
#include <stdio.h>


class JungleC: public Space {
private:
public:
    JungleC() {};
    ~JungleC();
    int menuA();
    int menuB();
};


#endif /* JungleC_hpp */
