#include "rectangle.h"
#include <stdio.h>
#include <string.h>


// CSCN71020 - Winter 24 - Group 2

// get input from user
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

// print points of shape for testing
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
	float bottom[RECTANGLEPOINTS] = { 0,0 };
	float right[RECTANGLEPOINTS] = { 0,0 };
	float top[RECTANGLEPOINTS] = { 0,0 };
	float left[RECTANGLEPOINTS] = { 0,0 };

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

	// if quadrilateral is oriented diagonally
	if (!flat) {
		for (int i = 0; i < RECTANGLESIDES; i++) {
			float currentX = quadrilateralPoints[i][0];
			float currentY = quadrilateralPoints[i][1];
			printf("loop %d\n", i);
			printf("currentX %f currentY %f\n", currentX, currentY);

			// set min x to bottom coordinate
			if (currentY == minY) {
				bottom[0] = currentX;
				bottom[1] = currentY;
			}

			if (currentY == maxY) {
				top[0] = currentX;
				top[1] = currentY;
			}

			if (currentX == minX) {
				left[0] = currentX;
				left[1] = currentY;
			}

			if (currentX == maxX) {
				right[0] = currentX;
				right[1] = currentY;
			}
		}
			// set points to correct order for calculations
			quadrilateralPoints[0][0] = bottom[0];
			quadrilateralPoints[0][1] = bottom[1];
			quadrilateralPoints[1][0] = right[0];
			quadrilateralPoints[1][1] = right[1];
			quadrilateralPoints[2][0] = top[0];
			quadrilateralPoints[2][1] = top[1];
			quadrilateralPoints[3][0] = left[0];
			quadrilateralPoints[3][1] = left[1];
	} // if quadrilateral is oriented horizontal/vertical
	else {

	}

	return *quadrilateralPoints;
}

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

	// might be missing some types of rectangles and orientations
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

// find min num of array of 4 floats
float findMinOfArray(float points[TOTALCOORDS]) {
	float lowest = points[0];
	for (int i = 0; i < TOTALCOORDS; i++) {
		if (points[i] <= lowest) {
			lowest = points[i];
		}
	}
	return lowest;
}

// find max num of array of 4 floats
float findMaxOfArray(float points[TOTALCOORDS]) {
	float highest = points[0];
	for (int i = 0; i < TOTALCOORDS; i++) {
		if (points[i] >= highest) {
			highest = points[i];
		}
	}
	return highest;
}

float* findLengths(float quadrilateralPoints[RECTANGLESIDES][RECTANGLEPOINTS]) {
	float lengths[LENGTHS];

	// calculate length with pythagorean theorem
	float side1 = pythagoreanTheorem(quadrilateralPoints[0], quadrilateralPoints[1]);
	float side2 = pythagoreanTheorem(quadrilateralPoints[1], quadrilateralPoints[2]);
	float side3 = pythagoreanTheorem(quadrilateralPoints[2], quadrilateralPoints[3]);
	float side4 = pythagoreanTheorem(quadrilateralPoints[3], quadrilateralPoints[0]);

	lengths[0] = side1;
	lengths[1] = side2;
	lengths[2] = side3;
	lengths[3] = side4;

	return lengths;
}

float* findDiagonals(float quadrilateralPoints[RECTANGLESIDES][RECTANGLEPOINTS]) {
	float diagonals[DIAGONALS];

	// calculate diagonals
	float diagonal1 = pythagoreanTheorem(quadrilateralPoints[0], quadrilateralPoints[2]);
	float diagonal2 = pythagoreanTheorem(quadrilateralPoints[1], quadrilateralPoints[3]);

	diagonals[0] = diagonal1;
	diagonals[1] = diagonal2;

	return diagonals;
}

bool isRectangle(float lengths[RECTANGLESIDES], float diagonals[RECTANGLEPOINTS]) {
	bool rectangle = false;

	if (lengths[0] == lengths[2] && lengths[1] == lengths[3] && diagonals[0] == diagonals[1]) {
		rectangle = true;
	}

	printf("is rectangle %d\n", rectangle);

	return rectangle;
}

float calculatePerimeter(float lengths[RECTANGLESIDES]) {
	float perimeter = 0;
	for (int i = 0; i < RECTANGLESIDES; i++) {
		perimeter += lengths[0];
	}
	return perimeter;
}

float calculateArea(float lengths[RECTANGLESIDES]) {
	float area = lengths[0] * lengths[1];
	return area;
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
	sortPoints(quadrilateralPoints, isFlat);
	printPoints(quadrilateralPoints);

	// find lengths of side of shape shape
	float lengths[LENGTHS];
	lengths[0] = findLengths(quadrilateralPoints)[0];
	lengths[1] = findLengths(quadrilateralPoints)[1];
	lengths[2] = findLengths(quadrilateralPoints)[2];
	lengths[3] = findLengths(quadrilateralPoints)[3];

	float diagonals[DIAGONALS];
	diagonals[0] = findDiagonals(quadrilateralPoints)[0];
	diagonals[1] = findDiagonals(quadrilateralPoints)[1];

	float area = 0;
	float perimeter = 0;
	float perimeter = calculatePerimeter(lengths);

	if (isRectangle(lengths, diagonals)) {
		printf("Shape is a rectangle\n");
		printf("Perimeter is %f\n", perimeter);
		area = calculateArea(lengths);
		printf("Area is %f\n", area);
	}
	else {
		printf("Shape is not a rectangle\n");
		printf("Perimeter is %f\n", perimeter);
	}

	//printf("length 1 %f\n", lengths[0]);
	//printf("length 2 %f\n", lengths[1]);
	//printf("length 3 %f\n", lengths[2]);
	//printf("length 4 %f\n", lengths[3]);
} 