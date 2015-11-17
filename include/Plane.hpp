//
//  Plane.hpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 16/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#ifndef Plane_hpp
#define Plane_hpp

class Plane {
    
private:
    float normalX;
    float normalY;
    float normalZ;
    float centerX;
    float centerY;
    float centerZ;
    float width;
    float length;
    float shine;
    float ka[3];
    float ks[3];
    float kd[3];
    bool mirror;
    
public:
    Plane(float normalX, float normalY, float normalZ, float centerX, float centerY, float centerZ, float width, float length, float shine, float *ka, float *ks, float *kd, bool mirror);
    
};

#endif /* Plane_hpp */
