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
             vector<Primitive*> *primitives,
             vector<Light> *lights){
    this->center = center;
    this->upVector = upVector;
    this->resolution_i = resolution_y;
    this->resolution_j = resolution_x;
    this->width = width;
    this->color = color;
    this->rightVector = Vector3f::crossProduct(center, up);
    this->primitives = primitives;
    this->lights = lights;
    this->center.normalize();
    this->upVector.normalize();
}

Scene& Scene::operator=(const Scene &other){
    if (this == &other)
        return *this;
    this->center = other.center;
    this->upVector = other.upVector;
    this->width = other.width;
    this->resolution_i = other.resolution_i;
    this->resolution_j = other.resolution_j;
    this->color = other.color;
    this->rightVector = other.rightVector;
    this->primitives = other.primitives;
    this->lights = other.lights;
    return *this;
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
    Vector3f intersectionPoint;
    for (vector<Primitive*>::iterator primitive = primitives->begin(); primitive != primitives->end(); primitive++) {
        pair<float, Vector3f> curr_distance = (*primitive)->intersect(ray);
        printf("--------- curr distance is: %f ---------", curr_distance.first);
        if (curr_distance.first < min_distance) {
            min_primitive = (*primitive);
            min_distance = curr_distance.first;
            intersectionPoint = curr_distance.second;
        }
    }
    return *(new Intersection(min_distance, *min_primitive, intersectionPoint));
}

Vector3f Scene::getColor(const Ray &ray, const Intersection &hit){
    if (hit.getMinDistance() == INFINITY)
        return *(new Vector3f(0, 0, 0)); //the ray hits nothing, so paint the pixel in black
    Vector3f res = Vector3f(0, 0, 0);
    Primitive prim = hit.getMinPrimitive();
    Vector3f ray_direction = ray.getDirection();
    Vector3f primitiveNormal = prim.getNormal(hit.getIntersectionPoint());
    Vector3f ray_normal = -primitiveNormal*(Vector3f::dotProduct(ray_direction, primitiveNormal));
    Vector3f directional_vec = ray_direction+ray_normal;
    Vector3f reflected_light = ray_normal+directional_vec;
    for (vector<Light>::iterator light_iter = lights->begin(); light_iter != lights->end(); ++light_iter){
        Vector3f curr_light = light_iter->get_position();
        float scalar = 0;
        if (reflected_light[0] == 0){
            if (curr_light[0] != 0) {
                continue;
            }
            else{
                scalar = (curr_light[0]/reflected_light[0]);
            }
        }
        else if (reflected_light[1] == 0){
            if (curr_light[1] != 0) {
                continue;
            }
            else{
                if(scalar != (curr_light[1]/reflected_light[1])){
                    continue;
                }
            }
        }
        else if (reflected_light[2] == 0){
            if (curr_light[2] != 0) {
                continue;
            }
            else{
                if(scalar != (curr_light[2]/reflected_light[2])){
                    continue;
                }
                else{
                    Ray reflected_ray = Ray(reflected_light);
                    bool reach_light = true;
                    for(vector<Primitive*>::iterator prim_iter = primitives->begin(); prim_iter != primitives->end() && reach_light; ++prim_iter){
                        float distance = (*prim_iter)->intersect(reflected_ray).first;
                        if((*prim_iter != &prim) && distance < INFINITY){
                            reach_light = false;
                        }
                    }
                    res += light_iter->get_color();
                }
            }
        }
    }
    return res;
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