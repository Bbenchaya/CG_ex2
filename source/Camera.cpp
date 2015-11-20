//
//  Camera.cpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 18/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#include "Camera.hpp"

Camera::Camera(){
    
}

Camera::Camera(const Vector3f &position,
               const Vector3f &direction){
    this->position = position;
    this->direction = direction;
}