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
#define INPUT_FILE "/Users/asafchelouche/programming/CG_ex2/source/init1.txt"
#define MAX_LINE_LENGTH 500

using namespace std;

class Parser {
private:

public:
    
    void parse(vector<Plane> plane_Vec, vector<Light> light_vec, vector<Sphere> sphere_vec, vector<Scene> scene_vec);
};

#endif /* Parser_hpp */
