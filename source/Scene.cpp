//
//  Scene.cpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 16/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#include "Scene.hpp"
Scene::Scene(const Vector3f &center,
             const Vector3f &up,
             float width,
             float resolution_x,
             float resolution_y,
             const Vector3f &color){
    this->center = center;
    this->upVector = upVector;
    this->width = width;
    this->resolution_x = resolution_x;
    this->resolution_y = resolution_y;
    this->color = color;
}