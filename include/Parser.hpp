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
#include <iostream>
#include <fstream>
#include "Vector3f.h"
#include <vector>
#include "Light.hpp"
#include "Scene.hpp"
#include "Plane.hpp"
#include "Sphere.hpp"

//#define INPUT_FILE "/Users/bbenchaya/Documents/Xcode/CG_EX2/source/init1.txt"
#define INPUT_FILE "/Users/asafchelouche/programming/CG_ex2/source/init_simple.txt"
#define MAX_LINE_LENGTH 6

using namespace std;

class Parser {
private:

public:
    void parse(vector<Plane> &planes,
               vector<Light> &lights,
               vector<Sphere> &spheres,
               vector<Scene> &scenes);
    
};

#endif /* Parser_hpp */
