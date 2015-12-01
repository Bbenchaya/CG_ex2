//
//  Sphere.hpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 16/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#ifndef Sphere_hpp
#define Sphere_hpp

#include "Primitive.hpp"

class Sphere : public Primitive{
    
private:
    Vector3f center;
    float radius;
    Vector3f ka;
    Vector3f kd;
    Vector3f ks;
    float shine;
    
public:
    Sphere(const Vector3f &center,
           float radius,
           const Vector3f &ka,
           const Vector3f &ks,
           const Vector3f &kd,
           float shine);
    
    Sphere& operator=(const Sphere &other);
    
    pair<float, Vector3f> intersect(Vector3f p0, Vector3f V);

    Vector3f getNormal(Vector3f point);
    
    Vector3f getKa(Vector3f at_point);
    
    Vector3f getKd(Vector3f at_point);
    
    Vector3f getKs(Vector3f at_point);
    
    float getShine();

};

#endif /* Sphere_hpp */
