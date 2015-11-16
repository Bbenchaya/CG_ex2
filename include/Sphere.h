//
//  Sphere.h
//  CG_EX2
//
//  Created by Asaf Chelouche on 16/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#ifndef Sphere_h
#define Sphere_h

class Sphere {
    
private:
    float x;
    float y;
    float z;
    float radius;
    float ka[3];
    float kd[3];
    float ks[3];
    float shine;
    
public:
    Sphere(float x, float y, float z, float radius, float *ka, float *kd, float *ks, float shine);
};

#endif /* Sphere_h */
