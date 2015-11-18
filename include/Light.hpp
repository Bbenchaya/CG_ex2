//
//  Light.hpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 16/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#ifndef Light_hpp
#define Light_hpp

#include <stdio.h>
class Light{

private:
float light_x;
float light_y;
float light_z;
float light_intensity_R;
float light_intensity_G;
float light_intensity_B;
//Spot Light
float spotlight_x;
float spotlight_y;
float spotlight_z;
float light_cutoff;

public:
    //Spot_Light
    Light(
        float light_x,
        float light_y,
        float light_z,
        float light_intensity_R,
        float light_intensity_G,
        float light_intensity_B,
        float spotlight_x,
        float spotlight_y,
        float spotlight_z,
        float light_cutoff);
    //Reular Light
    Light(
        float light_x,
        float light_y,
        float light_z,
        float light_intensity_R,
        float light_intensity_G,
        float light_intensity_B,
        float light_cutoff);
    
};
#endif /* Light_hpp */
