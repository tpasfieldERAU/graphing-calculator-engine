//
// Created by TJ on 1/11/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "ppmOutput.h"
#include "pointGenerators.h"

// Placeholder function to plot, look into lambdas and things too
double userFunc(double x){
    double ans = sqrt(x) * sin(8 * x);
    return ans;
}

int main(){
    unsigned int xRes = 240;
    unsigned int yRes = 180;

    // This guarantees a center row of pixels, for easier plotting and centering
    xRes += (xRes % 2 == 0);
    yRes += (yRes % 2 == 0);

    unsigned int num = 32;
    if (num > xRes){
        printf("Invalid number of points. Try again.");
        return 1;
    }
    double bounds[4] = {0.0, 8.0, -3.0, 3.0};

    unsigned int xDiv = xRes / num;
    double dx = (double)(bounds[1] - bounds[0]) / (double) xDiv;

    double *points = NULL;
    points = (double *) calloc((xRes / num +1) * 2, sizeof points);

    /*
    double *axes = NULL;
    axes = (double * ) calloc((xRes + yRes) * 2, sizeof axes);
    */

    unsigned int length = xDiv;
    unsigned char * img;
    img = (unsigned char *) calloc(xRes * yRes, sizeof img);

    // POINT GENERATORS ARE PUT HERE
    xPoints(xRes, num, dx, bounds[0], points, userFunc);
    // PLOT FUNCTIONS ARE PUT HERE

    writePPM("test.ppm", "# ", xRes, yRes, img);

    free(points);
    // free(axes);
    free(img);
    return 0;
}