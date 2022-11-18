#include "pch.h"
#include "CppUnitTest.h"
#include "..\SoftQA_Polygons30\SoftQA_Polygons30.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace isPointInPolygonTest
{
	TEST_CLASS(isPointInPolygonTest)
	{
	public:

		TEST_METHOD(InPolygon_SimpleSquare_True)
		{
			double varX, varY;

			varX = 5;
			varY = 5;

			vector<double> test = { 0, 0, 0, 10, 10, 10, 10, 0 };

			bool expectedanswer = true;

			bool actualanswer = isPointInPolygon(varX, varY, test);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(InPolygon_SimpleSquare_False)
		{
			double varX, varY;

			varX = 20;
			varY = 5;

			vector<double> test = { 0, 0, 0, 10, 10, 10, 10, 0 };

			bool expectedanswer = false;

			bool actualanswer = isPointInPolygon(varX, varY, test);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(InPolygon_SimpleTriangle_True)
		{
			double varX, varY;

			varX = 10;
			varY = 10;

			vector<double> test = { 0, 0, 20, 20, 40, 0 };

			bool expectedanswer = true;

			bool actualanswer = isPointInPolygon(varX, varY, test);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(InPolygon_SimpleTriangle_False)
		{
			double varX, varY;

			varX = 10;
			varY = 35;

			vector<double> test = { 0, 0, 20, 20, 40, 0 };

			bool expectedanswer = false;

			bool actualanswer = isPointInPolygon(varX, varY, test);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(InPolygon_SimplePentagon_True)
		{
			double varX, varY;

			varX = 14;
			varY = 2;

			vector<double> test = { 0, 0, 0, 10, 10, 20, 20, 10, 20, 0 };

			bool expectedanswer = true;

			bool actualanswer = isPointInPolygon(varX, varY, test);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(InPolygon_SimplePentagon_False)
		{
			double varX, varY;

			varX = -20;
			varY = 2;

			vector<double> test = { 0, 0, 0, 10, 10, 20, 20, 10, 20, 0 };

			bool expectedanswer = false;

			bool actualanswer = isPointInPolygon(varX, varY, test);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(InPolygon_NegSquare_True)
		{
			double varX, varY;

			varX = -5;
			varY = -5;

			vector<double> test = { 0, 0, 0, -10, -10, -10, -10, 0 };

			bool expectedanswer = true;

			bool actualanswer = isPointInPolygon(varX, varY, test);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(InPolygon_NegativeSquare_False)
		{
			double varX, varY;

			varX = 20;
			varY = 5;

			vector<double> test = { 0, 0, 0, -10, -10, -10, -10, 0 };

			bool expectedanswer = false;

			bool actualanswer = isPointInPolygon(varX, varY, test);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(InPolygon_Hexagon_True)
		{
			double varX, varY;

			varX = 1;
			varY = 1;

			vector<double> test = { 0, 1, 0, 2, 1, 3, 2, 2, 2, 1, 1, 0 };

			bool expectedanswer = true;

			bool actualanswer = isPointInPolygon(varX, varY, test);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(InPolygon_Hexagon_False)
		{
			double varX, varY;

			varX = 0;
			varY = 0;

			vector<double> test = { 0, 1, 0, 2, 1, 3, 2, 2, 2, 1, 1, 0 };

			bool expectedanswer = false;

			bool actualanswer = isPointInPolygon(varX, varY, test);

			Assert::AreEqual(actualanswer, expectedanswer);
		}
	};
}
