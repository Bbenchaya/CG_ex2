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

GLfloat* transformImageToGL(Vector3f*** image){
    GLfloat *res = new GLfloat[512 * 512 * 3];
    for (int i = 0; i < 512; i++)
        for (int j = 0; j < 512; j++) {
            res[(i * 512 + j) * 3] = ((*image)[i][j]).p[0];
            res[(i * 512 + j) * 3 + 1] = ((*image)[i][j]).p[1];
            res[(i * 512 + j) * 3 + 2] = ((*image)[i][j]).p[2];
//            res[(i * 512 + j) * 3] = 1;
//            res[(i * 512 + j) * 3 + 1] = 1;
//            res[(i * 512 + j) * 3 + 2] = 0;
         }
    return res;
}

void init(Vector3f ***image){
    glEnable(GL_TEXTURE_2D);
    glClearColor(0, 0, 0, 0);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    GLfloat *image_for_GL = transformImageToGL(image);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 512, 512, 0, GL_RGB, GL_FLOAT, image_for_GL);

}

void mydisplay(){
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glBindTexture(GL_TEXTURE_2D, texture);
    glViewport(0, 0, 512, 512);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(1.0, 1.0f, 1.0);
    glTexCoord2f(1, 0);
    glVertex3f(1.0, -1.0f, 1.0);
    glTexCoord2f(1, 1);
    glVertex3f(-1.0, -1.0f, 1.0);
    glTexCoord2f(0, 1);
    glVertex3f(-1.0, 1.0f, 1.0);
    glEnd();
    glFlush();
}


int main(int argc, char **argv){
    vector<Light> lights;
    vector<Primitive*> primitives;
    Scene scene = Scene();
    Parser parser;
    parser.parse(lights, primitives, scene);
    Vector3f **image = new Vector3f*[scene.getHeight()];
    for (int i = 0; i < scene.getHeight(); i++) {
        image[i] = new Vector3f[scene.getWidth()];
    }
    scene.castRays(&image);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(512, 512);
    glutCreateWindow("Ray casting");
    init(&image);
    glutDisplayFunc(mydisplay);
    glutMainLoop ();
    return 0;
}