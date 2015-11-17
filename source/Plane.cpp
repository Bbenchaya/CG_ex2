//
//  Plane.cpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 16/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#include "Plane.hpp"

Plane::Plane(float normalX, float normalY, float normalZ, float centerX, float centerY, float centerZ, float width, float length, float shine, float *ka, float *ks, float *kd, bool mirror){
    this->normalX = normalX;
    this->normalY = normalY;
    this->normalZ = normalZ;
    this->centerX = centerX;
    this->centerY = centerY;
    this->centerZ = centerZ;
    this->width = width;
    this->length = length;
    this->ka[0] = ka[0];
    this->ka[1] = ka[1];
    this->ka[2] = ka[2];
    this->ks[0] = ks[0];
    this->ks[1] = ks[1];
    this->ks[2] = ks[2];
    this->kd[0] = kd[0];
    this->kd[1] = kd[1];
    this->kd[2] = kd[2];
    this->mirror = mirror;
}