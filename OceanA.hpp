/*********************************************************************
 * File Name: OceanA.hpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Header file for OceanA.cpp.
 * *******************************************************************/

#ifndef OceanA_hpp
#define OceanA_hpp
#include "Space.hpp"
#include <stdio.h>

class OceanA: public Space {
public:
    OceanA();
    ~OceanA();
    int menuA();
    int menuB();
};


#endif /* OceanA_hpp */
