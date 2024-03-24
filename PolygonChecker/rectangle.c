#include "rectangle.h"
#include <stdio.h>
#include <string.h>
#define TWO 2


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

// check if quadrilateral is horizontal/vertical and not diagonal
bool isQuadrilateralFlat(float quadrilateralPoints[RECTANGLESIDES][RECTANGLEPOINTS]) {
	bool isFlat = false;

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

	return isFlat;
}

// for sorting algorithm
// check if 2 x and 2 y values are the same
bool isRectangleFlat(float quadrilateralPoints[RECTANGLESIDES][RECTANGLEPOINTS]) {
	bool isFlat = false;

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
	}

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

// get lengths of shape with pythagorean theorem
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

// find diagonal lengths using pythagorean theorem
// calculates from first corner to third corner
// and from second corner to fourth corner
float* findDiagonals(float quadrilateralPoints[RECTANGLESIDES][RECTANGLEPOINTS]) {
	float diagonals[DIAGONALS];

	// calculate diagonals
	float diagonal1 = pythagoreanTheorem(quadrilateralPoints[0], quadrilateralPoints[2]);
	float diagonal2 = pythagoreanTheorem(quadrilateralPoints[1], quadrilateralPoints[3]);

	diagonals[0] = diagonal1;
	diagonals[1] = diagonal2;

	return diagonals;
}

// check if shape is a rectangle and not another type of quadrilateral
bool isRectangle(float lengths[RECTANGLESIDES], float diagonals[RECTANGLEPOINTS]) {
	bool rectangle = false;

	// check if 2 lengths are equal and if both diagonals are equal
	if (lengths[0] == lengths[2] && lengths[1] == lengths[3] && diagonals[0] == diagonals[1]) {
		rectangle = true;
	}

	// check if any lengths and diagonals are 0 (not proper rectangle)
	if (lengths[0] == 0 || lengths[1] == 0 || lengths[2] == 0 || lengths[3] == 0 || diagonals[0] || diagonals[1]) {
		rectangle = false;
	}

	return rectangle;
}


// sort 2D rectangle array into correct corners 
float* sortPoints(float quadrilateralPoints[RECTANGLESIDES][RECTANGLEPOINTS], bool flat) {
	// order of corners for flat quadrilateral
	float bottomLeft[RECTANGLEPOINTS] = { 0, 0 };
	float bottomRight[RECTANGLEPOINTS] = { 0, 0 };
	float topRight[RECTANGLEPOINTS] = { 0, 0 };
	float topLeft[RECTANGLEPOINTS] = { 0, 0 };

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

	bool isRectangleAndFlat = isRectangleFlat(quadrilateralPoints);

	// if quadrilateral is oriented diagonally
	if (!flat) {
		for (int i = 0; i < RECTANGLESIDES; i++) {
			float currentX = quadrilateralPoints[i][0];
			float currentY = quadrilateralPoints[i][1];

			// set bottom coordiante to min y
			if (currentY == minY) {
				bottom[0] = currentX;
				bottom[1] = currentY;
			}
			// set top coordinate to max y value
			if (currentY == maxY) {
				top[0] = currentX;
				top[1] = currentY;
			}
			// set left coordinate to min x
			if (currentX == minX) {
				left[0] = currentX;
				left[1] = currentY;
			}
			// set right coordinate to max x
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
	else if (isRectangleAndFlat) {
		for (int i = 0; i < RECTANGLESIDES; i++) {
			float currentX = quadrilateralPoints[i][0];
			float currentY = quadrilateralPoints[i][1];

			if (currentX == minX && currentY == minY) {
				bottomLeft[0] = currentX;
				bottomLeft[1] = currentY;
			}
			else if (currentX == maxX && currentY == maxY) {
				topRight[0] = currentX;
				topRight[1] = currentY;
			}
			else if (currentX == minX && currentY == maxY) {
				topLeft[0] = currentX;
				topLeft[1] = currentY;
			}
			else if (currentX == maxX && currentY == minY) {
				bottomRight[0] = currentX;
				bottomRight[1] = currentY;
			}
		}

		// set points to correct order for calculations
		quadrilateralPoints[0][0] = bottomLeft[0];
		quadrilateralPoints[0][1] = bottomLeft[1];
		quadrilateralPoints[1][0] = bottomRight[0];
		quadrilateralPoints[1][1] = bottomRight[1];
		quadrilateralPoints[2][0] = topRight[0];
		quadrilateralPoints[2][1] = topRight[1];
		quadrilateralPoints[3][0] = topLeft[0];
		quadrilateralPoints[3][1] = topLeft[1];
	}
	else {
		for (int i = 0; i < RECTANGLESIDES; i++) {
			float currentX = quadrilateralPoints[i][0];
			float currentY = quadrilateralPoints[i][1];
			// check if corner is 0 or empty and current x and y values are not 0
			if (currentX != 0 && bottomLeft[0] == 0 && currentY != 0 && bottomLeft[1] == 0) {
				// check for other types of quadrilaterals
				// might need multiple checks for these
				if (currentX == minX && currentY == minY || currentX >= minX && currentX < maxX && currentY >= minY && currentY < maxY) {
					bottomLeft[0] = currentX;
					bottomLeft[1] = currentY;
				}
			}
			else if (currentX != 0 && bottomRight[0] == 0 && currentY != 0 && bottomRight[1] == 0) {
				// ?
				if (currentX == maxX && currentY == minY || currentX > minX && currentX <= maxX && currentY >= minY && currentY < maxY) {
					bottomRight[0] = currentX;
					bottomRight[1] = currentY;
				}
			}
			else if (currentX == maxX && currentY == maxY || currentX != 0 && topRight[0] == 0 && currentY != 0 && topRight[1] == 0) {
				if (currentX > minX && currentX <= maxX && currentY > minY && currentY <= maxY) {
					topRight[0] = currentX;
					topRight[1] = currentY;
				}
			}
			else if (currentX != 0 && topLeft[0] == 0 && currentY != 0 && topLeft[1] == 0) {
				if (currentX == minX && currentY == maxY || currentX >= minX && currentX < maxX && currentY > minY && currentY <= maxY) {
					topLeft[0] = currentX;
					topLeft[1] = currentY;
				}
			}
		}
	}


	return *quadrilateralPoints;
}

// calculates perimeter of quadrilateral
float calculatePerimeter(float lengths[RECTANGLESIDES]) {
	
	float perimeter = (lengths[0] + lengths[1] )* TWO;
	return perimeter;
}

// calculates area of rectangle
float calculateArea(float lengths[RECTANGLESIDES]) {
	float area = lengths[0] * lengths[1];
	return area;
}

void analyzeQuadrilateral(float quadrilateralPoints[RECTANGLESIDES][RECTANGLEPOINTS]) {
	bool isFlat = isQuadrilateralFlat(quadrilateralPoints);
	sortPoints(quadrilateralPoints, isFlat);

	// find lengths of side of shape shape
	float lengths[LENGTHS];
	lengths[0] = findLengths(quadrilateralPoints)[0];
	lengths[1] = findLengths(quadrilateralPoints)[1];
	lengths[2] = findLengths(quadrilateralPoints)[2];
	lengths[3] = findLengths(quadrilateralPoints)[3];

	float diagonals[DIAGONALS];
	diagonals[0] = findDiagonals(quadrilateralPoints)[0];
	diagonals[1] = findDiagonals(quadrilateralPoints)[1];

	float perimeter = calculatePerimeter(lengths);

	if (isRectangle(lengths, diagonals)) {
		printf("Shape is a rectangle\n");
		//printf("Perimeter is %f\n", perimeter);
		float area = calculateArea(lengths);
		printf("Area is %f\n", area);
	}
	else {
		printf("Shape is not a rectangle\n");
	}

	printf("Perimeter is %f\n", perimeter);
} 