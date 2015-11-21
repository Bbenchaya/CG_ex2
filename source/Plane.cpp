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

Vector3f Plane::getNormal(Vector3f point){
    return this->normal;
}

pair<float, Vector3f> Plane::intersect(Ray &ray){
    float numerator = Vector3f::dotProduct(getNormal(Vector3f()), getCenter());
    float denominator = Vector3f::dotProduct(getNormal(Vector3f()), ray.getDirection());
    float scalar =  numerator / denominator;
    Vector3f possibleIntersection = ray.getDirection() * scalar;
    Vector3f centerToPossibleIntersection = Vector3f();
    centerToPossibleIntersection.fromTo(center, possibleIntersection);
    float centerToPossibleIntersectionNorm = sqrtf(Vector3f::dotProduct(centerToPossibleIntersection, centerToPossibleIntersection));
    if (normal.p[2] == 0) { // plane rotates around z axis
        float cosAngle = Vector3f::dotProduct(centerToPossibleIntersection, Vector3f(0, 0, 1)) / centerToPossibleIntersectionNorm;
        float angle = acosf(cosAngle);
        float centerToPossibleIntersectionXComponent = centerToPossibleIntersectionNorm * cosAngle;
        float centerToPossibleIntersectionYComponent = centerToPossibleIntersectionNorm * sinf(angle);
        if (centerToPossibleIntersectionXComponent <= length / 2 && centerToPossibleIntersectionYComponent <= width / 2) {
            return make_pair(sqrtf(Vector3f::dotProduct(possibleIntersection, possibleIntersection)), possibleIntersection); // the distance from the origin to the intersection point
        }
        else return make_pair(INFINITY, Vector3f());
    }
    if (normal.p[1] == 0) { // plane rotates around y axis
        float cosAngle = Vector3f::dotProduct(centerToPossibleIntersection, Vector3f(0, 1, 0)) / centerToPossibleIntersectionNorm;
        float angle = acosf(cosAngle);
        float centerToPossibleIntersectionXComponent = centerToPossibleIntersectionNorm * cosAngle;
        float centerToPossibleIntersectionYComponent = centerToPossibleIntersectionNorm * sinf(angle);
        if (centerToPossibleIntersectionXComponent <= length / 2 && centerToPossibleIntersectionYComponent <= width / 2) {
            return make_pair(sqrtf(Vector3f::dotProduct(possibleIntersection, possibleIntersection)), possibleIntersection); // the distance from the origin to the intersection point
        }
        else return make_pair(INFINITY, Vector3f());
    }
    if (normal.p[0] == 0) { // plane rotates around z axis
        float cosAngle = Vector3f::dotProduct(centerToPossibleIntersection, Vector3f(1, 0, 0)) / centerToPossibleIntersectionNorm;
        float angle = acosf(cosAngle);
        float centerToPossibleIntersectionXComponent = centerToPossibleIntersectionNorm * cosAngle;
        float centerToPossibleIntersectionYComponent = centerToPossibleIntersectionNorm * sinf(angle);
        if (centerToPossibleIntersectionXComponent <= length / 2 && centerToPossibleIntersectionYComponent <= width / 2) {
            return make_pair(sqrtf(Vector3f::dotProduct(possibleIntersection, possibleIntersection)), possibleIntersection); // the distance from the origin to the intersection point
        }
        else return make_pair(INFINITY, Vector3f());
    }
    cout << "A plane was provided with illegal normal vector" << endl;
    return make_pair(0, Vector3f());;
}