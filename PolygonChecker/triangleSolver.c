#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "triangleSolver.h"

const double PI = 3.14159265358979323846;

void calculate_angles(int a, int b, int c) {
    if (a + b <= c || a + c <= b || b + c <= a) {
        printf("The input values do not form a valid triangle.\n");
        return;
    }
    double angle1, angle2, angle3;

    double cosA = (a * a + b * b - c * c) / (2 * a * b);
    double A = acos(cosA) * 180 / PI;

    double cosB = (b * b + c * c - a * a) / (2 * b * c);
    double B = acos(cosB) * 180 / PI;

    double cosC = (c * c + a * a - b * b) / (2 * c * a);
    double C = acos(cosC) * 180 / PI;



    printf("The angles in the triangle are: \n %.1f \n %.1f \n %.1f \n", A, B, C);
}

char* analyzeTriangle(int side1, int side2, int side3) {
    char* result = "";

    printf("%i\n", side1);
    printf("%i\n", side2);
    printf("%i\n", side3);

    if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
        result = "Not a triangle";
    }
    else if (side1 + side2 < side3 || side2 + side3 < side1 || side3 + side1 < side2) {
        result = "Triangle is not possible";
        return 0;
    }
    else if (side1 == side2 && side1 == side3) {
        printf("The angles are:\n 60.0, \n 60.0, \n 60.0\n");
        result = "Equilateral triangle";
    }
    else if ((side1 == side2 && side1 != side3) ||
        (side1 == side3 && side1 != side2))
    {
        calculate_angles(side1, side2, side3);
        result = "Isosceles triangle";
    }
    else {
        calculate_angles(side1, side2, side3);
        result = "Scalene triangle";
    }

    return result;
}