//
//  Sphere.cpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 16/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#include "Sphere.hpp"

Sphere::Sphere(const Vector3f &center,
               float radius,
               const Vector3f &ka,
               const Vector3f &ks,
               const Vector3f &kd,
               float shine) : Primitive('s'){
    this->center = center;
    this->radius = radius;
    this->ka = ka;
    this->ks = ks;
    this->kd = kd;
    this->shine = shine;
}