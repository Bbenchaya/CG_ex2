//
//  Scene.hpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 16/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <cmath>
#include <cstddef>
#include <limits>
#include <string>
#include <vector>

#include "Camera.hpp"
#include "Intersection.hpp"
#include "Light.hpp"
#include "Plane.hpp"
#include "Primitive.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"

#include <GLUT/GLUT.h>

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
    vector<Primitive> primitives;
    vector<Light> lights;
    
public:
    Scene();
    
    Scene(const Vector3f &center,
          const Vector3f &up,
          float width,
          unsigned int resolution_i,
          unsigned int resolution_j,
          const Vector3f &color,
          vector<Primitive> &primitives,
          vector<Light> &lights);
    
    Scene& operator=(const Scene &other);
    
//    float intersect(Ray &ray, Primitive &primitive);
    
    Ray constructRayThroughPixel(Camera &camera, unsigned int i ,unsigned int j);
    
    Intersection findIntersection(Ray &ray);
    
    Vector3f getColor(const Ray &ray, const Intersection &hit);
    
    void castRays(Vector3f ***image);
    
    unsigned int getWidth();
    
    unsigned int getHeight();
    
};

#endif /* Scene_hpp */
