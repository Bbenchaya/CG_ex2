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
#include <vector>
#include "Camera.hpp"
#include "Intersection.hpp"
#include "Light.hpp"
#include "Plane.hpp"
#include "Pixel.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include "Vector3f.h"

using namespace std;

class Scene {

private:
    Vector3f center; //screen center coordinates, this is also the image plane normal
    Vector3f upVector; //up vector coordinates
    Vector3f rightVector;
    float width;
    unsigned int resolution_i;
    unsigned int resolution_j;
    Vector3f color;
    
public:
    Scene();
    Scene(const Vector3f &center,
          const Vector3f &up,
          float width,
          unsigned int resolution_i,
          unsigned int resolution_j,
          const Vector3f &color);
    Scene& operator=(const Scene &other);
    Ray constructRayThroughPixel(const Camera &camera, unsigned int i ,unsigned int j);
    Intersection findIntersection(const Ray &ray, const Scene &scene);
    Vector3f getColor(const Scene &scene, const Ray &ray, const Intersection &hit);
    void castRays(Vector3f ***image,
                  const vector<Light> &lights,
                  const vector<Plane> &planes,
                  const vector<Sphere> &spheres);
    unsigned int getWidth();
    unsigned int getHeight();
    
};

#endif /* Scene_hpp */
