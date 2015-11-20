//
//  Scene.cpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 16/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#include "Scene.hpp"

Scene::Scene() :    resolution_j(0),
                    resolution_i(0){
    
}

Scene::Scene(const Vector3f &center,
             const Vector3f &up,
             float width,
             unsigned int resolution_x,
             unsigned int resolution_y,
             const Vector3f &color) :   resolution_j(resolution_x),
                                        resolution_i(resolution_y){
    this->center = center;
    this->upVector = upVector;
    this->width = width;
    this->color = color;
}

void Scene::castRays(Vector3f ****image,
                     const vector<Light> &lights,
                     const vector<Plane> &planes,
                     const vector<Sphere> &spheres){
    **image =  new Vector3f[5][5];
    Camera camera = Camera();
    for (unsigned int i = 0; i < resolution_i; i++){
        for (unsigned int j = 0; j < resolution_j; j++) {
            Ray ray = constructRayThroughPixel(camera, i ,j);
            Intersection hit = findIntersection(ray, this);
            image[i][j] = getColor(this, ray, hit);
        }
    }
}