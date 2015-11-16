//
//  Sphere.cpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 16/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#include "Sphere.h"

Sphere::Sphere(float x, float y, float z, float radius, float *ka, float *kd, float *ks, float shine){
    this->x = x;
    this->y = y;
    this->z = z;
    this->radius = radius;
    this->ka[0] = ka[0];
    this->ka[1] = ka[1];
    this->ka[2] = ka[2];
    this->kd[0] = kd[0];
    this->kd[1] = kd[1];
    this->kd[2] = kd[2];
    this->ks[0] = ks[0];
    this->ks[1] = ks[1];
    this->ks[2] = ks[2];
    this->shine = shine;
}