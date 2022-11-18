#include "pch.h"
#include "CppUnitTest.h"
#include "..\SoftQA_Polygons30\SoftQA_Polygons30.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace isIntersectionPointAlreadyInVectorTest
{
	TEST_CLASS(isIntersectionPointAlreadyInVectorTest)
	{
	public:

		TEST_METHOD(Already_PositivePoint_True)
		{
			vector<double> vec1 = { 1, 2, 3, 3, 5, 6 };
			vector<double> vec2 = { 1, 2, 3, 3, 5, 6 };

			double rX, rY;
			rX = 3;
			rY = 3;

			bool expectedanswer = true;

			bool actualanswer = isIntersectionPointAlreadyInVector(vec1, vec2, rX, rY);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(Already_NegativePoint_True)
		{
			vector<double> vec1 = { 1, 2, -3, -3, 5, 6 };
			vector<double> vec2 = { 1, 2, 3, 3, 5, 6 };

			double rX, rY;
			rX = -3;
			rY = -3;

			bool expectedanswer = true;

			bool actualanswer = isIntersectionPointAlreadyInVector(vec1, vec2, rX, rY);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(Already_PositivePoint_False)
		{
			vector<double> vec1 = { 1, 2, 4, 4, 5, 6 };
			vector<double> vec2 = { 1, 2, 3, 3, 5, 6 };

			double rX, rY;
			rX = 3;
			rY = 3;

			bool expectedanswer = false;

			bool actualanswer = isIntersectionPointAlreadyInVector(vec1, vec2, rX, rY);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(Already_NegativePoint_False)
		{
			vector<double> vec1 = { 1, 2, 3, 3, 5, 6 };
			vector<double> vec2 = { 1, 2, 3, 3, 5, 6 };

			double rX, rY;
			rX = -3;
			rY = -3;

			bool expectedanswer = false;

			bool actualanswer = isIntersectionPointAlreadyInVector(vec1, vec2, rX, rY);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(Already_NegativeX_True)
		{
			vector<double> vec1 = { 1, 2, -3, 3, 5, 6 };
			vector<double> vec2 = { 1, 2, 3, 3, 5, 6 };

			double rX, rY;
			rX = -3;
			rY = 3;

			bool expectedanswer = true;

			bool actualanswer = isIntersectionPointAlreadyInVector(vec1, vec2, rX, rY);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(Already_NegativeY_True)
		{
			vector<double> vec1 = { 1, 2, 3, -3, 5, 6 };
			vector<double> vec2 = { 1, 2, 3, 3, 5, 6 };

			double rX, rY;
			rX = 3;
			rY = -3;

			bool expectedanswer = true;

			bool actualanswer = isIntersectionPointAlreadyInVector(vec1, vec2, rX, rY);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(Already_NegativeVec_True)
		{
			vector<double> vec1 = { -1, -2, -3, -3, -5, -6 };
			vector<double> vec2 = { 1, 2, 3, 3, 5, 6 };

			double rX, rY;
			rX = -3;
			rY = -3;

			bool expectedanswer = true;

			bool actualanswer = isIntersectionPointAlreadyInVector(vec1, vec2, rX, rY);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(Already_NegativeVec_False)
		{
			vector<double> vec1 = { -1, -2, -3, -3, -5, -6 };
			vector<double> vec2 = { 1, 2, 3, 3, 5, 6 };

			double rX, rY;
			rX = -4;
			rY = -4;

			bool expectedanswer = false;

			bool actualanswer = isIntersectionPointAlreadyInVector(vec1, vec2, rX, rY);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(Already_PositivePointDouble_True)
		{
			vector<double> vec1 = { 1.9, 2.1, 3.4, 3.7, 5.7, 6.6 };
			vector<double> vec2 = { 1, 2, 3, 3, 5, 6 };

			double rX, rY;
			rX = 3.4;
			rY = 3.7;

			bool expectedanswer = true;

			bool actualanswer = isIntersectionPointAlreadyInVector(vec1, vec2, rX, rY);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(Already_PositivePointDouble_False)
		{
			vector<double> vec1 = { 1.9, 2.1, 3.4, 3.3, 5.7, 6.6 };
			vector<double> vec2 = { 1, 2, 3, 3, 5, 6 };

			double rX, rY;
			rX = 3.5;
			rY = 3.6;

			bool expectedanswer = false;

			bool actualanswer = isIntersectionPointAlreadyInVector(vec1, vec2, rX, rY);

			Assert::AreEqual(actualanswer, expectedanswer);
		}
	};
}

