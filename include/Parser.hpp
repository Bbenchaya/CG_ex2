//
//  Parser.hpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 16/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fstream>
#include <iostream>
#include <vector>

#include "Light.hpp"
#include "Plane.hpp"
#include "Primitive.hpp"
#include "Scene.hpp"
#include "Sphere.hpp"

#include "Vector3f.h"

#define INPUT_FILE "/Users/bbenchaya/Documents/Xcode/CG_EX2/source/init_simple.txt"
//#define INPUT_FILE "/Users/asafchelouche/programming/CG_ex2/source/init_simple.txt"
#define MAX_LINE_LENGTH 6

using namespace std;

class Parser {

public:
    void parse(vector<Light> &lights,
               vector<Primitive> &primitives,
               Scene &scenes);
    
};

#endif /* Parser_hpp */
