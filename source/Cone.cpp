//
//  Cone.cpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 3/12/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#include "Cone.hpp"

Cone::Cone(const Vector3f &center,
           float z_min,
           float z_max,
           const Vector3f &ka,
           const Vector3f &ks,
           const Vector3f &kd,
           float shine) : Primitive('c'){
    this->center = center;
    this->z_min = z_min;
    this->z_max = z_max;
    this->ka = ka;
    this->ks = ks;
    this->kd = kd;
    this->shine = shine;
}

Cone& Cone::operator=(const Cone &other){
    if (this == &other)
        return *this;
    this->center = other.center;
    this->z_min = other.z_min;
    this->z_max = other.z_max;
    this->ka = other.ka;
    this->ks = other.ks;
    this->kd = other.kd;
    this->shine = other.shine;
    return *this;
}

pair<float, Vector3f> Cone::intersect(Vector3f p0, Vector3f V){
    float a = powf(V[0], 2) + powf(V[1], 2) - powf(V[2], 2);
    float b = 2 * (p0[0] * V[0] + p0[1] * V[1] - p0[2] * V[2]);
    float c = powf(p0[0], 2) + powf(p0[1], 2) - powf(p0[2], 2);
    float t12 = powf(b, 2) - 4 * a * c;
    if (t12 < 0)
        return make_pair(INFINITY, Vector3f());
    t12 = sqrtf(t12);
    float t1 = (-b + t12) / (2 * a);
    float t2 = (-b - t12) / (2 * a);
    Vector3f intersectionVector = V * fminf(t1, t2);
    return make_pair(intersectionVector.getLength(), intersectionVector);
}

Vector3f Cone::getKa(Vector3f at_point) {
    return this->ka;
}

Vector3f Cone::getKd(Vector3f at_point){
    return this->kd;
}

Vector3f Cone::getKs(Vector3f at_point){
    return this->ks;
}

float Cone::getShine(){
    return this->shine;
}

Vector3f Cone::getNormal(Vector3f point){
    Vector3f N = point - center;
    return N / N.getLength();
}