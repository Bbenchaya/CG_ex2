//
//  Triangle.cpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 29/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#include "Triangle.hpp"

Triangle::Triangle(){
    
}

Triangle::Triangle(Vector3f p1, Vector3f p2, Vector3f p3){
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}

Triangle& Triangle::operator=(const Triangle &other){
    if (this == &other)
        return *this;
    this->p1 = other.p1;
    this->p2 = other.p2;
    this->p3 = other.p3;
    return *this;
}

bool Triangle::intersect(Vector3f point){
    Vector3f normal = Vector3f::crossProduct(p1, p2);
    normal.normalize();
    if (Vector3f::dotProduct(point, normal) < 0){
        return false;}
    normal = Vector3f::crossProduct(p2, p3);
    normal.normalize();
    if (Vector3f::dotProduct(point, normal) < 0){
        return false;}
    normal = Vector3f::crossProduct(p3, p1);
    normal.normalize();
    if (Vector3f::dotProduct(point, normal) < 0){
        return false;}
    return true;
}