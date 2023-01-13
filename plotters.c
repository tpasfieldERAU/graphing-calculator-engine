//
// Created by TJ on 1/12/2023.
//

#include "plotters.h"

// REQUIRES THE COORDINATES TO BE TRANSFORMED BEFORE USE
// REQUIRES A REWRITE OF PPMOUTPUT AND OTHER OUTPUT METHODS
void plotLine(int x0, int y0, int x1, int y1){
    int dx = x1 - x0;
    int dy = y1 - y0;

    int D = 2 * dy - dx;
    int y = y0;

    for(int x = x0; x <= x1; x++){
        plotPixel(x, y);
        if(D > 0){
            y = y + 1;
            D = D - 2*dx;
        }
        D = D + 2 * dy;
    }
}
// This is more of a placeholder because I'm lazy
void plotPixel(int x, int y){
    // IMPLEMENT SHAPES LATER
    if (x < 0 | x > xRes | y < 0 | y > yRes){
        return;
    }
    img[xRes * y + x] = lineColor;
}

void plot(double * points){
    double hX = xRes / 2.0, hY = yRes / 2.0;
    double xSpan = bounds[1] - bounds[0];
    double ySpan = bounds[3] - bounds[2];
    double xp1, yp1, xp2, yp2;
    int x0, y0, x1, y1;

    for (unsigned int i = 0; i < (num-1) * 2; i++){
        xp1 = points[2*i];
        yp1 = points[2*i + 1];
        xp2 = points[2*(i+1)];
        yp2 = points[2*(i+1) + 1];

        // IGNORE NARROWING CONVERSION FOR NOW
        x0 = (int) (xRes * xp1) / xSpan + hX;
        y0 = (int) (yRes * yp1) / ySpan + hY;
        x1 = (int) (xRes * xp2) / xSpan + hX;
        y1 = (int) (yRes * yp2) / ySpan + hY;

        plotLine(x0, y0, x1, y1);

    }

}