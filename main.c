//
// Created by TJ on 1/11/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "outputs.h"
#include "pointGenerators.h"
#include "plotters.h"
#include "vars.h"

// Placeholder function to plot, look into lambdas and things too
float userFunc(float x){
    float ans = 1.0f/x - floorf(1.0f/x);
    return ans;
}

float fx(float T){
    float ans = cosf(9.0f * T) - powf(cosf(200.0f*T), 3);
    return ans;
}

float fy(float T){
    float ans = sinf(100.0f*T)-powf(sinf(9.0f*T), 4);
    return ans;
}

void printPoints(float * points){
    for (int i = 0; i <= num; i++){
        printf("%f\t%f\n", points[2*i], points[2*i + 1]);
    }
}

int main(){
    float b[4] = {-5.0f, 5.0f, -1.0f, 1.0f};
    varsInit(720, 720, 1, 1, 360, b);
    outputInit();

    float dx = (float)(bounds[1] - bounds[0]) / (float) num;
    //float dtheta = 2.0f * M_PI / 60.0f;
    //float dT = 0.0001f;


    // Consider moving this?
    // Otherwise, it allows easy use of keeping data in an array format, which could be good
    //  for table view and other processing
    float *points = NULL;
    points = (float *) calloc((num+1) * 2, sizeof points);

    xPoints(dx, bounds[0], points, userFunc);

    //polarPoints(dtheta, 0.0f, points, polarFunc);

    //parametricPoints(dT, -25.0f, points, fx, fy);
    plot(points);

    output("./point.ppm", 0);
    outputCleanup();
    return 0;
}