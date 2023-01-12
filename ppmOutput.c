//
// Created by TJ on 1/11/2023.
//

#include "ppmOutput.h"


void writePPM(char *name, char *fcomment, unsigned int xRes, unsigned int yRes, const unsigned char *img) {
    FILE * image;
    image = fopen(name, "wb");
    fprintf(image, "P6\n%s\n%d\n%d\n%d\n", fcomment, xRes, yRes, 255);

    // Default Background Color
    // Cannot currently be changed by user after compilation time
    unsigned char bg[3] = {255, 255, 255};

    // Default Line Color
    unsigned char color[3] = {0, 63, 255};

    // INDEXABLE COLORS
    // This whole thing should probably be in C++ ngl
    // These colors are currently all stolen from the Manim Project, since it provides a nice color theme.
    // Might put a Gruv color theme commented out, just because I like it.
    unsigned char ctable[27] = {0, 0,0,          /* 0 */
                                252, 98, 85,     /* 1 red    */
                                88, 196, 221,      /* 2 blue   */
                                131, 193, 103,   /* 3 green  */
                                255, 255, 0,    /* 4 yellow */
                                92, 208, 179,   /* 5 teal   */
                                154, 114, 172,  /* 6 purple */
                                197, 95, 115,   /* 7 maroon */
                                255, 255, 255}; /* 8 */
    unsigned char c;

    for (unsigned int y = 0; y < yRes; y++) {
        for (unsigned int x = 0; x < xRes; x++) {
            if (img[xRes * y + x] < 8) {
                c = img[xRes * y + x];
                color[0] = ctable[3*c];
                color[1] = ctable[3*c + 1];
                color[2] = ctable[3*c + 2];
                fwrite(color, 1, 3, image);
                continue;
            }
            else {
                fwrite(bg, 1, 3, image);
            }
        }
    }

    fclose(image);
}
