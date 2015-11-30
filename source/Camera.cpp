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

Camera::Camera(Vector3f &position){
    this->position = position;
}

Vector3f Camera::getPosition() const{
    return this->position;
}

