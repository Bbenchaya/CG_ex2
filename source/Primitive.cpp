//
//  Primitive.cpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 20/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#include "Primitive.hpp"

Primitive::Primitive() : type('\0'){
    
}

Primitive::Primitive(char type) : type(type){
    
}

Primitive& Primitive::operator=(const Primitive &other){
    if (this == &other)
        return *this;
    return *this;
}

bool Primitive::operator!=(const Primitive &other){
    return (this != &other);
}

pair<float, Vector3f> Primitive::intersect(Ray &ray){
    return make_pair(INFINITY, Vector3f());
}

Vector3f Primitive::getNormal(Vector3f point){
    return Vector3f();
}

Vector3f Primitive::getKa(){
    return Vector3f();
}

Vector3f Primitive::getKd(){
    return Vector3f();
}

Vector3f Primitive::getKs(){
    return Vector3f();
}

float Primitive::getShine(){
    return 0.0;
}


const char Primitive::instanceof(){
    return type;
}