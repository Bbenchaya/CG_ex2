#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "Parser.hpp"
#include "Scene.hpp"

using namespace std;
GLuint texture;
int width;
int height;

Vector3f* fisheye(Vector3f *source_image){
    // create the result data
    Vector3f *dstpixels = new Vector3f[width * height];
    // for each row
    for (int y = 0; y < height; y++) {
        // normalize y coordinate to -1 ... 1
        double ny = ((2.0 * y) / height) - 1.0;
        // pre calculate ny*ny
        double ny2 = powf(ny, 2);
        // for each column
        for (int x = 0; x < width; x++) {
            // normalize x coordinate to -1 ... 1
            double nx = ((2.0 * x) / width) - 1.0;
            // pre calculate nx*nx
            double nx2 = pow(nx, 2);
            // calculate distance from center (0,0)
            // this will include circle or ellipse shape portion
            // of the image, depending on image dimensions
            // you can experiment with images with different dimensions
            double r = sqrt(nx2 + ny2);
            // discard pixels outside from circle!
            if (0.0 <= r && r <= 1.0) {
                double nr = sqrt(1.0 - pow(r, 2));
                // new distance is between 0 ... 1
                nr = (r + (1.0 - nr)) / 2.0;
                // discard radius greater than 1.0
                if (nr <= 1.0) {
                    // calculate the angle for polar coordinates
                    double theta = atan2(ny,nx);
                    // calculate new x position with new distance in same angle
                    double nxn = nr * cos(theta);
                    double nyn = nr * sin(theta);
                    // map from -1 ... 1 to image coordinates
                    int x2 = (int)(((nxn + 1) * width) / 2.0);
                    // map from -1 ... 1 to image coordinates
                    int y2 = (int)(((nyn + 1) * height) / 2.0);
                    // find (x2,y2) position from source pixels
                    int srcpos = (int)(y2 * width + x2);
                    // make sure that position stays within arrays
//                    printf("i:%d, j:%d\n%f:%f:%f\n", y2, x2, source_image[srcpos][0], source_image[srcpos][1], source_image[srcpos][2]);
                    if (srcpos >= 0 & srcpos < width * height) {
                        // get new pixel (x2,y2) and put it to target array at (x,y)
                        dstpixels[y * width + x] = source_image[srcpos];
                    }
                }
            }
        }
    }
    //return result pixels
    return dstpixels;
}

GLfloat* transformImageToGL(Vector3f ***image, bool to_fish_eye){
    GLfloat *res = new GLfloat[height * width * 3];
    if (to_fish_eye) {
        Vector3f *fisheyed = new Vector3f[height * width];
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                fisheyed[i * width + j] = (*image)[i][j];
            }
        }
        fisheyed = fisheye(fisheyed);
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++) {
                res[(i * width + j) * 3] = fisheyed[i * width + j].p[0];
                res[(i * width + j) * 3 + 1] = fisheyed[i * width + j].p[1];
                res[(i * width + j) * 3 + 2] = fisheyed[i * width + j].p[2];
            }
        return res;
    }
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++) {
            res[(i * width + j) * 3] = ((*image)[i][j]).p[0];
            res[(i * width + j) * 3 + 1] = ((*image)[i][j]).p[1];
            res[(i * width + j) * 3 + 2] = ((*image)[i][j]).p[2];
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
    GLfloat *image_for_GL = transformImageToGL(image, true);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, height, width, 0, GL_RGB, GL_FLOAT, image_for_GL);

}

void mydisplay(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glBindTexture(GL_TEXTURE_2D, texture);
    glViewport(0, 0, height, width);
    glBegin(GL_QUADS);
    glTexCoord2f(0, 0); glVertex3f(-1.0, 1.0f, 1.0);
    glTexCoord2f(1, 0); glVertex3f(1.0, 1.0f, 1.0);
    glTexCoord2f(1, 1); glVertex3f(1.0, -1.0f, 1.0);
    glTexCoord2f(0, 1); glVertex3f(-1.0, -1.0f, 1.0);
    glEnd();
    glFlush();
}


int main(int argc, char **argv){
    vector<Light> lights;
    vector<Primitive*> primitives;
    Scene scene = Scene();
    Parser parser;
    parser.parse(lights, primitives, scene);
    height = scene.getHeight();
    width = scene.getWidth();
    Vector3f **image = new Vector3f*[height];
    for (int i = 0; i < height; i++) {
        image[i] = new Vector3f[width];
    }
    Cone* cone = new Cone(Vector3f(0, 0, -20), 0, 0.1, Vector3f(0.5, 0, 0.5), Vector3f(0.5, 0.5, 0.5), Vector3f(0.5, 0.5, 0.5), 20, false);
//    primitives.push_back(cone);
    scene.castRays(&image);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(height, width);
    glutCreateWindow("Ray casting");
    init(&image);
    glutDisplayFunc(mydisplay);
    glutMainLoop ();
    return 0;
}