#pragma once

// CSCN71020 - Winter 24 - Group 2

#define RECTANGLESIDES	4
#define RECTANGLEPOINTS	2

int* getRectangleSides(int rectangleSides[RECTANGLESIDES][RECTANGLEPOINTS]);

void printPoints(int rectangleSides[RECTANGLESIDES][RECTANGLEPOINTS]);

char* analyzeQuadrilateral(int point1[RECTANGLEPOINTS], int point2[RECTANGLEPOINTS], int point3[RECTANGLEPOINTS], int point4[RECTANGLEPOINTS]);