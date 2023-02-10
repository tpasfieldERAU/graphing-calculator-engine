//
// Created by TJ on 1/12/2023.
//

#include "vars.h"

unsigned int xRes;
unsigned int yRes;
unsigned char shape;
unsigned char lineColor;
unsigned int num;
float * bounds;

void varsInit(unsigned int xR, unsigned int yR, unsigned char s, unsigned char c, unsigned int n, float b[4]){
    xRes = xR;
    yRes = yR;
    xRes += (xRes % 2 == 0);
    yRes += (yRes % 2 == 0);

    shape = s;
    lineColor = c;
    num = n;
    bounds = b;

    // Try putting this somewhere else?
    /*if (num > xRes){
        printf("Invalid number of points. Try again.");
        exit(1);
    }*/
}

void changeShape(unsigned char s){
    shape = s;
}

void changeColor(unsigned char c){
    lineColor = c;
}