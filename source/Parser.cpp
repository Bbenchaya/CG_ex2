//
//  Parser.cpp
//  CG_EX2
//
//  Created by Asaf Chelouche on 16/11/15.
//  Copyright © 2015 Bbenchaya. All rights reserved.
//

#include "Parser.hpp"

void Parser::parse(){
    FILE *f;
    f = fopen(INPUT_FILE, "r");
    if (f == NULL){
        cout << "Error: opening input file" << endl;
        exit(1);
    }
    char next_line[MAX_LINE_LENGTH] = "";
    while (!feof(f)){
        fscanf(f, "%s", next_line);
        if (strncmp(next_line, "scene", 5) == 0){
            float upVectorX, upVectorY, upVectorZ, centerX, centerY, centerZ, width, Rx, Ry;
            float ambient[3]; // ambient[0] = R, ambient[1] = G, ambient[2] = B
            fscanf(f, " %f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", &upVectorX, &upVectorY, &upVectorZ, &centerX, &centerY, &centerZ, &width, &Rx, &Ry, ambient, ambient + 1, ambient + 2);
            printf("upVectorX:%f,upVectorY:%f,upVectorZ:%f,centerX:%f,centerY:%f,centerZ:%f,width:%f,Rx:%f,Ry:%f,ambientR:%f,ambientG:%f,ambientB:%f\n", upVectorX, upVectorY, upVectorZ, centerX, centerY, centerZ, width, Rx, Ry, ambient[0], ambient[1], ambient[2]);
            cout << "Scene created!" << endl;
        }
        if (strcmp(next_line, "spher") == 0){
            float x, y, z, radius, shine;
            float ka[3];
            float ks[3];
            float kd[3];
            fscanf(f, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", &x, &y, &z, &radius, ka, ka + 1, ka + 2, kd, kd + 1, kd + 2, ks, ks + 1, ks + 2, &shine);
            printf("x:%f,y:%f,z:%f,radius:%f,ka0:%f,ka1:%f,ka2:%f,kd0:%f,kd1:%f,kd2:%f,ks0:%f,ks1:%f,ks2:%f,shine:%f\n", x, y, z, radius, ka[0], ka[1], ka[2], kd[0], kd[1], kd[2], ks[0], ks[1], ks[2], shine);
            cout << "Sphere created!" << endl;
        }
        if (strncmp(next_line, "plane", 5) == 0){
            float normalX, normalY, normalZ, centerX, centerY, centerZ, width, length, shine;
            float ka[3];
            float ks[3];
            float kd[3];
            char mirror;
            fscanf(f, " %f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f %c", &normalX, &normalY, &normalZ, &centerX, &centerY, &centerZ, &width, &length, ka, ka + 1, ka + 2, kd, kd + 1, kd + 2, ks, ks + 1, ks + 2, &shine, &mirror);
            printf("normalX:%f,normalY:%f,normalZ:%f,centerX:%f,centerY:%f,centerZ:%f,width:%f,length:%f,ka0:%f,ka1:%f,ka2:%f,kd0:%f,kd1:%f,kd2:%f,ks0:%f,ks1:%f,ks2:%f,shine:%f,mirror:%c\n", normalX, normalY, normalZ, centerX, centerY, centerZ, width, length, ka[0], ka[1], ka[2], kd[0], kd[1], kd[2], ks[0], ks[1], ks[2], shine, mirror);
            cout << "Plane created!" << endl;
        }
        if (strncmp(next_line, "light", 5) == 0){
            cout << "Light created!" << endl;
        }
    }
    fclose(f);
}
