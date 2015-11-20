//
//  Scene.cpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 16/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#include "Scene.hpp"

Scene::Scene() {
    
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

float Scene::intersect(Ray &ray, Primitive &primitive){
    switch (primitive.instanceof()) {
        case 's':
            return 0;
        case 'p':
            float numerator = Vector3f::dotProduct((static_cast<Plane*>(&primitive))->getCenter(),
                                                   (static_cast<Plane*>(&primitive))->getNormal());
            float denominator = Vector3f::dotProduct((static_cast<Plane*>(&primitive))->getNormal(), ray.getDirection());
            float scalar =  numerator / denominator;
            Vector3f possibleIntersection = ray.getDirection() * scalar;
            return 0;
    }
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
    return *(new Ray(v));
}

Intersection Scene::findIntersection(Ray &ray){
    float min_distance = INFINITY;
    Primitive *min_primitive = NULL;
    for (vector<Primitive>::iterator primitive = primitives.begin(); primitive != primitives.end(); primitive++) {
        float curr_distance = intersect(ray, *primitive);
        if (curr_distance < min_distance) {
            min_primitive = &(*primitive);
            min_distance = curr_distance;
        }
    }
    return *(new Intersection(min_distance, *min_primitive));
}

Vector3f Scene::getColor(const Ray &ray, const Intersection &hit){
    if (hit.getMinDistance() == INFINITY)
        return *(new Vector3f(0, 0, 0)); //the ray hits nothing, so paint the pixel in black
    Vector3f *res = new Vector3f(0, 0, 0);
    /* construct a vector from the intersection point to each light source, and check if it reaches the light. if so, sum up the
        light's color values into *res. */
    return *(new Vector3f());
}

void Scene::castRays(Vector3f ***image){
    Vector3f cameraPosition(0, 0, 0);
    Camera camera = Camera(cameraPosition);
    for (unsigned int i = 0; i < getHeight(); i++) {
        for (unsigned int j = 0; j < getWidth(); j++) {
            Ray ray = constructRayThroughPixel(camera, i ,j);
            Intersection hit = findIntersection(ray);
            (*image)[i][j] = getColor(ray, hit);
        }
    }
}

unsigned int Scene::getWidth(){
    return resolution_j;
}

unsigned int Scene::getHeight(){
    return resolution_i;
}