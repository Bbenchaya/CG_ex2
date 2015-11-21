#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <fstream>
#include "Vector3f.h"
#include "Parser.hpp"
#include "Light.hpp"
#include "Scene.hpp"
#include "Sphere.hpp"

using namespace std;
GLuint texture;

void init(Vector3f ***image){
    glGenTextures(1, &texture);
    
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 512, 512, 0,GL_LUMINANCE, GL_UNSIGNED_BYTE, *image);
    
}

void mydisplay(){
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0f, 1.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0f, 1.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0f, 1.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0f, 1.0);
    glEnd();
}


int main(int argc, char **argv){
    vector<Light> lights;
    vector<Primitive> primitives;
    Scene scene = Scene();
    Parser parser;
    parser.parse(lights, primitives, scene);
    Vector3f **image = new Vector3f*[scene.getHeight()];
    for (int i = 0; i < scene.getHeight(); i++) {
        image[i] = new Vector3f[scene.getWidth()];
    }
    scene.castRays(&image);
    glutInit (&argc, argv) ;
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB) ;
    glutInitWindowSize ( 512,512) ;
    glutCreateWindow("Lighting") ;
    init(&image);
    glutDisplayFunc(mydisplay);
    glutMainLoop ();
}