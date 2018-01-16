/*********************************************************************
 * File Name: OceanC.hpp
 * Author: James Whiteley IV
 * Date: 3/9/2017
 * Description: Header file for OceanC.cpp.
 * *******************************************************************/

#ifndef OceanC_hpp
#define OceanC_hpp
#include "Space.hpp"
#include <stdio.h>

class OceanC: public Space {
public:
    OceanC();
    ~OceanC();
    int menuA();
    int menuB();
};


#endif /* OceanC_hpp */
