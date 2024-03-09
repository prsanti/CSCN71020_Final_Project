#include "rectangle.h"
#include <stdio.h>
#include <string.h>


// CSCN71020 - Winter 24 - Group 2

#define BUFSIZE			99
#define RECTANGLESIDES	4
#define RECTANGLEPOINTS	2

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
	
	return rectangleSides;
}

void printPoints(int rectangleSides[RECTANGLESIDES][RECTANGLEPOINTS]) {
	for (int i = 0; i < RECTANGLESIDES; i++) {
		printf("e: %d\n", i + 1);
		printf("x: %d\n", rectangleSides[i][0]);
		printf("y: %d\n", rectangleSides[i][1]);
	}
}

char* analyzeQuadrilateral(int point1[RECTANGLEPOINTS], int point2[RECTANGLEPOINTS], int point3[RECTANGLEPOINTS], int point4[RECTANGLEPOINTS]) {
	printf("point 1: %d,%d\n", point1[0], point1[1]);
	printf("point 2: %d,%d\n", point2[0], point2[1]);
	printf("point 3: %d,%d\n", point3[0], point3[1]);
	printf("point 4: %d,%d\n", point4[0], point4[1]);
} 