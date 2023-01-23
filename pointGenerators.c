//
// Created by TJ on 1/11/2023.
//

#include "pointGenerators.h"

void xPoints(
        double dx,
        double x,
        double * points,
        double f(double)
        ){

    for (unsigned int i = 0; i < num; i++){
        points[2*i] = x;
        points[2*i + 1] = f(x);
        x += dx;
    }
}