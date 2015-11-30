//
//  Plane.hpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 16/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#ifndef Plane_hpp
#define Plane_hpp

#include "Primitive.hpp"
#include "Triangle.hpp"

class Plane : public Primitive{
    
private:
    Vector3f normal;
    Vector3f center;
    float width;
    float length;
    float shine;
    Vector3f ka;
    Vector3f ks;
    Vector3f kd;
    bool mirror;
    Vector3f p1;
    Vector3f p2;
    Vector3f p3;
    Vector3f p4;
    Triangle t1;
    Triangle t2;
    
public:
    Plane(const Vector3f &normal,
          const Vector3f &center,
          float width,
          float length,
          float shine,
          const Vector3f &ka,
          const Vector3f &kd,
          const Vector3f &ks,
          bool mirror);
    
    Plane& operator=(const Plane &other);
    
    Vector3f getCenter();
    
    Vector3f getNormal(Vector3f point);
    
    pair<float, Vector3f> intersect(Ray &ray);
    
    Vector3f getKa();
    
    Vector3f getKd();
    
    Vector3f getKs();
    
    float getShine();
};

#endif /* Plane_hpp */
