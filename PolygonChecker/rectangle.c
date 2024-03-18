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

// pythagorean theorem
// a^2 + b^2 = c^2
// can use theorem on a striaght line as well
float pythagoreanTheorem(float a[RECTANGLEPOINTS], float b[RECTANGLEPOINTS]) {
	// point format: {x, y}
	float c = sqrtf(pow(b[0] - a[0], 2) + pow(b[1] - a[1], 2));
	return c;
}

// sort 2D rectangle array into correct corners 
float* sortPoints(float quadrilateralPoints[RECTANGLESIDES][RECTANGLEPOINTS], bool flat) {
	// order of corners for flat quadrilateral
	float bottomLeft[RECTANGLEPOINTS];
	float bottomRight[RECTANGLEPOINTS];
	float topRight[RECTANGLEPOINTS];
	float topLeft[RECTANGLEPOINTS];
	
	// order of corners if diagonal
	float bottom[RECTANGLEPOINTS];
	float right[RECTANGLEPOINTS];
	float top[RECTANGLEPOINTS];
	float left[RECTANGLEPOINTS];

	// put x and y coords into an array
	float xCoords[RECTANGLESIDES] = { quadrilateralPoints[0][0], quadrilateralPoints[1][0], quadrilateralPoints[2][0], quadrilateralPoints[3][0] };
	float yCoords[RECTANGLESIDES] = { quadrilateralPoints[0][1], quadrilateralPoints[1][1], quadrilateralPoints[2][1], quadrilateralPoints[3][1] };
	// find min and max x
	float minX = findMinOfArray(xCoords);
	float maxX = findMaxOfArray(xCoords);
	// find min and max y
	float minY = findMinOfArray(yCoords);
	float maxY = findMaxOfArray(yCoords);

	printf("min x %f\n", minX);
	printf("max x %f\n", maxX);
	printf("min y %f\n", minY);
	printf("max y %f\n", maxY);


	// create temp array
	float temp[RECTANGLEPOINTS];
	// initialize x and y value to first element of input
	//temp[0] = quadrilateralPoints[0][0];
	//temp[1] = quadrilateralPoints[0][1];

	for (int i = 0; i < RECTANGLESIDES; i++) {
		float currentX = quadrilateralPoints[i][0];
		float currentY = quadrilateralPoints[i][1];

		//if (currentX)
	}

	// set first corner as bottom left
	//quadrilateralPoints[0][0] = bottomLeft[0];
	//quadrilateralPoints[0][1] = bottomLeft[1];


	return *quadrilateralPoints;
}

// fix this
bool isQuadrilateralFlat(float quadrilateralPoints[RECTANGLESIDES][RECTANGLEPOINTS]) {
	bool isFlat = false;

	//float xCoord1 = 0, xCoord2 = 0, yCoord1 = 0, yCoord2 = 0;
	// set first x-coordinate to first x value
	float xCoord1 = quadrilateralPoints[0][0];
	// set first y-coordinate to first y value
	float yCoord1 = quadrilateralPoints[0][1];

	float xCoord2, yCoord2;

	// set second x-coordinate to second different x value
	if (quadrilateralPoints[1][0] != xCoord1) {
		xCoord2 = quadrilateralPoints[1][0];
	}
	else {
		xCoord2 = quadrilateralPoints[2][0];
	}

	// set second y-coordinate to second different x value
	if (quadrilateralPoints[1][1] != yCoord1) {
		yCoord2 = quadrilateralPoints[1][1];
	}
	else {
		yCoord2 = quadrilateralPoints[2][1];
	}

	// keep count of x and y values
	int xCount1 = 0;
	int xCount2 = 0;
	int yCount1 = 0;
	int yCount2 = 0;

	// set coords
	for (int i = 0; i < RECTANGLESIDES; i++) {
		float currentX = quadrilateralPoints[i][0];
		float currentY = quadrilateralPoints[i][1];

		if (currentX == xCoord1) {
			xCount1++;
		}
		else if (currentX == xCoord2) {
			xCount2++;
		}

		if (currentY == yCoord1) {
			yCount1++;
		}
		else if (currentY == yCoord2) {
			yCount2++;
		}

	}

	// flat (vertical/horizontal)
	// rectangle
	if (xCount1 == 2 && xCount2 == 2 && yCount1 == 2 && yCount2 == 2) {
		isFlat = true;
	}	// trapezoid
	else if (xCount1 == 2 && xCount2 == 1 || xCount1 == 1 && xCount2 == 2) {
		isFlat = true;
	}
	else if (yCount1 == 2 && yCount2 == 1 || yCount1 == 1 && yCount2 == 2) {
		isFlat = true;
	} // parallelogram
	else if (yCount1 == 2 && yCount2 == 2 && xCount1 == 1 && xCount2 == 1) {
		isFlat = true;
	}
	else if (yCount1 == 1 && yCount2 == 1 && xCount1 == 2 && xCount2 == 2) {
		isFlat = true;
	}

	printf("x coord 1 %f\n", xCoord1);
	printf("x coord 2 %f\n", xCoord2);
	printf("y coord 1 %f\n", yCoord1);
	printf("y coord 2 %f\n", yCoord2);

	printf("xcount1 %d\n", xCount1);
	printf("xcount2 %d\n", xCount2);
	printf("ycount1 %d\n", yCount1);
	printf("ycount2 %d\n", yCount2);

	printf("isflat? %d\n", isFlat);

	return isFlat;
}

float findMinOfArray(float points[TOTALCOORDS]) {
	float lowest = points[0];
	for (int i = 0; i < TOTALCOORDS; i++) {
		if (points[i] <= lowest) {
			lowest = points[i];
		}
	}
	return lowest;
}

float findMaxOfArray(float points[TOTALCOORDS]) {
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

// method 1
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

// method 2
/*
	1) sort each coord and find the corner
	2) calculate length from each point
	3) calculate distance from corner to corner (diagonal)
	4) if diagonals are equal, lengths are equal, widths are equal then rectangle
	5) return perimeter, and area if all are equal
	6) return perimeter if not rectangle
*/

char* analyzeQuadrilateral(float quadrilateralPoints[RECTANGLESIDES][RECTANGLEPOINTS]) {
	// check if quadrilateral is flat

	//bool isFlat = false;

	// for diagonal
	//int xCoordinates[TOTALCOORDS] = { point1[0], point2[0], point3[0], point4[0] };
	//int yCoordinates[TOTALCOORDS] = { point1[1], point2[1], point3[1], point4[1] };

	//printf("lowest x: %d\n", findMinOfArray(xCoordinates));
	//printf("highest x: %d\n", findMaxOfArray(xCoordinates));

	//printf("lowest y: %d\n", findMinOfArray(yCoordinates));
	//printf("highest y: %d\n", findMaxOfArray(yCoordinates));



	//bool test = isQuadrilateralFlat(point1, point2, point3, point4);

	//if (isRectangle()) {
	//	analyzeRectangle();
	//}
	//else {
	//	findPerimeter();
	//}

	bool isFlat = isQuadrilateralFlat(quadrilateralPoints);
	sortPoints(quadrilateralPoints);
} 