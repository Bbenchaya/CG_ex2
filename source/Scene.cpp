//
//  Scene.cpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 16/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#include "Scene.hpp"

Scene::Scene(){
    
}

Scene::Scene(const Vector3f &center,
             const Vector3f &up,
             float width,
             unsigned int resolution_x,
             unsigned int resolution_y,
             const Vector3f &color){
    this->center = center;
    this->upVector = upVector;
    this->resolution_i = resolution_y;
    this->resolution_j = resolution_x;
    this->width = width;
    this->color = color;
    this->rightVector = Vector3f::crossProduct(center, up);
}

Scene& Scene::operator=(const Scene &other){
    if (this == &other)
        return *this;
    this->center = other.center;
    this->upVector = other.upVector;
    this->resolution_i = other.resolution_i;
    this->resolution_j = other.resolution_j;
    this->width = other.width;
    this->color = other.color;
    this->rightVector = Vector3f::crossProduct(other.center, other.upVector);
    return *this;
}

Ray Scene::constructRayThroughPixel(const Camera &camera, unsigned int i ,unsigned int j){
    return *(new Ray());
}

Intersection Scene::findIntersection(const Ray &ray, const Scene &scene){
    return *(new Intersection());
}

Vector3f Scene::getColor(const Scene &scene, const Ray &ray, const Intersection &hit){
    return *(new Vector3f());
}

void Scene::castRays(Vector3f ***image,
                     const vector<Light> &lights,
                     const vector<Plane> &planes,
                     const vector<Sphere> &spheres){
    Camera camera = Camera();
    for (unsigned int i = 0; i < resolution_i; i++) {
        for (unsigned int j = 0; j < 5; j++) {
            Ray ray = constructRayThroughPixel(camera, i ,j);
            Intersection hit = findIntersection(ray, *this);
            (*image)[i][j] = getColor(*this, ray, hit);
        }
    }
}

unsigned int Scene::getWidth(){
    return resolution_j;
}

unsigned int Scene::getHeight(){
    return resolution_i;
}