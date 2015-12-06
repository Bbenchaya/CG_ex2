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
               float shine,
               bool mirror) : Primitive('s'){
    this->center = center;
    this->radius = radius;
    this->ka = ka;
    this->ks = ks;
    this->kd = kd;
    this->shine = shine;
    this->mirror = mirror;
}

Sphere& Sphere::operator=(const Sphere &other){
    if (this == &other)
        return *this;
    this->center = other.center;
    this->radius = other.radius;
    this->ka = other.ka;
    this->ks = other.ks;
    this->kd = other.kd;
    this->mirror = other.mirror;
    this->shine = other.shine;
    return *this;
}

pair<float, Vector3f> Sphere::intersect(Vector3f p0, Vector3f V){
    Vector3f L = center - p0;
    float t_m = Vector3f::dotProduct(L, V);
    float d_squared = powf(L.getLength(), 2) - powf(t_m, 2);
    if (d_squared > radius * radius)
        return make_pair(INFINITY, Vector3f());
    float t_h = sqrtf(radius * radius - d_squared);
    if (t_m - t_h > 0){
        Vector3f intersectionVector = V * (t_m - t_h);
        return make_pair(intersectionVector.getLength(), intersectionVector);
    }
    else
        return make_pair(INFINITY, Vector3f());
}

Vector3f Sphere::getKa(Vector3f at_point) {
    return this->ka;
}

Vector3f Sphere::getKd(Vector3f at_point){
    return this->kd;
}

Vector3f Sphere::getKs(Vector3f at_point){
    return this->ks;
}

float Sphere::getShine(){
    return this->shine;
}

Vector3f Sphere::getNormal(Vector3f point){
    Vector3f N = point - center;
    return N / N.getLength();
}

bool Sphere::isMirror(){
    return this->mirror;
}