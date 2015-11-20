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

Ray::Ray(const Vector3f &origin,
         const Vector3f &direction){
    this->origin = origin;
    this->direction = direction;
}

Ray& Ray::operator=(const Ray &other){
    if (this == &other)
        return *this;
    
    return *this;
}