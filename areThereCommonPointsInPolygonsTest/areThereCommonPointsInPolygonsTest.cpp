#include "pch.h"
#include "CppUnitTest.h"
#include "..\SoftQA_Polygons30\SoftQA_Polygons30.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace areThereCommonPointsInPolygonsTest
{
	TEST_CLASS(areThereCommonPointsInPolygonsTest)
	{
	public:

		TEST_METHOD(areCommon_ZeroCommon_Pos)
		{
			vector<double> vec1 = { 2, 2, 2, 5, 4, 5, 4, 2 };
			vector<double> vec2 = { 1, 3, 1, 4, 3, 4, 3, 3 };

			bool expectedanswer = false;

			bool actualanswer = areThereCommonPointsInPolygons(vec1, vec2);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(areCommon_OneCommon_Pos)
		{
			vector<double> vec1 = { 2, 2, 2, 5, 4, 5, 4, 2 };
			vector<double> vec2 = { 2, 5, 1, 4, 3, 4, 3, 3 };

			bool expectedanswer = false;

			bool actualanswer = areThereCommonPointsInPolygons(vec1, vec2);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(areCommon_TwoCommon_Pos)
		{
			vector<double> vec1 = { 2, 2, 2, 5, 4, 5, 4, 2 };
			vector<double> vec2 = { 2, 5, 4, 2, 3, 4, 3, 3 };

			bool expectedanswer = true;

			bool actualanswer = areThereCommonPointsInPolygons(vec1, vec2);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(areCommon_ThreeCommon_Pos)
		{
			vector<double> vec1 = { 2, 2, 2, 5, 4, 5, 4, 2 };
			vector<double> vec2 = { 2, 5, 4, 5, 4, 2, 3, 3 };

			bool expectedanswer = true;

			bool actualanswer = areThereCommonPointsInPolygons(vec1, vec2);

			Assert::AreEqual(actualanswer, expectedanswer);
		}


		TEST_METHOD(areCommon_ZeroCommon_Neg)
		{
			vector<double> vec1 = { -2, -2, -2, -5, -4, -5, -4, -2 };
			vector<double> vec2 = { -1, -3, -1, -4, -3, -4, -3, -3 };

			bool expectedanswer = false;

			bool actualanswer = areThereCommonPointsInPolygons(vec1, vec2);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(areCommon_OneCommon_Neg)
		{
			vector<double> vec1 = { -2, -2, -2, -5, -4, -5, -4, -2 };
			vector<double> vec2 = { -2, -5, -1, -4, -3, -4, -3, -3 };

			bool expectedanswer = false;

			bool actualanswer = areThereCommonPointsInPolygons(vec1, vec2);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(areCommon_TwoCommon_Neg)
		{
			vector<double> vec1 = { -2, -2, -2, -5, -4, -5, -4, -2 };
			vector<double> vec2 = { -2, -5, -4, -2, -3, -4, -3, -3 };

			bool expectedanswer = true;

			bool actualanswer = areThereCommonPointsInPolygons(vec1, vec2);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(areCommon_ThreeCommon_Neg)
		{
			vector<double> vec1 = { -2, -2, -2, -5, -4, -5, -4, -2 };
			vector<double> vec2 = { -2, -5, -4, -5, -4, -2, -3, -3 };

			bool expectedanswer = true;

			bool actualanswer = areThereCommonPointsInPolygons(vec1, vec2);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(areCommon_AllCommon_Pos)
		{
			vector<double> vec1 = { 2, 2, 2, 5, 4, 5, 4, 2 };
			vector<double> vec2 = { 2, 2, 2, 5, 4, 5, 4, 2 };

			bool expectedanswer = true;

			bool actualanswer = areThereCommonPointsInPolygons(vec1, vec2);

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(areCommon_AllCommon_Neg)
		{
			vector<double> vec1 = { -2, -2, -2, -5, -4, -5, -4, -2 };
			vector<double> vec2 = { -2, -2, -2, -5, -4, -5, -4, -2 };

			bool expectedanswer = true;

			bool actualanswer = areThereCommonPointsInPolygons(vec1, vec2);

			Assert::AreEqual(actualanswer, expectedanswer);
		}
	};
}

