//
//  Scene.hpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 16/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <GLUT/GLUT.h>
#include "Vector3f.h"
#include <vector>
#include "Camera.hpp"
#include "Light.hpp"
#include "Plane.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"

using namespace std;

class Scene {

private:
    Vector3f center; //screen center coordinates, this is also the image plane normal
    Vector3f upVector; //up vector coordinates
    float width;
    const unsigned int resolution_i;
    const unsigned int resolution_j;
    Vector3f color;
    
public:
    Scene();
    Scene(const Vector3f &center,
          const Vector3f &up,
          float width,
          unsigned int resolution_i,
          unsigned int resolution_j,
          const Vector3f &color);
    void castRays(Vector3f ****image,
                  const vector<Light> &lights,
                  const vector<Plane> &planes,
                  const vector<Sphere> &spheres);
};

#endif /* Scene_hpp */
