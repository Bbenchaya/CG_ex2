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
#include "Vector3f.h"

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
    
    virtual Vector3f getCenter();
    
    virtual Vector3f getNormal();
    
};

#endif /* Plane_hpp */
