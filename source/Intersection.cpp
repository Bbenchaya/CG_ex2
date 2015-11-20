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

Intersection::Intersection(float min_distance, const Primitive &min_primitive){
    this->min_distance = min_distance;
    this->min_primitive = min_primitive;
}

Intersection& Intersection::operator=(const Intersection &other){
    if (this == &other)
        return *this;
    
    return *this;
}

float Intersection::getMinDistance(){
    return this->min_distance;
}

Primitive* Intersection::getMinPrimitive(){
    return &(this->min_primitive);
}