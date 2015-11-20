//
//  Ray.cpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 18/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#include "Ray.hpp"

Ray::Ray(){
    
}

Ray::Ray(Vector3f &direction){
    this->direction = direction;
}

Ray& Ray::operator=(const Ray &other){
    if (this == &other)
        return *this;
    this->direction = other.direction;
    return *this;
}

Vector3f Ray::getDirection() const{
    return this->direction;
}