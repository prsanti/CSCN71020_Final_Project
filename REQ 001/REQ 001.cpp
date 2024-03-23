#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
extern "C" void calculate_angles(int a, int b, int c);
extern "C"  char* analyzeTriangle(int side1, int side2 , int side3);
extern "C" float calculatePerimeter(float[]);
extern "C" float calculateArea(float[]);
extern "C" float pythagoreanTheorem(float[], float[]);
extern "C" bool isQuadrilateralFlat(float[]);
extern "C" bool isRectangle(float[], float[]);
namespace REQ001
{
    TEST_CLASS(TRIANGLE)
    {
    public:

        TEST_METHOD(TestEquilateralTriangle)
        {
            // Test an equilateral triangle
          
            Assert::AreEqual("Equilateral triangle", analyzeTriangle(5, 5, 5));
        }

        TEST_METHOD(TestIsoscelesTriangle)
        {
            // Test an isosceles triangle
            Assert::AreEqual("Isosceles triangle", analyzeTriangle(5, 5, 6));
        }

        TEST_METHOD(TestScaleneTriangle)
        {
            // Test a scalene triangle
            Assert::AreEqual("Scalene triangle", analyzeTriangle(3, 4, 5));
        }

        TEST_METHOD(TestNotATriangle)
        {
            // Test when the sides do not form a triangle
            Assert::AreEqual("Not a triangle", analyzeTriangle(0, 0, 0));
        }
        TEST_METHOD(TestValidTriangleangle)
        {

            // Assert
            int a = 3, b = 4, c = 5;

            calculate_angles(a, b, c);

            // Assert
            Assert::AreEqual(90.0,  1.0); 
            Assert::AreEqual(36.9,  1.0);
            Assert::AreEqual(53.1,  1.0);
        }
    };
    TEST_CLASS(RECTANGLE)
    {
    public:
        TEST_METHOD(pythagoras)
        {
            // Test a rectangle with sides 4 and 5
            float a[2] = { 1, 1 };
            float b[2] = { 3, 1 };
            float result = pythagoreanTheorem(a, b);
            float expected = 2.0;
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestCalculateArea)
        {
            // Test a rectangle with sides 4 and 5
            float lengths[2] = { 4, 5 };
            float expectedArea = 20;
            Assert::AreEqual(expectedArea, calculateArea(lengths));
        }
        TEST_METHOD(TestCalculateAreaZeroSides)
        {
            // Test a rectangle with sides 0 and 5
            float lengths[2] = { 0, 5 };
            float expectedArea = 0;
            Assert::AreEqual(expectedArea, calculateArea(lengths));
        }
        TEST_METHOD(TestCalculatePerimeterZeroSides)
        {
            // Test when one side is 0
            float lengths[4] = { 2, 0, 2, 0 };
            float expectedPerimeter = 8; // Perimeter = 2*(length + width)
            float result = calculatePerimeter(lengths);
            Assert::AreEqual(expectedPerimeter, result);
        }
        TEST_METHOD(TestCalculatePerimeter)
        {
            // Test a rectangle 
            float lengths[4] = { 2, 1, 2, 1 };
            float expectedPerimeter = 8; // Perimeter = 2*(length + width)
            float result = calculatePerimeter(lengths);
            Assert::AreEqual(expectedPerimeter, result);
        }
        TEST_METHOD(Testifrectangle)
        {
            // Test a rectangle 
            float lengths[4] = { 2,1,2,1 };
            float diagonals[2] = { 2.23606797, 2.23606797 };
            float expected = true; 
            float result = isRectangle(lengths, diagonals);
            Assert::AreEqual(expected, result);
        }
       
       
    };


}
