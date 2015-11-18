//
//  Light.hpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 16/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#ifndef Light_hpp
#define Light_hpp

#include "Vector3f.h"

class Light{

private:
    Vector3f position;
    Vector3f color;
//Spot Light
    Vector3f spotlight;
    float light_cutoff;

public:
    //Spot_Light
    Light(const Vector3f &position,
          const Vector3f &color,
          const Vector3f &spotlight,
          float light_cutoff);
    //Reular Light
    Light(const Vector3f &position,
          const Vector3f &color,
          float light_cutoff);
    
};
#endif /* Light_hpp */
