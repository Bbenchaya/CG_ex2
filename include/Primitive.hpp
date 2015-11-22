//
//  Primitive.hpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 20/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#ifndef Primitive_hpp
#define Primitive_hpp

#include <iostream>
#include <utility>

#include "Ray.hpp"

#include "Vector3f.h"

using namespace std;

class Primitive {

protected:
    const char type;
    
public:
    Primitive();
    Primitive(char type);
    virtual Primitive& operator=(const Primitive &other);
    virtual bool operator!=(const Primitive &other);
    virtual pair<float, Vector3f> intersect(Ray &ray);
    const char instanceof();
    virtual Vector3f getNormal(Vector3f point);
};

#endif /* Primitive_hpp */
