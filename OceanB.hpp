/*********************************************************************
 * File Name: OceanB.hpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Header file for OceanB.cpp.
 * *******************************************************************/

#ifndef OceanB_hpp
#define OceanB_hpp
#include "Space.hpp"
#include <stdio.h>

class OceanB: public Space {
public:
    OceanB();
    ~OceanB();
    int menuA();
    int menuB();
};


#endif /* OceanB_hpp */
