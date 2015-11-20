//
//  Camera.hpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 18/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include "Vector3f.h"

class Camera {

private:
    Vector3f position;
    
public:
    Camera();
    Camera(Vector3f &position);
    Vector3f getPosition();
};

#endif /* Camera_hpp */
