//
//  Plane.cpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 16/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#include "Plane.hpp"

Plane::Plane(const Vector3f &normal,
             const Vector3f &center,
             float width,
             float length,
             float shine,
             const Vector3f &ka,
             const Vector3f &kd,
             const Vector3f &ks,
             bool mirror) : Primitive('p'){
    this->normal = normal;
    this->center = center;
    this->width = width;
    this->length = length;
    this->ka = ka;
    this->kd = kd;
    this->ks = ks;
    this->mirror = mirror;
}

Vector3f Plane::getCenter(){
    return this->center;
}

Vector3f Plane::getNormal(){
    return this->normal;
}

float Plane::intersect(Ray &ray){
    float numerator = Vector3f::dotProduct(getCenter(), getNormal());
    float denominator = Vector3f::dotProduct(getNormal(), ray.getDirection());
    float scalar =  numerator / denominator;
    Vector3f possibleIntersection = ray.getDirection() * scalar;
    return 0;
}