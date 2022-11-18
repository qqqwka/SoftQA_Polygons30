#include "pch.h"
#include "CppUnitTest.h"
#include "..\SoftQA_Polygons30\SoftQA_Polygons30.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace findIntersectionPointTest
{
	TEST_CLASS(findIntersectionPointTest)
	{
	public:

		TEST_METHOD(findIntersection_AllPositive)
		{
			double x1, x2, x3, x4, y1, y2, y3, y4, resX, resY;

			resX = 0;
			resY = 0;

			x1 = 2;
			y1 = 1;
			x2 = 3;
			y2 = 4;
			x3 = 1;
			y3 = 4;
			x4 = 3;
			y4 = 2;

			findIntersectionPoint(x1, y1, x2, y2, x3, y3, x4, y4, resX, resY);

			Assert::AreEqual(resX, 2.5);
			Assert::AreEqual(resY, 2.5);


		}
		TEST_METHOD(findIntersection_AllNegative)
		{
			double x1, x2, x3, x4, y1, y2, y3, y4, resX, resY;

			resX = 0;
			resY = 0;

			x1 = -2;
			y1 = -1;
			x2 = -3;
			y2 = -4;
			x3 = -1;
			y3 = -4;
			x4 = -3;
			y4 = -2;

			findIntersectionPoint(x1, y1, x2, y2, x3, y3, x4, y4, resX, resY);

			Assert::AreEqual(resX, -2.5);
			Assert::AreEqual(resY, -2.5);


		}

		TEST_METHOD(findIntersection_AllPositiveDouble)
		{
			double x1, x2, x3, x4, y1, y2, y3, y4, resX, resY;

			resX = 0;
			resY = 0;

			x1 = 2.2;
			y1 = 1.1;
			x2 = 3.3;
			y2 = 4.4;
			x3 = 1.1;
			y3 = 4.4;
			x4 = 3.3;
			y4 = 2.2;

			findIntersectionPoint(x1, y1, x2, y2, x3, y3, x4, y4, resX, resY);

			Assert::AreEqual(resX, 2.75);
			Assert::AreEqual(resY, 2.75);


		}
		TEST_METHOD(findIntersection_AllNegativeDouble)
		{
			double x1, x2, x3, x4, y1, y2, y3, y4, resX, resY;

			resX = 0;
			resY = 0;

			x1 = -2.0;
			y1 = -1.0;
			x2 = -3.0;
			y2 = -4.0;
			x3 = -1.0;
			y3 = -4.0;
			x4 = -3.0;
			y4 = -2.0;

			findIntersectionPoint(x1, y1, x2, y2, x3, y3, x4, y4, resX, resY);

			Assert::AreEqual(resX, -2.5);
			Assert::AreEqual(resY, -2.5);


		}

		TEST_METHOD(findIntersection_HalfPositiveDouble)
		{
			double x1, x2, x3, x4, y1, y2, y3, y4, resX, resY;

			resX = 0;
			resY = 0;

			x1 = -1.0;
			y1 = -1.0;
			x2 = 2.0;
			y2 = 2.0;
			x3 = -1.0;
			y3 = 1.0;
			x4 = 1.0;
			y4 = -1.0;

			findIntersectionPoint(x1, y1, x2, y2, x3, y3, x4, y4, resX, resY);

			Assert::AreEqual(resX, 0.0);
			Assert::AreEqual(resY, 0.0);


		}
		TEST_METHOD(findIntersection_HalfNegativeDouble)
		{
			double x1, x2, x3, x4, y1, y2, y3, y4, resX, resY;

			resX = 0;
			resY = 0;

			x1 = 1.0;
			y1 = 1.0;
			x2 = -2.0;
			y2 = -2.0;
			x3 = 1.0;
			y3 = -1.0;
			x4 = -1.0;
			y4 = 1.0;

			findIntersectionPoint(x1, y1, x2, y2, x3, y3, x4, y4, resX, resY);

			Assert::AreEqual(resX, 0.0);
			Assert::AreEqual(resY, 0.0);


		}

		TEST_METHOD(findIntersection_HalfPositiveInt)
		{
			double x1, x2, x3, x4, y1, y2, y3, y4, resX, resY;

			resX = 0;
			resY = 0;

			x1 = -3;
			y1 = -3;
			x2 = 6;
			y2 = 6;
			x3 = 0;
			y3 = 2;
			x4 = 2;
			y4 = 0;

			findIntersectionPoint(x1, y1, x2, y2, x3, y3, x4, y4, resX, resY);

			Assert::AreEqual(resX, 1.0);
			Assert::AreEqual(resY, 1.0);


		}

		TEST_METHOD(findIntersection_HalfNegativeInt)
		{
			double x1, x2, x3, x4, y1, y2, y3, y4, resX, resY;

			resX = 0;
			resY = 0;

			x1 = 1;
			y1 = 1;
			x2 = -2;
			y2 = -2;
			x3 = 0;
			y3 = -2;
			x4 = -2;
			y4 = 0;

			findIntersectionPoint(x1, y1, x2, y2, x3, y3, x4, y4, resX, resY);

			Assert::AreEqual(resX, -1.0);
			Assert::AreEqual(resY, -1.0);


		}
	};
}

