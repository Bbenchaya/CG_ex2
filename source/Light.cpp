//
//  Light.cpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 16/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#include "Light.hpp"

Light::Light(){
    
}

//SpotLight Constructor
Light::Light(const Vector3f &direction,
             const Vector3f &intensity,
             const Vector3f &position,
             float light_cutoff){
    this->direction = direction;
    this->intensity = intensity;
    this->position = position;
    this->light_cutoff = light_cutoff;
    this->is_directional = false;
}

//Regular Light Constructor
Light::Light(const Vector3f &direction,
             const Vector3f &intensity){
    this->direction = direction;
    this->intensity = intensity;
    this->is_directional = true;
}

Vector3f Light::get_direction(){
    return this->direction;
}

Vector3f Light::get_intensity(){
    return this->intensity;
}

