//
// Created by TJ on 1/11/2023.
//

#ifndef GRAPHING_CALCULATOR_ENGINE_PPMOUTPUT_H
#define GRAPHING_CALCULATOR_ENGINE_PPMOUTPUT_H

#endif //GRAPHING_CALCULATOR_ENGINE_PPMOUTPUT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vars.h"

extern unsigned char * img;

void outputInit();

void outputCleanup();

void output(char * name, unsigned int type);

void writePPM(char * name, char * fcomment);
