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
             const Vector3f &ambient_color,
             vector<Primitive*> *primitives,
             vector<Light> *lights){
    this->center = center;
    this->upVector = up;
    this->resolution_i = resolution_y;
    this->resolution_j = resolution_x;
    this->width = width;
    this->ambient_color = ambient_color;
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
    this->ambient_color = other.ambient_color;
    this->rightVector = other.rightVector;
    this->primitives = other.primitives;
    this->lights = other.lights;
    return *this;
}

Ray Scene::constructRayThroughPixel(Camera &camera, unsigned int i ,unsigned int j){
    float scalar = width / resolution_j;
    Vector3f p = center;
    p = p - (i - floorf(resolution_i / 2)) * scalar * upVector
          + (j - floorf(resolution_j / 2)) * scalar * rightVector;
    p.normalize();
    return *(new Ray(p));
}

Intersection Scene::findIntersection(Ray &ray){
    float min_distance = INFINITY;
    Primitive *min_primitive = NULL;
    Vector3f intersectionPoint;
    for (vector<Primitive*>::iterator primitive = primitives->begin(); primitive != primitives->end(); primitive++) {
        pair<float, Vector3f> curr_distance = (*primitive)->intersect(Vector3f(0, 0, 0) ,ray.getDirection());
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
        return Vector3f(0, 0, 0); //the ray hits nothing, so paint the pixel in black
    Primitive *prim = hit.getMinPrimitive();
    Vector3f at_point = hit.getIntersectionPoint();
    Vector3f ka = prim->getKa(at_point);
    Vector3f kd = prim->getKd(at_point);
    Vector3f ks = prim->getKs(at_point);
    float nShine = prim->getShine();
    Vector3f N = prim->getNormal(hit.getIntersectionPoint());
    Vector3f V = hit.getIntersectionPoint() - camera.getPosition();
    V.normalize();
    Vector3f res = ambient_color * ka;
    for (vector<Light>::iterator light = lights->begin(); light != lights->end(); light++){
        Vector3f L;
        if (light->is_spotlight()) {
            L = (*light).get_position() - hit.getIntersectionPoint();
            if (!light->illuminates(L)){
                continue;
            }
        }
        else
            L = light->get_direction() * -1000000; // arbitrary position for a directional light at pseudo-infinity
        L.normalize();
        bool ray_intersects_another_primitive = false;
        for (vector<Primitive*>::iterator primitive = primitives->begin(); primitive != primitives->end(); ++primitive) {
            if (*primitive != prim) {
                if ((*primitive)->intersect(hit.getIntersectionPoint(), L).first != INFINITY) {
                    ray_intersects_another_primitive = true;
                    break;
                }
            }
        }
        if (!ray_intersects_another_primitive) {
            Vector3f R = -L + N * 2 * (Vector3f::dotProduct(L, N));
            R.normalize();
            Vector3f V = -hit.getIntersectionPoint();
            V.normalize();
            float angleCos = fmaxf(0, Vector3f::dotProduct(V, R));
            res += (kd * Vector3f::dotProduct(N, L)) * light->get_intensity() + (ks * powf(angleCos, nShine) * light->get_intensity());
        }
    }
    res[0] = fminf(res[0], 1);
    res[1] = fminf(res[1], 1);
    res[2] = fminf(res[2], 1);
    return res;
}

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