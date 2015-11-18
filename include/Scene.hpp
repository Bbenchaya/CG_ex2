//
//  Scene.hpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 16/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

#include "Vector3f.h"

class Scene {

private:
    Vector3f center; //screen center coordinates, this is also the image plane normal
    Vector3f upVector; //up vector coordinates
    float width;
    float resolution_x;
    float resolution_y;
    Vector3f color;
    
public:
    Scene(const Vector3f &center,
          const Vector3f &up,
          float width,
          float resolution_x,
          float resolution_y,
          const Vector3f &color);
};

#endif /* Scene_hpp */
