#include "pch.h"
#include "CppUnitTest.h"
#include "..\SoftQA_Polygons30\SoftQA_Polygons30.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CrossProductTest
{
	TEST_CLASS(CrossProductTest)
	{
	public:

		TEST_METHOD(CrossTest_PositiveCoordinates)
		{
			int answer1;

			vector<double> test1 = { 3, 2, 3, 4, 6, 6 };

			answer1 = CrossProduct(test1);

			Assert::AreEqual(answer1, -6);
		}

		TEST_METHOD(CrossTest_NegativeCoordinates)
		{
			int answer1;

			vector<double> test1 = { -2, -1, -3, -2, -5, -3 };

			answer1 = CrossProduct(test1);

			Assert::AreEqual(answer1, -1);
		}

		TEST_METHOD(CrossTest_NegativeXs)
		{
			int answer1;

			vector<double> test1 = { -2, 1, -3, 2, -5, 3 };

			answer1 = CrossProduct(test1);

			Assert::AreEqual(answer1, 1);
		}

		TEST_METHOD(CrossTest_NegativeYs)
		{
			int answer1;

			vector<double> test1 = { 2, -1, 3, -2, 5, -3 };

			answer1 = CrossProduct(test1);

			Assert::AreEqual(answer1, 1);
		}

		TEST_METHOD(CrossTest_HalfNegative_HalfPositive)
		{
			int answer1;

			vector<double> test1 = { -2, -1, -3, 2, 5, 3 };

			answer1 = CrossProduct(test1);

			Assert::AreEqual(answer1, -25);
		}

		TEST_METHOD(CrossTest_HalfPositive_HalfNegative)
		{
			int answer1;

			vector<double> test1 = { 2, 1, 3, -2, -5, -3 };

			answer1 = CrossProduct(test1);

			Assert::AreEqual(answer1, -25);
		}

		TEST_METHOD(CrossTest_OnePointIsZero)
		{
			int answer1;

			vector<double> test1 = { 2, 1, 0, 0, 5, 3 };

			answer1 = CrossProduct(test1);

			Assert::AreEqual(answer1, -1);
		}

		TEST_METHOD(CrossTest_XsAreZero)
		{
			int answer1;

			vector<double> test1 = { 0, 1, 0, 2, 0, 3 };

			answer1 = CrossProduct(test1);

			Assert::AreEqual(answer1, 0);
		}

		TEST_METHOD(CrossTest_YsAreZero)
		{
			int answer1;

			vector<double> test1 = { 2, 0, 3, 0, 5, 0 };

			answer1 = CrossProduct(test1);

			Assert::AreEqual(answer1, 0);
		}

		TEST_METHOD(CrossTest_CoordinatesAreDouble)
		{
			int answer1;

			vector<double> test1 = { 2.1, 0.5, 3.1, 0.7, 5.9, 0.2 };

			answer1 = CrossProduct(test1);

			Assert::AreEqual(answer1, -1);
		}
	};
}

