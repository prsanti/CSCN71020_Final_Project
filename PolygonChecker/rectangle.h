#pragma once

#include <stdbool.h>
#include <math.h>

// CSCN71020 - Winter 24 - Group 2

//#define BUFSIZE			99
#define RECTANGLESIDES	4
#define RECTANGLEPOINTS	2
#define TOTALCOORDS		4

//typedef enum flatcorner {
//	BOTTOMLEFT,
//	BOTTOMRIGHT,
//	TOPLEFT,
//	TOPRIGHT 
//} FLATCORNER;
//
//typedef enum diagonalcorner {
//	BOTTOM,
//	TOP,
//	LEFT,
//	RIGHT
//} DIAGONALCORNER;

typedef enum corner {
	// flat
	BOTTOM,
	TOP,
	LEFT,
	RIGHT,
	// diagonal
	BOTTOMLEFT,
	BOTTOMRIGHT,
	TOPLEFT,
	TOPRIGHT
} CORNER;

typedef struct rectanglecorner {
	CORNER type;
	int point[2];
} RECTANGLECORNER;

//typedef struct flatrectangle {
//	FLATCORNER corner[RECTANGLESIDES];
//	struct {
//		int point[2];
//	};
//
//} FLATRECTANGLE;

float* getRectangleSides(float rectangleSides[RECTANGLESIDES][RECTANGLEPOINTS]);

void printPoints(float rectangleSides[RECTANGLESIDES][RECTANGLEPOINTS]);

// pythagorean theorem
float pythagoreanTheorem(float a[RECTANGLEPOINTS], float b[RECTANGLEPOINTS]);

float* sortPoints(float quadrilateralPoints[RECTANGLESIDES][RECTANGLEPOINTS], bool flat);

float findMinOfArray(float points[TOTALCOORDS]);

float findMaxOfArray(float points[TOTALCOORDS]);

bool isQuadrilateralFlat(float quadrilateralPoints[RECTANGLESIDES][RECTANGLEPOINTS]);

//bool isRectangle(int xCoordinates[TOTALCOORDS], int yCoordinates[TOTALCOORDS]);

float* findLengths(float quadrilateralPoints[RECTANGLESIDES][RECTANGLEPOINTS]);

float calculatePerimeter();

float calculateArea();

char* analyzeQuadrilateral(float quadrilateralPoints[RECTANGLESIDES][RECTANGLEPOINTS]);