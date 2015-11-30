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

Sphere& Sphere::operator=(const Sphere &other){
    if (this == &other)
        return *this;
    this->center = other.center;
    this->radius = other.radius;
    this->ka = other.ka;
    this->ks = other.ks;
    this->kd = other.kd;
    this->shine = other.shine;
    return *this;
}

pair<float, Vector3f> Sphere::intersect(Ray &ray){
    float t_m = Vector3f::dotProduct(center, ray.getDirection());
    float d_squared = Vector3f::dotProduct(center, center) - powf(t_m, 2);
    if (d_squared > radius * radius)
        return make_pair(INFINITY, Vector3f());
    float t_h = sqrtf(radius * radius - d_squared);
    if (t_m - t_h > 0){
        Vector3f intersectionVector = ray.getDirection() * (t_m - t_h);
        return make_pair(sqrtf(Vector3f::dotProduct(intersectionVector, intersectionVector)), intersectionVector); // ray-sphere intersection point
    }
    else {
        Vector3f intersectionVector = ray.getDirection() * (t_m + t_h);
        return make_pair(sqrtf(Vector3f::dotProduct(intersectionVector, intersectionVector)), intersectionVector); // ray-sphere intersection point
    }
}

Vector3f Sphere::getKa() {
    return this->ka;
}

Vector3f Sphere::getKd(){
    return this->kd;
}

Vector3f Sphere::getKs(){
    return this->ks;
}

float Sphere::getShine(){
    return this->shine;
}

Vector3f Sphere::getNormal(Vector3f point){
    //possible bug? should 'new'?
    return (point - center)/Vector3f::dotProduct(point-center, point-center);
}