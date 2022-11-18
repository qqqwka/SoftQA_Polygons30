#include "pch.h"
#include "CppUnitTest.h"
#include "..\SoftQA_Polygons30\SoftQA_Polygons30.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace isPolygonConvexTest
{
	TEST_CLASS(isPolygonConvexTest)
	{
	public:

		TEST_METHOD(isConvex_FiveVertices_True)
		{
			vector<double> test1;

			test1 = { 0, 0, 0, 1, 1, 3, 2, 2, 2, 0 };

			bool expectedanswer = true;

			bool actualanswer = isPolygonConvex(test1);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(isConvex_FiveVertices_False)
		{
			vector<double> test1;

			test1 = { 0, 0, 0, 1, 1, 1, 2, 2, 2, 0 };

			bool expectedanswer = false;

			bool actualanswer = isPolygonConvex(test1);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(isConvex_ManyVertices_False)
		{
			vector<double> test1;

			test1 = { 0, 1, 0, 2, 1, 3, 2, 2, 2, 1, 1, 2 };

			bool expectedanswer = false;

			bool actualanswer = isPolygonConvex(test1);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(isConvex_ManyVertices_True)
		{
			vector<double> test1;

			test1 = { 0, 1, 0, 2, 1, 3, 2, 2, 2, 1, 1, 0 };

			bool expectedanswer = true;

			bool actualanswer = isPolygonConvex(test1);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(isConvex_FiveNegative_True)
		{
			vector<double> test1;

			test1 = { 0, 0, 0, -1, -1, -3, -2, -2, -2, 0 };

			bool expectedanswer = true;

			bool actualanswer = isPolygonConvex(test1);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(isConvex_FiveNegative_False)
		{
			vector<double> test1;

			test1 = { 0, 0, 0, -1, -1, -1, -2, -2, -2, 0 };

			bool expectedanswer = false;

			bool actualanswer = isPolygonConvex(test1);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(isConvex_ManyNegatives_False)
		{
			vector<double> test1;

			test1 = { 0, -1, 0, -2, -1, -3, -2, -2, -2, -1, -1, -2 };

			bool expectedanswer = false;

			bool actualanswer = isPolygonConvex(test1);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(isConvex_ManyNegatives_True)
		{
			vector<double> test1;

			test1 = { 0, -1, 0, -2, -1, -3, -2, -2, -2, -1, -1, 0 };

			bool expectedanswer = true;

			bool actualanswer = isPolygonConvex(test1);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(isConvex_HalfNeg_HalfPos_True)
		{
			vector<double> test1;

			test1 = { -1, 0, -1, 1, 0, 2, 1, 1, 1, 0, 0, -1 };

			bool expectedanswer = true;

			bool actualanswer = isPolygonConvex(test1);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(isConvex_HalfPos_HalfPos_False)
		{
			vector<double> test1;

			test1 = { 0, -1, 0, -2, -1, -3, 2, 2, 2, 1, 1, 0 };

			bool expectedanswer = false;

			bool actualanswer = isPolygonConvex(test1);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(isConvex_AllDouble_True)
		{
			vector<double> test1;

			test1 = { 0.2, 1.3, 0.5, 2.6, 1.7, 3.8, 2.9, 2.0, 2.1, 1.2, 1.3, 0.4 };

			bool expectedanswer = true;

			bool actualanswer = isPolygonConvex(test1);

			Assert::AreEqual(actualanswer, expectedanswer);
		}
	};
}

