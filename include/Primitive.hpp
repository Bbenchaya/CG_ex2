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

using namespace std;

class Primitive {

protected:
    const char type;
    
public:
    Primitive();
    Primitive(char type);
    Primitive& operator=(const Primitive &other);
    virtual pair<float, Vector3f> intersect(Ray &ray);
    const char instanceof();
};

#endif /* Primitive_hpp */
