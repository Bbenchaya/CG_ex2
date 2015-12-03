//
//  Parser.cpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 16/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#include "Parser.hpp"

void Parser::parse(vector<Light> &lights,
                   vector<Primitive*> &primitives,
                   Scene &scene){
    FILE *file;
    file = fopen(INPUT_FILE, "r");
    if (file == NULL){
        cout << "Error: opening input file" << endl;
        exit(1);
    }
    char next_line[MAX_LINE_LENGTH] = "";
    while (!feof(file)){
        int successful_read;
        // the if statement prevents parsing the last line twice, causing the last primitive to have 2 instances
        if((successful_read = fscanf(file, "%s", next_line)) > 0){
            if (strncmp(next_line, "scene", 5) == 0){
                float upVectorX, upVectorY, upVectorZ, centerX, centerY, centerZ, width;
                unsigned int Rx, Ry;
                float ambient[3]; // ambient[0] = R, ambient[1] = G, ambient[2] = B
                fscanf(file, " %f,%f,%f,%f,%f,%f,%f,%u,%u,%f,%f,%f", &upVectorX, &upVectorY, &upVectorZ, &centerX, &centerY, &centerZ, &width, &Rx, &Ry, ambient, ambient + 1, ambient + 2);
                scene = Scene(Vector3f(upVectorX, upVectorY, upVectorZ),
                            Vector3f(centerX, centerY, centerZ),
                            width,
                            Ry,
                            Rx,
                            Vector3f(ambient),
                            &primitives,
                            &lights);
                            cout << "Scene created!" << endl;
            }
            if (strcmp(next_line, "spher") == 0){
                float x, y, z, radius, shine;
                float ka[3];
                float ks[3];
                float kd[3];
                char mirror = '\0';
                bool isMirror = false;
                fscanf(file, " %f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%c", &x, &y, &z, &radius, ka, ka + 1, ka + 2, kd, kd + 1, kd + 2, ks, ks + 1, ks + 2, &shine, &mirror);
                if (mirror == 'M') {
                    isMirror = true;
                }
                Sphere *spher = new Sphere(Vector3f(x, y, z),
                             radius,
                             Vector3f(ka),
                             Vector3f(ks),
                             Vector3f(kd),
                             shine,
                             isMirror);
                primitives.push_back(spher);
                cout << "Sphere created!" << endl;
            }
            if (strncmp(next_line, "plane", 5) == 0){
                float normalX, normalY, normalZ, centerX, centerY, centerZ, width, length, shine;
                float ka[3];
                float ks[3];
                float kd[3];
                char mirror = '\0';
                bool isMirror = false;
                fscanf(file, " %f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f %c", &normalX, &normalY, &normalZ, &centerX, &centerY, &centerZ, &width, &length, ka, ka + 1, ka + 2, kd, kd + 1, kd + 2, ks, ks + 1, ks + 2, &shine, &mirror);
                if (mirror == 'M') {
                    isMirror = true;
                }
                Plane *plane = new Plane(Vector3f(normalX, normalY, normalZ),
                            Vector3f(centerX, centerY, centerZ),
                            width,
                            length,
                            shine,
                            Vector3f(ka),
                            Vector3f(kd),
                            Vector3f(ks),
                            isMirror);
                primitives.push_back(plane);
                cout << "Plane created!" << endl;
            }
            if (strncmp(next_line, "light", 5) == 0){
                float dirX, dirY, dirZ;
                float intensity[3];
                float positionX, positionY, positionZ, angle;
                int params = fscanf(file, " %f,%f,%f,%f,%f,%f,%f", &dirX, &dirY, &dirZ, intensity, intensity + 1, intensity + 2, &positionX);
                if (params < 7){
                    Light light(Vector3f(dirX, dirY, dirZ),
                                Vector3f(intensity));
                    lights.push_back(light);
                }
                else {
                    fscanf(file, ",%f,%f,%f", &positionY, &positionZ, &angle);
                    Light spot_light(Vector3f(dirX, dirY, dirZ),
                                     Vector3f(intensity),
                                     Vector3f(positionX, positionY, positionZ),
                                     angle);
                    lights.push_back(spot_light);
                }
                cout << "Light created!" << endl;
            }
        }
    }
    fclose(file);
}
