#pragma once

#include <stdbool.h>

// CSCN71020 - Winter 24 - Group 2

//#define BUFSIZE			99
#define RECTANGLESIDES	4
#define RECTANGLEPOINTS	2
#define TOTALCOORDS		4

typedef enum corner {
	BOTTOMLEFT,
	BOTTOMRIGHT,
	TOPLEFT,
	TOPRIGHT 
} CORNER;

int* getRectangleSides(int rectangleSides[RECTANGLESIDES][RECTANGLEPOINTS]);

void printPoints(int rectangleSides[RECTANGLESIDES][RECTANGLEPOINTS]);

int findMinOfArray(int points[TOTALCOORDS]);

int findMaxOfArray(int points[TOTALCOORDS]);

bool isQuadrilateralFlat(int point1[RECTANGLEPOINTS], int point2[RECTANGLEPOINTS], int point3[RECTANGLEPOINTS], int point4[RECTANGLEPOINTS]);

//bool isRectangle(int xCoordinates[TOTALCOORDS], int yCoordinates[TOTALCOORDS]);

int calculatePerimeter();

char* analyzeQuadrilateral(int point1[RECTANGLEPOINTS], int point2[RECTANGLEPOINTS], int point3[RECTANGLEPOINTS], int point4[RECTANGLEPOINTS]);