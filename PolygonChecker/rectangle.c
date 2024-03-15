#include "rectangle.h"
#include <stdio.h>
#include <string.h>


// CSCN71020 - Winter 24 - Group 2

int* getRectangleSides(int rectangleSides[RECTANGLESIDES][RECTANGLEPOINTS]) {
	printf_s("Enter the four points of the rectangle:\n");
	for (int i = 0; i < 4; i++) {
		printf("Coordinate %d\n", i + 1);
		printf("Enter the x-coordinate: \n");
		int x;
		scanf_s("%d", &x);

		rectangleSides[i][0] = x;

		printf("Enter the y-coordinate: \n");
		int y;
		scanf_s("%d", &y);
		rectangleSides[i][1] = y;
	}
	
	return *rectangleSides;
}

void printPoints(int rectangleSides[RECTANGLESIDES][RECTANGLEPOINTS]) {
	for (int i = 0; i < RECTANGLESIDES; i++) {
		printf("e: %d\n", i + 1);
		printf("x: %d\n", rectangleSides[i][0]);
		printf("y: %d\n", rectangleSides[i][1]);
	}
}

// fix this
bool isQuadrilateralFlat(int point1[RECTANGLEPOINTS], int point2[RECTANGLEPOINTS], int point3[RECTANGLEPOINTS], int point4[RECTANGLEPOINTS]) {
	bool areTwoXEqual = false;
	bool areTwoYEqual = false;
	bool isFlat = false;

	if (point1[0] == point2[0] || point1[0] == point3[0] || point1[0] == point4[0]) {
		areTwoXEqual = true;
	}

	if (point1[1] == point2[1] || point1[1] == point3[1] || point1[1] == point4[1]) {
		areTwoYEqual = true;
	}

	if (areTwoXEqual && areTwoYEqual) {
		isFlat = true;
	}

	return isFlat;
}

int findMinOfArray(int points[TOTALCOORDS]) {
	int lowest = points[0];
	for (int i = 0; i < TOTALCOORDS; i++) {
		if (points[i] <= lowest) {
			lowest = points[i];
		}
	}
	return lowest;
}

int findMaxOfArray(int points[TOTALCOORDS]) {
	int highest = points[0];
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

char* analyzeQuadrilateral(int point1[RECTANGLEPOINTS], int point2[RECTANGLEPOINTS], int point3[RECTANGLEPOINTS], int point4[RECTANGLEPOINTS]) {
	printf("point 1: %d,%d\n", point1[0], point1[1]);
	printf("point 2: %d,%d\n", point2[0], point2[1]);
	printf("point 3: %d,%d\n", point3[0], point3[1]);
	printf("point 4: %d,%d\n", point4[0], point4[1]);

	int xCoordinates[TOTALCOORDS] = { point1[0], point2[0], point3[0], point4[0] };
	int yCoordinates[TOTALCOORDS] = { point1[1], point2[1], point3[1], point4[1] };

	printf("lowest x: %d\n", findMinOfArray(xCoordinates));
	printf("highest x: %d\n", findMaxOfArray(xCoordinates));

	printf("lowest y: %d\n", findMinOfArray(yCoordinates));
	printf("highest y: %d\n", findMaxOfArray(yCoordinates));

	bool isFlat = false;

	bool test = isQuadrilateralFlat(point1, point2, point3, point4);
	printf("is flat? %d\n", test);



	//if (isRectangle()) {
	//	analyzeRectangle();
	//}
	//else {
	//	findPerimeter();
	//}
} 