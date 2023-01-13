//
// Created by TJ on 1/12/2023.
//

#ifndef GRAPHING_CALCULATOR_ENGINE_VARS_H
#define GRAPHING_CALCULATOR_ENGINE_VARS_H

#endif //GRAPHING_CALCULATOR_ENGINE_VARS_H

#include <stdio.h>
#include <stdlib.h>

extern unsigned int xRes;
extern unsigned int yRes;
extern unsigned char shape;
extern unsigned char lineColor;
extern unsigned int num;

extern double * bounds;



void varsInit(unsigned int xR, unsigned int yR, unsigned char s, unsigned char c, unsigned int n, double bounds[4]);
void changeShape(unsigned char s);
void changeColor(unsigned char c);