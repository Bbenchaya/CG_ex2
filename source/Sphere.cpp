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

pair<float, Vector3f> Sphere::intersect(Ray &ray){
    float t_m = Vector3f::dotProduct(center, ray.getDirection());
    float d_squared = Vector3f::dotProduct(center, center) - powf(t_m, 2);
    if (d_squared > radius * radius)
        return make_pair(INFINITY, Vector3f());
    float t_h = sqrtf(radius * radius - d_squared);
    if (t_m - t_h > 0)
        return make_pair(t_m - t_h, ray.getDirection() * (t_m - t_h));
    else
        return make_pair(t_m + t_h, ray.getDirection() * (t_m + t_h));
}