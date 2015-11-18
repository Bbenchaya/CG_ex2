//
//  Light.cpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 16/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#include "Light.hpp"
//SpotLight Constructor
Light::Light(float light_x, float light_y, float light_z,float light_intensity_R,float light_intensity_G, float light_intensity_B, float spotlight_x, float spotlight_y, float spotlight_z, float light_cutoff){
    this->light_x = light_x;
    this->light_y = light_y;
    this->light_z = light_z;
    this->light_intensity_R = light_intensity_R;
    this->light_intensity_G = light_intensity_G;
    this->light_intensity_B = light_intensity_B;
    this->spotlight_x = spotlight_x;
    this->spotlight_y = spotlight_y;
    this->spotlight_z = spotlight_z;
    this->light_cutoff = light_cutoff;
}

//Regular Light Constructor
Light::Light(float light_x, float light_y, float light_z,float light_intensity_R,float light_intensity_G, float light_intensity_B, float light_cutoff){
    this->light_x = light_x;
    this->light_y = light_y;
    this->light_z = light_z;
    this->light_intensity_R = light_intensity_R;
    this->light_intensity_G = light_intensity_G;
    this->light_intensity_B = light_intensity_B;
    this->light_cutoff = light_cutoff;

};