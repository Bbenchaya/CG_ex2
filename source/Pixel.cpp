//
//  Pixel.cpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 20/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#include "Pixel.hpp"

Pixel& Pixel::operator=(const Pixel &other){
    if (this == &other)
        return *this;
    RGB[0] = other.RGB[0];
    RGB[1] = other.RGB[1];
    RGB[2] = other.RGB[2];
    return *this;
}