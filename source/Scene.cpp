//
//  Scene.cpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 16/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#include "Scene.hpp"
Scene::Scene(float pc_x, float pc_y, float pc_z, float up_x, float up_y, float up_z, float width, float resolution_x, float resolution_y, float ambient_R, float ambient_G, float ambient_B){
    this->pc_x = pc_x;
    this->pc_y = pc_y;
    this->pc_z = pc_z;
    this->up_x = up_x;
    this->up_y = up_y;
    this->up_z = up_z;
    this->width = width;
    this->resolution_x = resolution_x;
    this->resolution_y = resolution_y;
    this->ambient_R = ambient_R;
    this->ambient_G = ambient_G;
    this->ambient_B = ambient_B;
}