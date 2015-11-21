//
//  Primitive.hpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 20/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#ifndef Primitive_hpp
#define Primitive_hpp

#include "Ray.hpp"

class Primitive {

protected:
    const char type;
    
public:
    Primitive();
    Primitive(char type);
    Primitive& operator=(const Primitive &other);
    virtual float intersect(Ray &ray);
    const char instanceof();
};

#endif /* Primitive_hpp */
