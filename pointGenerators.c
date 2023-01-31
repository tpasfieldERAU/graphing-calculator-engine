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

    for (unsigned int i = 0; i < num; i++){
        points[2*i] = x;
        points[2*i + 1] = f(x);
        x += dx;
    }
}