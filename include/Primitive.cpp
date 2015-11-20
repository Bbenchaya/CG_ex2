//
//  Primitive.cpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 20/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#include "Primitive.hpp"

Primitive::Primitive() : type('\0'){
    
}

Primitive::Primitive(char type) : type(type){
    
}

Primitive& Primitive::operator=(const Primitive &other){
    return *this;
}

const char Primitive::instanceof(){
    return type;
}