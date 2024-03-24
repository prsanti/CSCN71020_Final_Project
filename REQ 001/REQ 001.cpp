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
        TEST_METHOD(pythagoras_SmallInputs)
        {
            // Test with very small sides
            float a[2] = { 0.0001, 0.0001 };
            float b[2] = { 0.0002, 0.0001 };
            float result = pythagoreanTheorem(a, b);
            float expected = 0.0001; // Expected result can be calculated separately
            Assert::AreEqual(expected, result);
        }
        TEST_METHOD(pythagoras_DegenerateTriangle) 
        {
            // Test with collinear sides
            float a[2] = { 1, 1 };
            float b[2] = { 1, 2 };
            float result = pythagoreanTheorem(a, b);
            float expected = 1.0; // Since two points are collinear, the distance should be the difference in the other coordinate
            Assert::AreEqual(expected, result);
        }

        TEST_METHOD(TestCalculateArea)
        {
            // Test a rectangle with sides 4 and 5
            float lengths[2] = { 4, 5 };
            float expectedArea = 20;
            Assert::AreEqual(expectedArea, calculateArea(lengths));
        }
        TEST_METHOD(TestCalculateArea_SmallInputs) 
        {
            // Test with very small sides
            float lengths[2] = { 1, 1 };
            float expectedArea = 1;
            Assert::AreEqual(expectedArea, calculateArea(lengths));
        }
        TEST_METHOD(TestCalculateArea_LargeNumbers) 
        {
            // Test with very large sides
            float lengths[2] = { 1e9, 1e9 };
            // Expected result is calculated as the product of the lengths
            float expectedArea = 1e18; // 1e9 * 1e9
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
            float lengths[2] = {  0, 5 };
            float expectedPerimeter = 10;
            float result = calculatePerimeter(lengths);
            Assert::AreEqual(expectedPerimeter, result);
        }
        TEST_METHOD(TestCalculatePerimeterLargeNumbers)
        {
            float lengths[2] = { 1e9, 2e9 }; // Rectangle with large side lengths
            float expectedPerimeter = 6e9; // Perimeter = 2 * (1e9 + 2e9) = 6e9
            float result = calculatePerimeter(lengths);
            Assert::AreEqual(expectedPerimeter,result );
        }
        TEST_METHOD(TestCalculatePerimeter)
        {
            // Test a rectangle 
            float lengths[2] = { 5, 5 };
            float expectedPerimeter = 20;
            float result = calculatePerimeter(lengths);
            Assert::AreEqual(expectedPerimeter, result);
        }
        TEST_METHOD(Testifnotrectangle)
        {
            // Test a rectangle 
            float lengths[4] = { 0, 0, 0, 0 };
    float diagonals[2] = { 2.23606797, 2.23606797 };
    bool expected = false; 
    bool result = isRectangle(lengths, diagonals);
    Assert::AreEqual(expected, result);
        }
       
        
    };


}
