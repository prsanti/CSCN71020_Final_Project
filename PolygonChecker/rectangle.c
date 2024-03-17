#include "rectangle.h"
#include <stdio.h>
#include <string.h>


// CSCN71020 - Winter 24 - Group 2

float* getRectangleSides(float rectangleSides[RECTANGLESIDES][RECTANGLEPOINTS]) {
	printf_s("Enter the four points of the rectangle:\n");
	for (int i = 0; i < RECTANGLESIDES; i++) {
		printf("Coordinate %d\n", i + 1);
		printf("Enter the x-coordinate: \n");
		float x;
		scanf_s("%f", &x);

		rectangleSides[i][0] = x;

		printf("Enter the y-coordinate: \n");
		float y;
		scanf_s("%f", &y);
		rectangleSides[i][1] = y;
	}
	
	return *rectangleSides;
}

void printPoints(float quadrilateralPoints[RECTANGLESIDES][RECTANGLEPOINTS]) {
	for (int i = 0; i < RECTANGLESIDES; i++) {
		printf("point %d: (%f, %f)\n", i+1, quadrilateralPoints[i][0], quadrilateralPoints[i][1]);
	}
}

// fix this
bool isQuadrilateralFlat(float quadrilateralPoints[RECTANGLESIDES]) {
	bool areTwoXEqual = false;
	bool areTwoYEqual = false;
	bool isFlat = false;

	//int xCoord1 = point1[0]; 
	//int xCoord2 = point2[0];
	//int yCoord1 = point1[1];
	//int yCoord2 = point2[1];

	int xCount = 0;
	int yCount = 0;

	for (int i = 0; i < RECTANGLESIDES; i++) {
		
	}

	return isFlat;
}

float findMinOfArray(int points[TOTALCOORDS]) {
	float lowest = points[0];
	for (int i = 0; i < TOTALCOORDS; i++) {
		if (points[i] <= lowest) {
			lowest = points[i];
		}
	}
	return lowest;
}

float findMaxOfArray(int points[TOTALCOORDS]) {
	float highest = points[0];
	for (int i = 0; i < TOTALCOORDS; i++) {
		if (points[i] >= highest) {
			highest = points[i];
		}
	}
	return highest;
}

// need to find each corner and define them

// rectangle if:
// all corners are 90 degrees

// if rectangle:
// 1) need to check if flat
//		- 2 xs are equal
//		- 2 ys are equal
// 2)

/*
	1) check if flat
		a) if flat and coords are 2 x equal and 2 y equal then rectangle
		b) define corners
	2) define corners
	3) check if right angle (90deg)
		a) if all 90 then rectangle
		b) else return perimeter
*/

char* analyzeQuadrilateral(float quadrilateralPoints[RECTANGLESIDES][RECTANGLEPOINTS]) {
	// check if quadrilateral is flat

	bool isFlat = false;

	// for diagonal
	//int xCoordinates[TOTALCOORDS] = { point1[0], point2[0], point3[0], point4[0] };
	//int yCoordinates[TOTALCOORDS] = { point1[1], point2[1], point3[1], point4[1] };

	//printf("lowest x: %d\n", findMinOfArray(xCoordinates));
	//printf("highest x: %d\n", findMaxOfArray(xCoordinates));

	//printf("lowest y: %d\n", findMinOfArray(yCoordinates));
	//printf("highest y: %d\n", findMaxOfArray(yCoordinates));



	//bool test = isQuadrilateralFlat(point1, point2, point3, point4);
	//printf("is flat? %d\n", test);



	//if (isRectangle()) {
	//	analyzeRectangle();
	//}
	//else {
	//	findPerimeter();
	//}
} 