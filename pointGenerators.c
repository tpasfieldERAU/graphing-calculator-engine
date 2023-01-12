//
// Created by TJ on 1/11/2023.
//

#include "pointGenerators.h"

void xPoints(
        unsigned int xRes,
        unsigned int num,
        double dx,
        double x,
        double * points,
        double f(double)
        ){

    unsigned int interval = xRes / num;

    for (unsigned int i = 0; i <= num; i++){
        points[2*i] = x;
        points[2*i + 1] = f(x);
        x += dx;
    }
}