//
// Created by TJ on 1/11/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "outputs.h"
#include "pointGenerators.h"
#include "vars.h"

// Placeholder function to plot, look into lambdas and things too
double userFunc(double x){
    double ans = sqrt(x) * sin(8 * x);
    return ans;
}

int main(){
    double b[4] = {0.0, 8.0, -3.0, 3.0};
    varsInit(240, 180, 1, 1, 32, b);
    outputInit();

    unsigned int xDiv = xRes / num;
    double dx = (double)(bounds[1] - bounds[0]) / (double) xDiv;


    // Consider moving this?
    // Otherwise, it allows easy use of keeping data in an array format, which could be good
    //  for table view and other processing
    double *points = NULL;
    points = (double *) calloc((xRes / num + 1) * 2, sizeof points);

    xPoints(dx, bounds[0], points, userFunc);
    // PLOT FUNCTIONS ARE PUT HERE

    output("point.ppm", 0);
    outputCleanup();
    return 0;
}