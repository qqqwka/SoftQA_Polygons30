#include "pch.h"
#include "CppUnitTest.h"
#include "..\SoftQA_Polygons30\SoftQA_Polygons30.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace intersectionPointInsertTest
{
	TEST_CLASS(intersectionPointInsertTest)
	{
	public:

		TEST_METHOD(PointInsert2_AllPositive_Vec1)
		{
			vector<double> veci1 = { 2, 2, 2, 5, 4, 5, 4, 2, 2, 2 };
			vector<double> vecj1 = { 1, 3, 1, 4, 3, 4, 3, 3, 1, 3 };
			vector<double> veci2 = { 2, 2, 2, 5, 4, 5, 4, 2, 2, 2 };
			vector<double> vecj2 = { 1, 3, 1, 4, 3, 4, 3, 3, 1, 3 };
			//vector<double> veci2 = { 2, 2, 2, 3, 2, 4, 2, 5, 4, 5, 4, 2, 2, 2 };
			//vector<double> vecj2 = { 1, 3, 1, 4, 2, 4, 3, 4, 3, 3, 2, 3, 1, 3 };

			intersectionPointInsert(veci1, vecj1, veci2, vecj2);

			vector<double> veci2expect = { 2, 2, 2, 3, 2, 4, 2, 5, 4, 5, 4, 2, 2, 2 };

			Assert::AreEqual(veci2.size(), veci2expect.size());

		}

		TEST_METHOD(PointInsert2_AllPositive_Vec2)
		{
			vector<double> veci1 = { 2, 2, 2, 5, 4, 5, 4, 2, 2, 2 };
			vector<double> vecj1 = { 1, 3, 1, 4, 3, 4, 3, 3, 1, 3 };
			vector<double> veci2 = { 2, 2, 2, 5, 4, 5, 4, 2, 2, 2 };
			vector<double> vecj2 = { 1, 3, 1, 4, 3, 4, 3, 3, 1, 3 };
			//vector<double> veci2 = { 2, 2, 2, 3, 2, 4, 2, 5, 4, 5, 4, 2, 2, 2 };
			//vector<double> vecj2 = { 1, 3, 1, 4, 2, 4, 3, 4, 3, 3, 2, 3, 1, 3 };

			intersectionPointInsert(veci1, vecj1, veci2, vecj2);

			vector<double> vecj2expect = { 1, 3, 1, 4, 2, 4, 3, 4, 3, 3, 2, 3, 1, 3 };

			Assert::AreEqual(vecj2.size(), vecj2expect.size());

		}

		TEST_METHOD(PointInsert2_AllNegative_Vec1)
		{
			vector<double> veci1 = { -2, -2, -2, -5, -4, -5, -4, -2, -2, -2 };
			vector<double> vecj1 = { -1, -3, -1, -4, -3, -4, -3, -3, -1, -3 };
			vector<double> veci2 = { -2, -2, -2, -5, -4, -5, -4, -2, -2, -2 };
			vector<double> vecj2 = { -1, -3, -1, -4, -3, -4, -3, -3, -1, -3 };
			//vector<double> veci2 = { -2, -2, -2, -3, -2, -4, -2, -5, -4, -5, -4, -2, -2, -2 };
			//vector<double> vecj2 = { -1, -3, -1, -4, -2, -4, -3, -4, -3, -3, -2, -3, -1, -3 };

			intersectionPointInsert(veci1, vecj1, veci2, vecj2);

			vector<double> veci2expect = { -2, -2, -2, -3, -2, -4, -2, -5, -4, -5, -4, -2, -2, -2 };

			Assert::AreEqual(veci2.size(), veci2expect.size());

		}

		TEST_METHOD(PointInsert2_AllNegative_Vec2)
		{
			vector<double> veci1 = { -2, -2, -2, -5, -4, -5, -4, -2, -2, -2 };
			vector<double> vecj1 = { -1, -3, -1, -4, -3, -4, -3, -3, -1, -3 };
			vector<double> veci2 = { -2, -2, -2, -5, -4, -5, -4, -2, -2, -2 };
			vector<double> vecj2 = { -1, -3, -1, -4, -3, -4, -3, -3, -1, -3 };
			//vector<double> veci2 = { -2, -2, -2, -3, -2, -4, -2, -5, -4, -5, -4, -2, -2, -2 };
			//vector<double> vecj2 = { -1, -3, -1, -4, -2, -4, -3, -4, -3, -3, -2, -3, -1, -3 };

			intersectionPointInsert(veci1, vecj1, veci2, vecj2);

			vector<double> vecj2expect = { -1, -3, -1, -4, -2, -4, -3, -4, -3, -3, -2, -3, -1, -3 };

			Assert::AreEqual(vecj2.size(), vecj2expect.size());

		}

		TEST_METHOD(PointInsert4_AllPositive_Vec1)
		{
			vector<double> veci1 = { 2, 2, 2, 5, 4, 5, 4, 2, 2, 2 };
			vector<double> vecj1 = { 1, 3, 1, 4, 5, 4, 5, 3, 1, 3 };
			vector<double> veci2 = { 2, 2, 2, 5, 4, 5, 4, 2, 2, 2 };
			vector<double> vecj2 = { 1, 3, 1, 4, 5, 4, 5, 3, 1, 3 };
			//vector<double> veci2 = { 2, 2, 2, 3, 2, 4, 2, 5, 4, 5, 4, 4, 4, 3, 4, 2, 2, 2 };
			//vector<double> vecj2 = { 1, 3, 1, 4, 2, 4, 4, 4, 5, 4, 5, 3, 4, 3, 2, 3, 1, 3 };

			intersectionPointInsert(veci1, vecj1, veci2, vecj2);

			vector<double> veci2expect = { 2, 2, 2, 3, 2, 4, 2, 5, 4, 5, 4, 4, 4, 3, 4, 2, 2, 2 };

			Assert::AreEqual(veci2.size(), veci2expect.size());

		}

		TEST_METHOD(PointInsert4_AllPositive_Vec2)
		{
			vector<double> veci1 = { 2, 2, 2, 5, 4, 5, 4, 2, 2, 2 };
			vector<double> vecj1 = { 1, 3, 1, 4, 5, 4, 5, 3, 1, 3 };
			vector<double> veci2 = { 2, 2, 2, 5, 4, 5, 4, 2, 2, 2 };
			vector<double> vecj2 = { 1, 3, 1, 4, 5, 4, 5, 3, 1, 3 };
			//vector<double> veci2 = { 2, 2, 2, 3, 2, 4, 2, 5, 4, 5, 4, 4, 4, 3, 4, 2, 2, 2 };
			//vector<double> vecj2 = { 1, 3, 1, 4, 2, 4, 4, 4, 5, 4, 5, 3, 4, 3, 2, 3, 1, 3 };

			intersectionPointInsert(veci1, vecj1, veci2, vecj2);

			vector<double> vecj2expect = { 1, 3, 1, 4, 2, 4, 4, 4, 5, 4, 5, 3, 4, 3, 2, 3, 1, 3 };

			Assert::AreEqual(vecj2.size(), vecj2expect.size());

		}

		TEST_METHOD(PointInsert4_AllNegative_Vec1)
		{
			vector<double> veci1 = { 2, 2, 2, 5, 4, 5, 4, 2, 2, 2 };
			vector<double> vecj1 = { 1, 3, 1, 4, 5, 4, 5, 3, 1, 3 };
			vector<double> veci2 = { 2, 2, 2, 5, 4, 5, 4, 2, 2, 2 };
			vector<double> vecj2 = { 1, 3, 1, 4, 5, 4, 5, 3, 1, 3 };
			//vector<double> veci2 = { 2, 2, 2, 3, 2, 4, 2, 5, 4, 5, 4, 4, 4, 3, 4, 2, 2, 2 };
			//vector<double> vecj2 = { 1, 3, 1, 4, 2, 4, 4, 4, 5, 4, 5, 3, 4, 3, 2, 3, 1, 3 };

			intersectionPointInsert(veci1, vecj1, veci2, vecj2);

			vector<double> veci2expect = { 2, 2, 2, 3, 2, 4, 2, 5, 4, 5, 4, 4, 4, 3, 4, 2, 2, 2 };

			Assert::AreEqual(veci2.size(), veci2expect.size());

		}

		TEST_METHOD(PointInsert4_AllNegative_Vec2)
		{
			vector<double> veci1 = { -2, -2, -2, -5, -4, -5, -4, -2, -2, -2 };
			vector<double> vecj1 = { -1, -3, -1, -4, -5, -4, -5, -3, -1, -3 };
			vector<double> veci2 = { -2, -2, -2, -5, -4, -5, -4, -2, -2, -2 };
			vector<double> vecj2 = { -1, -3, -1, -4, -5, -4, -5, -3, -1, -3 };
			//vector<double> veci2 = { -2, -2, -2, -3, -2, -4, -2, -5, -4, -5, -4, -4, -4, -3, -4, -2, -2, -2 };
			//vector<double> vecj2 = { -1, -3, -1, -4, -2, -4, -4, -4, -5, -4, -5, -3, -4, -3, -2, -3, -1, -3 };

			intersectionPointInsert(veci1, vecj1, veci2, vecj2);

			vector<double> vecj2expect = { -1, -3, -1, -4, -2, -4, -4, -4, -5, -4, -5, -3, -4, -3, -2, -3, -1, -3 };

			Assert::AreEqual(vecj2.size(), vecj2expect.size());

		}
	};
}

