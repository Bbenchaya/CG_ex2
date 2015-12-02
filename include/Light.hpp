//
//  Light.hpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 16/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#ifndef Light_hpp
#define Light_hpp

#include <math.h>
#include "Vector3f.h"

class Light {

private:
    Vector3f direction;
    Vector3f intensity;
//Spot Light
    Vector3f position;
    float light_cutoff;
    bool directional;

public:
    Light();
    //Spot_Light
    Light(const Vector3f &direction,
          const Vector3f &intensity,
          const Vector3f &position,
          float light_cutoff);
    //Reular Light
    Light(const Vector3f &direction,
          const Vector3f &intensity);
    
    Vector3f get_direction();
    
    Vector3f get_intensity();
    
    Vector3f get_position();
    
    bool is_spotlight();
    
    bool illuminates(Vector3f L);
};
#endif /* Light_hpp */
