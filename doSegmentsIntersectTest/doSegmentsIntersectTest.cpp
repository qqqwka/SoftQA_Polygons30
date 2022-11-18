#include "pch.h"
#include "CppUnitTest.h"
#include "..\SoftQA_Polygons30\SoftQA_Polygons30.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace doSegmentsIntersectTest
{
	TEST_CLASS(doSegmentsIntersectTest)
	{
	public:

		TEST_METHOD(doIntersect_Straight_True)
		{
			double x1, x2, x3, x4, y1, y2, y3, y4;

			x1 = 2;
			y1 = 1;
			x2 = 2;
			y2 = 4;
			x3 = 0;
			y3 = 2;
			x4 = 3;
			y4 = 2;

			bool expectedanswer = true;

			bool actualanswer = doSegmentsIntersect(x1, y1, x2, y2, x3, y3, x4, y4);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(doIntersect_Straight_False)
		{
			double x1, x2, x3, x4, y1, y2, y3, y4;

			x1 = 5;
			y1 = 1;
			x2 = 5;
			y2 = 4;
			x3 = 0;
			y3 = 2;
			x4 = 3;
			y4 = 2;

			bool expectedanswer = false;

			bool actualanswer = doSegmentsIntersect(x1, y1, x2, y2, x3, y3, x4, y4);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(doIntersect_Diagonal_True)
		{
			double x1, x2, x3, x4, y1, y2, y3, y4;

			x1 = 2;
			y1 = 1;
			x2 = 3;
			y2 = 4;
			x3 = 1;
			y3 = 4;
			x4 = 3;
			y4 = 2;

			bool expectedanswer = true;

			bool actualanswer = doSegmentsIntersect(x1, y1, x2, y2, x3, y3, x4, y4);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(doIntersect_Diagonal_False)
		{
			double x1, x2, x3, x4, y1, y2, y3, y4;

			x1 = 0;
			y1 = 2;
			x2 = 2;
			y2 = 1;
			x3 = 3;
			y3 = 2;
			x4 = 1;
			y4 = 4;

			bool expectedanswer = false;

			bool actualanswer = doSegmentsIntersect(x1, y1, x2, y2, x3, y3, x4, y4);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(doIntersect_NegativeStraight_True)
		{
			double x1, x2, x3, x4, y1, y2, y3, y4;

			x1 = -2;
			y1 = -1;
			x2 = -2;
			y2 = -4;
			x3 = -0;
			y3 = -2;
			x4 = -3;
			y4 = -2;

			bool expectedanswer = true;

			bool actualanswer = doSegmentsIntersect(x1, y1, x2, y2, x3, y3, x4, y4);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(doIntersect_NegativeStraight_False)
		{
			double x1, x2, x3, x4, y1, y2, y3, y4;

			x1 = -5;
			y1 = -1;
			x2 = -5;
			y2 = -4;
			x3 = 0;
			y3 = -2;
			x4 = -3;
			y4 = -2;

			bool expectedanswer = false;

			bool actualanswer = doSegmentsIntersect(x1, y1, x2, y2, x3, y3, x4, y4);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(doIntersect_NegativeDiagonal_True)
		{
			double x1, x2, x3, x4, y1, y2, y3, y4;

			x1 = -2;
			y1 = -1;
			x2 = -3;
			y2 = -4;
			x3 = -1;
			y3 = -4;
			x4 = -3;
			y4 = -2;

			bool expectedanswer = true;

			bool actualanswer = doSegmentsIntersect(x1, y1, x2, y2, x3, y3, x4, y4);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(doIntersect_NegativeDiagonal_False)
		{
			double x1, x2, x3, x4, y1, y2, y3, y4;

			x1 = 0;
			y1 = -2;
			x2 = -2;
			y2 = -1;
			x3 = -3;
			y3 = -2;
			x4 = -1;
			y4 = -4;

			bool expectedanswer = false;

			bool actualanswer = doSegmentsIntersect(x1, y1, x2, y2, x3, y3, x4, y4);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(doIntersect_Straight_Half)
		{
			double x1, x2, x3, x4, y1, y2, y3, y4;

			x1 = 5;
			y1 = 1;
			x2 = 5;
			y2 = 4;
			x3 = 0;
			y3 = -2;
			x4 = -3;
			y4 = -2;

			bool expectedanswer = false;

			bool actualanswer = doSegmentsIntersect(x1, y1, x2, y2, x3, y3, x4, y4);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(doIntersect_DiagonalHalf)
		{
			double x1, x2, x3, x4, y1, y2, y3, y4;

			x1 = -2;
			y1 = -1;
			x2 = -3;
			y2 = -4;
			x3 = 1;
			y3 = 4;
			x4 = 3;
			y4 = 2;

			bool expectedanswer = false;

			bool actualanswer = doSegmentsIntersect(x1, y1, x2, y2, x3, y3, x4, y4);

			Assert::AreEqual(actualanswer, expectedanswer);
		}
	};
}

