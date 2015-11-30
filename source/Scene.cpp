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
             const Vector3f &color, //ambient light color
             vector<Primitive*> *primitives,
             vector<Light> *lights){
    this->center = center;
    this->upVector = up;
    this->resolution_i = resolution_y;
    this->resolution_j = resolution_x;
    this->width = width;
    this->color = color;
    this->rightVector = Vector3f::crossProduct(center, up);
    this->rightVector.normalize();
    this->primitives = primitives;
    this->lights = lights;
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
    float scalar = width / resolution_j;
    Vector3f p = center;
    p = p - (i - floorf(resolution_i / 2)) * scalar * upVector + (j - floorf(resolution_j / 2)) * scalar * rightVector;
    p.normalize();
    return *(new Ray(p));
}

Intersection Scene::findIntersection(Ray &ray){
    float min_distance = INFINITY;
    Primitive *min_primitive = NULL;
    Vector3f intersectionPoint;
    for (vector<Primitive*>::iterator primitive = primitives->begin(); primitive != primitives->end(); primitive++) {
        pair<float, Vector3f> curr_distance = (*primitive)->intersect(ray);
//        printf("prim: %c, dist: %f\n", (*primitive)->instanceof(), curr_distance.first);
        if (curr_distance.first < min_distance) {
            min_primitive = (*primitive);
            min_distance = curr_distance.first;
            intersectionPoint = curr_distance.second;
        }
    }
    return *(new Intersection(min_distance, min_primitive, intersectionPoint));
}

Vector3f Scene::getColor(const Ray &ray, Intersection &hit, const Camera &camera){
    if (hit.getMinDistance() == INFINITY)
        return *(new Vector3f(0, 0, 0)); //the ray hits nothing, so paint the pixel in black
    Primitive *prim = hit.getMinPrimitive();
    Vector3f ka = prim->getKa();
    Vector3f kd = prim->getKd();
    Vector3f ks = prim->getKs();
    float nShine = prim->getShine();
    Vector3f N = prim->getNormal(hit.getIntersectionPoint());
    Vector3f V = hit.getIntersectionPoint() - camera.getPosition();
    V.normalize();
    Vector3f res = color * ka; //Should I sum the ambient of the scene and prim?
    for (vector<Light>::iterator light_iter = lights->begin(); light_iter != lights->end(); ++light_iter){
        Vector3f L = (*light_iter).get_direction() - hit.getIntersectionPoint();
        L.normalize();
//        if (light_iter->is_directional() && !light_iter->illuminates(L)) {
//            continue;
//        }

        bool ray_intersects_another_primitive = false;
//        for (vector<Primitive*>::iterator primitive = primitives->begin(); primitive != primitives->end(); ++primitive) {
//            if (*primitive != prim) {
//                Ray ray(L);
//                if ((*primitive)->intersect(ray).first != INFINITY) {
//                    ray_intersects_another_primitive = true;
//                    break;
//                }
//            }
//        }
//        if (!ray_intersects_another_primitive) {
            Vector3f R = hit.getIntersectionPoint() - (2 * N)*( Vector3f::dotProduct(hit.getIntersectionPoint(), N));
            R.normalize();
            res += (kd * Vector3f::dotProduct(N, L)) + (ks * powf(Vector3f::dotProduct(V , R), nShine));
//        }
    }
    res[0] = fminf(res[0], 1);
    res[1] = fminf(res[1], 1);
    res[2] = fminf(res[2], 1);
    return res;
}

//    Vector3f ray_direction = ray.getDirection();
//        
//    //cout<<"first "<<hit.getIntersectionPoint().p[0]<<" second "<<hit.getIntersectionPoint().p[1]<<" third "<<hit.getIntersectionPoint().p[2]<<endl;
//    Vector3f ray_normal = -primitiveNormal*(Vector3f::dotProduct(ray_direction, primitiveNormal));
//    Vector3f directional_vec = ray_direction + ray_normal;
//    Vector3f reflected_light = ray_normal + directional_vec;
//    
//        Vector3f curr_light = light_iter->get_position();
//
//        
        

//        float scalar = 0;
//        if (reflected_light[0] == 0){
//            if (curr_light[0] != 0) {
//                continue;
//            }
//            else{
//                scalar = (curr_light[0]/reflected_light[0]);
//            }
//        }
//        else if (reflected_light[1] == 0){
//            if (curr_light[1] != 0) {
//                continue;
//            }
//            else{
//                if(scalar != (curr_light[1]/reflected_light[1])){
//                    continue;
//                }
//            }
//        }
//        else if (reflected_light[2] == 0){
//            if (curr_light[2] != 0) {
//                continue;
//            }
//            else{
//                if(scalar != (curr_light[2]/reflected_light[2])){
//                    continue;
//                }
//                else{
//                    Ray reflected_ray = Ray(reflected_light);
//                    bool reach_light = true;
//                    for(vector<Primitive*>::iterator prim_iter = primitives->begin(); prim_iter != primitives->end() && reach_light; ++prim_iter){
//                        float distance = (*prim_iter)->intersect(reflected_ray).first;
//                        if((*prim_iter != &prim) && distance < INFINITY){
//                            reach_light = false;
//                        }
//                    }
//                    res += light_iter->get_color();
//                }
//            }
//        }
//    }



void Scene::castRays(Vector3f ***image){
    Vector3f cameraPosition(0, 0, 0);
    Camera camera = Camera(cameraPosition);
    for (unsigned int i = 0; i < 512; i++) {
        for (unsigned int j = 0; j < 512; j++) {
            Ray ray = constructRayThroughPixel(camera, i ,j);
            Intersection hit = findIntersection(ray);
            (*image)[i][j] = getColor(ray, hit, camera);
        }
    }
}

unsigned int Scene::getWidth(){
    return resolution_j;
}

unsigned int Scene::getHeight(){
    return resolution_i;
}