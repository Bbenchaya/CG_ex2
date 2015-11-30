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
    Primitive *min_primitive;
    Vector3f intersectionPoint;
    
public:
    Intersection();
    Intersection(float min_distance, Primitive *min_primitive, Vector3f intersectionPoint);
    Intersection& operator=(const Intersection &other);
    float getMinDistance() const;
    Primitive* getMinPrimitive();
    Vector3f getIntersectionPoint() const;
};

#endif /* Intersection_hpp */
