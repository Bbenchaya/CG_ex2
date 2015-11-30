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
    /*
     Now find the plane's 4 corners. First, check if the plane is parallel to any of the 3 basic planes.
     If so, finding the corners is trivial. Otherwise, employ analytical geometry to find the corners.
     */
    // plane is parallel to xy plane
    if (normal.p[0] == 0 && normal.p[1] == 0){
        p1 = Vector3f(-length / 2, width / 2, normal.p[2]);
        p2 = Vector3f(length / 2, width / 2, normal.p[2]);
        p3 = Vector3f(length / 2, -width / 2, normal.p[2]);
        p4 = Vector3f(-length / 2, -width / 2, normal.p[2]);
    }
    // plane is parallel to xz plane
    else if (normal.p[0] == 0 && normal.p[2] == 0){
        p1 = Vector3f(width / 2, normal.p[1], -length / 2);
        p2 = Vector3f(width / 2, normal.p[1], length / 2);
        p3 = Vector3f(-width / 2, normal.p[1], length / 2);
        p4 = Vector3f(-width / 2, normal.p[1], -length / 2);
    }
    // plane is parallel to yz plane
    else if (normal.p[1] == 0 && normal.p[2] == 0){
        p1 = Vector3f(normal.p[0], width / 2, -length / 2);
        p2 = Vector3f(normal.p[0], width / 2, length / 2);
        p3 = Vector3f(normal.p[0], -width / 2, length / 2);
        p4 = Vector3f(normal.p[0], -width / 2, -length / 2);
    }
    else {
        // analytical geometry... =[
    }
    t1 = Triangle(p1, p2 ,p3);
    t2 = Triangle(p3, p4, p1);
}

Plane& Plane::operator=(const Plane &other){
    if (this == &other)
        return *this;
    this->normal = other.normal;
    this->center = other.center;
    this->width = other.width;
    this->length = other.length;
    this->shine = other.shine;
    this->ka = other.ka;
    this->ks = other.ks;
    this->kd = other.kd;
    this->mirror = other.mirror;
    this->p1 = other.p1;
    this->p2 = other.p2;
    this->p3 = other.p3;
    this->p4 = other.p4;
    this->t1 = other.t1;
    this->t2 = other.t2;
    return *this;
}

Vector3f Plane::getCenter(){
    return this->center;
}

Vector3f Plane::getNormal(Vector3f point){
    return this->normal;
}

pair<float, Vector3f> Plane::intersect(Ray &ray){
    float numerator = Vector3f::dotProduct(normal, center);
    float denominator = Vector3f::dotProduct(normal, ray.getDirection());
    if (denominator == 0)
        return make_pair(INFINITY, Vector3f());
    float scalar =  numerator / denominator;
    Vector3f possibleIntersection = ray.getDirection() * scalar;
    Vector3f centerToPossibleIntersection = Vector3f();
    centerToPossibleIntersection.fromTo(center, possibleIntersection);
    float centerToPossibleIntersectionNorm = centerToPossibleIntersection.getLength();
    if (t1.intersect(possibleIntersection) || t2.intersect(possibleIntersection))
        return make_pair(centerToPossibleIntersectionNorm, possibleIntersection);
    else
        return make_pair(INFINITY, Vector3f());

    
//    if (normal.p[2] == 0) { // plane rotates around z axis
//        float cosAngle = Vector3f::dotProduct(centerToPossibleIntersection, Vector3f(0, 0, 1)) / centerToPossibleIntersectionNorm;
//        float angle = acosf(cosAngle);
//        float centerToPossibleIntersectionXComponent = centerToPossibleIntersectionNorm * cosAngle;
//        float centerToPossibleIntersectionYComponent = centerToPossibleIntersectionNorm * sinf(angle);
//        if (centerToPossibleIntersectionXComponent <= length / 2 && centerToPossibleIntersectionYComponent <= width / 2) {
//            return make_pair(sqrtf(Vector3f::dotProduct(possibleIntersection, possibleIntersection)), possibleIntersection); // the distance from the origin to the intersection point
//        }
//        else return make_pair(INFINITY, Vector3f());
//    }
//    if (normal.p[1] == 0) { // plane rotates around y axis
//        float cosAngle = Vector3f::dotProduct(centerToPossibleIntersection, Vector3f(0, 1, 0)) / centerToPossibleIntersectionNorm;
//        float angle = acosf(cosAngle);
//        float centerToPossibleIntersectionXComponent = centerToPossibleIntersectionNorm * cosAngle;
//        float centerToPossibleIntersectionYComponent = centerToPossibleIntersectionNorm * sinf(angle);
//        if (centerToPossibleIntersectionXComponent <= length / 2 && centerToPossibleIntersectionYComponent <= width / 2) {
//            return make_pair(sqrtf(Vector3f::dotProduct(possibleIntersection, possibleIntersection)), possibleIntersection); // the distance from the origin to the intersection point
//        }
//        else return make_pair(INFINITY, Vector3f());
//    }
//    if (normal.p[0] == 0) { // plane rotates around z axis
//        float cosAngle = Vector3f::dotProduct(centerToPossibleIntersection, Vector3f(1, 0, 0)) / centerToPossibleIntersectionNorm;
//        float angle = acosf(cosAngle);
//        float centerToPossibleIntersectionXComponent = centerToPossibleIntersectionNorm * cosAngle;
//        float centerToPossibleIntersectionYComponent = centerToPossibleIntersectionNorm * sinf(angle);
//        if (centerToPossibleIntersectionXComponent <= length / 2 && centerToPossibleIntersectionYComponent <= width / 2) {
//            return make_pair(sqrtf(Vector3f::dotProduct(possibleIntersection, possibleIntersection)), possibleIntersection); // the distance from the origin to the intersection point
//        }
//        else return make_pair(INFINITY, Vector3f());
//    }
    cout << "A plane was provided with illegal normal vector" << endl;
    return make_pair(0, Vector3f());;
}



Vector3f Plane::getKa() {
    return this->ka;
}

Vector3f Plane::getKd(){
    return this->kd;
}

Vector3f Plane::getKs(){
    return this->ks;
}

float Plane::getShine(){
    return this->shine;
}