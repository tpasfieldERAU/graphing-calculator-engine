//
// Created by TJ on 1/12/2023.
//

#include "plotters.h"

// REQUIRES THE COORDINATES TO BE TRANSFORMED BEFORE USE
// REQUIRES A REWRITE OF PPMOUTPUT AND OTHER OUTPUT METHODS
/*void plotLine(int x0, int y0, int x1, int y1){
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
}*/
void plotLine(int x0, int y0, int x1, int y1){
    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1: -1;
    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1: -1;

    int error = dx + dy;

    while(1){
        plotPixel(x0, y0);
        if(x0 == x1 && y0 == y1){break;}
        int e2 = 2 * error;
        if(e2 >= dy){
            if(x0==x1){break;}
            error = error + dy;
            x0 = x0 + sx;
        }
        if(e2 <= dx){
            if(y0 == y1){break;}
            error = error + dx;
            y0 = y0 + sy;
        }
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

void plot(const float * points){
    float hX = (float) xRes / 2.0f, hY = (float) yRes / 2.0f;
    float xSpan = bounds[1] - bounds[0];
    float ySpan = bounds[3] - bounds[2];
    float xp1, yp1, xp2, yp2;
    int x0, y0, x1, y1;

    for (unsigned int i = 0; i < num; i++){
        xp1 = points[2*i];
        yp1 = points[2*i + 1];
        xp2 = points[2*(i+1)];
        yp2 = points[2*(i+1) + 1];

        // IGNORE NARROWING CONVERSION FOR NOW
        x0 = (int) (((float) xRes * xp1) / xSpan + hX);
        y0 = (int) (((float) yRes * yp1) / ySpan + hY);
        x1 = (int) (((float) xRes * xp2) / xSpan + hX);
        y1 = (int) (((float) yRes * yp2) / ySpan + hY);

        plotLine(x0, y0, x1, y1);

    }

}