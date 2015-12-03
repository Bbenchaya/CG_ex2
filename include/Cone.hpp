//
//  Cone.hpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 3/12/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#ifndef Cone_hpp
#define Cone_hpp

#include "Primitive.hpp"

class Cone : public Primitive{
    
private:
    Vector3f center;
    float z_min;
    float z_max;
    Vector3f ka;
    Vector3f kd;
    Vector3f ks;
    float shine;
    
public:
    Cone(const Vector3f &center,
         float z_min,
         float z_max,
         const Vector3f &ka,
         const Vector3f &ks,
         const Vector3f &kd,
         float shine);
    
    Cone& operator=(const Cone &other);
    
    pair<float, Vector3f> intersect(Vector3f p0, Vector3f V);
    
    Vector3f getNormal(Vector3f point);
    
    Vector3f getKa(Vector3f at_point);
    
    Vector3f getKd(Vector3f at_point);
    
    Vector3f getKs(Vector3f at_point);
    
    float getShine();
    
};

#endif /* Cone_hpp */
