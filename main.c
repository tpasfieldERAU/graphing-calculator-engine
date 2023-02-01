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
    //float ans = sqrtf(x) * sinf(8 * x);
    float ans = sinf(x) + 2.0f*cosf(x/3.0f) + sinf(2.0f*x);
    return ans;
}

float func1(float x){
    float ans = sinf(x);
    return ans;
}

float func2(float x){
    float ans = 2.0f * cosf(x / 3.0f);
    return ans;
}

float func3(float x){
    float ans = sinf(2.0f * x);
    return ans;
}

void printPoints(float * points){
    for (int i = 0; i <= num; i++){
        printf("%f\t%f\n", points[2*i], points[2*i + 1]);
    }
}

int main(){
    float b[4] = {-10.0f, 10.0f, -4.0f, 4.0f};
    varsInit(480, 360, 1, 6, 60, b);
    outputInit();

    float dx = (float)(bounds[1] - bounds[0]) / (float) num;
    //printf("%f", dx);


    // Consider moving this?
    // Otherwise, it allows easy use of keeping data in an array format, which could be good
    //  for table view and other processing
    float *points = NULL;
    points = (float *) calloc((num+1) * 2, sizeof points);

    xPoints(dx, bounds[0], points, userFunc);
    // PLOT FUNCTIONS ARE PUT HERE
    plot(points);

    changeColor(1);
    float *points1 = NULL;
    points1 = (float *) calloc((num+1) * 2, sizeof points1);
    xPoints(dx, bounds[0], points1, func1);
    plot(points1);

    changeColor(2);
    float *points2 = NULL;
    points2 = (float *) calloc((num+1) * 2, sizeof points1);
    xPoints(dx, bounds[0], points2, func2);
    plot(points2);

    changeColor(3);
    float *points3 = NULL;
    points3 = (float *) calloc((num+1) * 2, sizeof points1);
    xPoints(dx, bounds[0], points3, func3);
    plot(points3);

    output("./point.ppm", 0);
    outputCleanup();
    return 0;
}