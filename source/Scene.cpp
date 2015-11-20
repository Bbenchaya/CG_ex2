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
             const Vector3f &color,
             vector<Primitive> &primitives,
             vector<Light> &lights) :   primitives(NULL),
                                        lights(NULL){
    this->center = center;
    this->upVector = upVector;
    this->resolution_i = resolution_y;
    this->resolution_j = resolution_x;
    this->width = width;
    this->color = color;
    this->rightVector = Vector3f::crossProduct(center, up);
    this->primitives = primitives;
    this->lights = lights;
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

float Scene::intersect(const Ray &ray, Primitive *primitive){
    return 0;
}

Ray Scene::constructRayThroughPixel(Camera &camera, unsigned int i ,unsigned int j){
    float scalar = width / getWidth();
    Vector3f v;
    if (i < getWidth() / 2) {
        float scalar_left = -scalar * (getWidth() - i);
        Vector3f left_addition = rightVector;
        left_addition *= scalar_left;
        if (j < getWidth() / 2) {
            float scalar_up = scalar * (getWidth() - j);
            Vector3f up_addition = upVector;
            up_addition *= scalar_up;
            up_addition += left_addition;
            v = center + up_addition;
            v.normalize();
        }
        else {
            float scalar_down = -scalar * (getWidth() - j);
            Vector3f down_addition = upVector;
            down_addition *= scalar_down;
            down_addition += left_addition;
            v = center + down_addition;
            v.normalize();
        }
    }
    else {
        float scalar_right = scalar * (getWidth() - i);
        Vector3f right_addition = rightVector;
        right_addition *= scalar_right;
        if (j < getWidth() / 2) {
            float scalar_up = scalar * (getWidth() - j);
            Vector3f up_addition = upVector;
            up_addition *= scalar_up;
            up_addition += right_addition;
            v = center + up_addition;
            v.normalize();
        }
        else {
            float scalar_down = -scalar * (getWidth() - j);
            Vector3f down_addition = upVector;
            down_addition *= scalar_down;
            down_addition += right_addition;
            v = center + down_addition;
            v.normalize();
        }
    }
    return *(new Ray());
}

Intersection Scene::findIntersection(const Ray &ray, const Scene &scene){
    float min_distance = INFINITY;
    Primitive *min_primitive = NULL;
    for (vector<Primitive>::iterator prim_iter = primitives.begin(); prim_iter != primitives.end(); prim_iter++) {
        float curr_distance = intersect(ray, &(*prim_iter));
        if (curr_distance < min_distance) {
            min_primitive = &*prim_iter;
            min_distance = curr_distance;
        }
    }
    return *(new Intersection(min_distance, *min_primitive));
}

Vector3f Scene::getColor(const Scene &scene, const Ray &ray, const Intersection &hit){
    return *(new Vector3f());
}

void Scene::castRays(Vector3f ***image,
                     const vector<Light> &lights,
                     const vector<Primitive> &primitives){
    Vector3f cameraPosition(0, 0, 0);
    Camera camera = Camera(cameraPosition);
    for (unsigned int i = 0; i < getHeight(); i++) {
        for (unsigned int j = 0; j < getWidth(); j++) {
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