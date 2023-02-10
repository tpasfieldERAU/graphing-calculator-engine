//
// Created by TJ on 1/11/2023.
//

#ifndef GRAPHING_CALCULATOR_ENGINE_POINTGENERATORS_H
#define GRAPHING_CALCULATOR_ENGINE_POINTGENERATORS_H

#endif //GRAPHING_CALCULATOR_ENGINE_POINTGENERATORS_H

#include "vars.h"
#include <math.h>

void xPoints(
        float dx,
        float x,
        float * points,
        float f(float)
        );

void yPoints(
        float dy,
        float y,
        float * points,
        float f(float)
        );

void polarPoints(
        float dtheta,
        float theta,
        float * points,
        float f(float)
        );

void parametricPoints(
        float dT,
        float T,
        float * points,
        float fx(float),
        float fy(float)
        );