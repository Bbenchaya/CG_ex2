//
//  Triangle.hpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 29/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#ifndef Triangle_hpp
#define Triangle_hpp

#include <stdlib.h>

#include "Vector3f.h"

class Triangle{

private:
    Vector3f p1, p2, p3;

public:
    Triangle(Vector3f p1, Vector3f p2, Vector3f p3);
    
    bool intersect(Vector3f point);
};

#endif /* Triangle_hpp */
