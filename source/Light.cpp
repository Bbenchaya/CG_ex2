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
Light::Light(const Vector3f &position,
             const Vector3f &color,
             const Vector3f &spotlight,
             float light_cutoff){
    this->position = position;
    this->color = color;
    this->spotlight = spotlight;
    this->light_cutoff = light_cutoff;
    this->is_directional = true;
}

//Regular Light Constructor
Light::Light(const Vector3f &position,
             const Vector3f &color){
    this->position = position;
    this->color = color;
    this->is_directional = false;

};