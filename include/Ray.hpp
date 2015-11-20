//
//  Ray.hpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 18/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#ifndef Ray_hpp
#define Ray_hpp

#include "Vector3f.h"

class Ray {
private:
    Vector3f direction;
    
public:
    Ray();
    Ray(Vector3f &direction);
    Ray& operator=(const Ray &other);
    Vector3f getDirection();
};

#endif /* Ray_hpp */
