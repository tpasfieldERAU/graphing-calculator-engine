//
// Created by TJ on 1/11/2023.
//

#include "pointGenerators.h"

void xPoints(
        float dx,
        float x,
        float * points,
        float f(float)
        ){

    for (unsigned int i = 0; i <= num; i++){
        points[2*i] = x;
        points[2*i + 1] = f(x);
        x += dx;
    }
}

void yPoints(
        float dy,
        float y,
        float * points,
        float f(float)
        ){
    for (unsigned int i = 0; i <= num; i++){
        points[2*i] = y;
        points[2*i+1] = f(y);
        y += dy;
    }
}

void polarPoints(
        float dtheta,
        float theta,
        float * points,
        float f(float)
        ){
    float r;
    for (unsigned int i = 0; i <= num; i++){
        r = f(theta);
        points[2*i] = cosf(theta) * r;
        points[2*i+1] = sinf(theta) * r;
        theta += dtheta;
    }
}