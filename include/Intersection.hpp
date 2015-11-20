//
//  Intersection.hpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 20/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#ifndef Intersection_hpp
#define Intersection_hpp

#include "Primitive.hpp"

class Intersection {
    
private:
    float min_distance;
    Primitive min_primitive;
    
public:
    Intersection();
    Intersection(float min_distance, const Primitive &min_primitive);
    Intersection& operator=(const Intersection &other);
    float getMinDistance();
    Primitive* getMinPrimitive();
    
};

#endif /* Intersection_hpp */
