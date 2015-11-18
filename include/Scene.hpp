//
//  Scene.hpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 16/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <stdio.h>

class Scene{

private:
    float pc_x;
    float pc_y;
    float pc_z; //screen center coordinates, this is also the image plane normal
    float up_x;
    float up_y;
    float up_z; //up vector coordinates
    float width;
    float resolution_x;
    float resolution_y;
    float ambient_R;
    float ambient_G;
    float ambient_B;
    
public:
    Scene(float pc_x,
          float pc_y,
          float pc_z,
          float up_x,
          float up_y,
          float up_z,
          float width,
          float resolution_x,
          float resolution_y,
          float ambient_R,
          float ambient_G,
          float ambient_B);
};

#endif /* Scene_hpp */
