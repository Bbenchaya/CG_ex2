//
//  Intersection.cpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 20/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#include "Intersection.hpp"

Intersection::Intersection() {
    
}

Intersection::Intersection(float min_distance, Primitive &min_primitive){
    this->min_distance = min_distance;
    this->min_primitive = min_primitive;
}

Intersection& Intersection::operator=(const Intersection &other){
    if (this == &other)
        return *this;
    this->min_distance = other.min_distance;
    this->min_primitive = other.min_primitive;
    return *this;
}

float Intersection::getMinDistance() const{
    return this->min_distance;
}

Primitive Intersection::getMinPrimitive() const{
    return this->min_primitive;
}