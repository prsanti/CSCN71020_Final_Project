#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangle.h"

#define RECTANGLESIDES	4
#define RECTANGLEPOINTS	2

// CSCN71020 - Winter 24 - Group 2

int side = 0;

int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			//printf_s("! %d\n", triangleSidesPtr[0]);
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			break;
		case 2:
			printf_s("Rectangle selected.\n");
			int rectangleSides[RECTANGLESIDES][RECTANGLEPOINTS] = {{0,0}, {0,0}, {0,0}, {0,0}};
			//int* rectangleSidesPtr = getRectangleSides(rectangleSides);
			getRectangleSides(rectangleSides);
			printPoints(rectangleSides);
		/*	printf("test %d\n", rectangleSides[0][0]);
			printf("test2 %d\n", rectangleSides[1][0]);*/

			analyzeQuadrilateral(rectangleSides[0], rectangleSides[1], rectangleSides[2], rectangleSides[3]);

			break;
		case 0:
			continueProgram = false;
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("Enter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}