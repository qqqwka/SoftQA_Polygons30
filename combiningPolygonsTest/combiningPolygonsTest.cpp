#include "pch.h"
#include "CppUnitTest.h"
#include "..\SoftQA_Polygons30\SoftQA_Polygons30.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace combiningPolygonsTest
{
	TEST_CLASS(combiningPolygonsTest)
	{
	public:

		TEST_METHOD(combining_AllPos_2P)
		{
			vector<double> vec1 = { 1, 1, 1, 2, 1, 3, 1, 4, 3, 4, 3, 1 };
			vector<double> vec2 = { 0, 2, 0, 3, 1, 3, 2, 3, 2, 2, 1, 2 };

			combiningPolygons(vec1, vec2);

			vector<double> testvec = { 1, 1, 1, 2, 0, 2, 0, 3, 1, 3, 1, 4, 3, 4, 3, 1 };

			int expectedanswer = testvec.size();

			int actualanswer = vec1.size();

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(combining_AllNegative_2P)
		{
			vector<double> vec1 = { -1, -1, -1, -2, -1, -3, -1, -4, -3, -4, -3, -1 };
			vector<double> vec2 = { 0, -2, 0, -3, -1, -3, -2, -3, -2, -2, -1, -2 };

			combiningPolygons(vec1, vec2);

			vector<double> testvec = { -1, -1, -1, -2, -0, -2, 0, -3, -1, -3, -1, -4, -3, -4, -3, -1 };

			int expectedanswer = testvec.size();

			int actualanswer = vec1.size();

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(combining_AllPos_4P)
		{
			vector<double> vec1 = { 1, 1, 1, 2, 1, 3, 1, 4, 3, 4, 3, 3, 3, 2, 3, 1 };
			vector<double> vec2 = { 0, 2, 0, 3, 1, 3, 3, 3, 4, 3, 4, 2, 3, 2, 1, 2 };

			combiningPolygons(vec1, vec2);

			vector<double> testvec = { 1, 1, 1, 2, 0, 2, 0, 3, 1, 3, 1, 4, 3, 4, 3, 3, 4, 3, 4, 2, 3, 2, 3, 1 };

			int expectedanswer = testvec.size();

			int actualanswer = vec1.size();

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(combining_AllNegative_4P)
		{
			vector<double> vec1 = { -1, -1, -1, -2, -1, -3, -1, -4, -3, -4, -3, -3, -3, -2, -3, -1 };
			vector<double> vec2 = { 0, -2, 0, -3, -1, -3, -3, -3, -4, -3, -4, -2, -3, -2, -1, -2 };

			combiningPolygons(vec1, vec2);

			vector<double> testvec = { -1, -1, -1, -2, 0, -2, 0, -3, -1, -3, -1, -4, -3, -4, -3, -3, -4, -3, -4, -2, -3, -2, -3, -1 };

			int expectedanswer = testvec.size();

			int actualanswer = vec1.size();

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(combining_AllPos_2P_Double)
		{
			vector<double> vec1 = { 1.1, 1.1, 1.1, 2.1, 1.1, 3.1, 1.1, 4.1, 3.1, 4.1, 3.1, 1.1 };
			vector<double> vec2 = { 0.1, 2.1, 0.1, 3.1, 1.1, 3.1, 2.1, 3.1, 2.1, 2.1, 1.1, 2.1 };

			combiningPolygons(vec1, vec2);

			vector<double> testvec = { 1.1, 1.1, 1.1, 2.1, 0.1, 2.1, 0.1, 3.1, 1.1, 3.1, 1.1, 4.1, 3.1, 4.1, 3.1, 1.1 };

			int expectedanswer = testvec.size();

			int actualanswer = vec1.size();

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(combining_AllNegative_2P_Double)
		{
			vector<double> vec1 = { -1.1, -1.1, -1.1, -2.1, -1.1, -3.1, -1.1, -4.1, -3.1, -4.1, -3.1, -1.1 };
			vector<double> vec2 = { 0.1, -2.1, 0.1, -3.1, -1.1, -3.1, -2.1, -3.1, -2.1, -2.1, -1.1, -2.1 };

			combiningPolygons(vec1, vec2);

			vector<double> testvec = { -1.1, -1.1, -1.1, -2.1, 0.1, -2.1, 0.1, -3.1, -1.1, -3.1, -1.1, -4.1, -3.1, -4.1, -3.1, -1.1 };

			int expectedanswer = testvec.size();

			int actualanswer = vec1.size();

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(combining_AllPos_4P_Double)
		{
			vector<double> vec1 = { 1.1, 1.1, 1.1, 2.1, 1.1, 3.1, 1.1, 4.1, 3.1, 4.1, 3.1, 3.1, 3.1, 2.1, 3.1, 1.1 };
			vector<double> vec2 = { 0.1, 2.1, 0.1, 3.1, 1.1, 3.1, 3.1, 3.1, 4.1, 3.1, 4.1, 2.1, 3.1, 2.1, 1.1, 2.1 };

			combiningPolygons(vec1, vec2);

			vector<double> testvec = { 1.1, 1.1, 1.1, 2.1, 0.1, 2.1, 0.1, 3.1, 1.1, 3.1, 1.1, 4.1, 3.1, 4.1, 3.1, 3.1, 4.1, 3.1, 4.1, 2.1, 3.1, 2.1, 3.1, 1.1 };

			int expectedanswer = testvec.size();

			int actualanswer = vec1.size();

			Assert::AreEqual(actualanswer, expectedanswer);
		}

		TEST_METHOD(combining_AllNegative_4P_Double)
		{
			vector<double> vec1 = { -1.1, -1.1, -1.1, -2.1, -1.1, -3.1, -1.1, -4.1, -3.1, -4.1, -3.1, -3.1, -3.1, -2.1, -3.1, -1.1 };
			vector<double> vec2 = { 0.1, -2.1, 0.1, -3.1, -1.1, -3.1, -3.1, -3.1, -4.1, -3.1, -4.1, -2.1, -3.1, -2.1, -1.1, -2.1 };

			combiningPolygons(vec1, vec2);

			vector<double> testvec = { -1.1, -1.1, -1.1, -2.1, 0.1, -2.1, 0.1, -3.1, -1.1, -3.1, -1.1, -4.1, -3.1, -4.1, -3.1, -3.1, -4.1, -3.1, -4.1, -2.1, -3.1, -2.1, -3.1, -1.1 };

			int expectedanswer = testvec.size();

			int actualanswer = vec1.size();

			Assert::AreEqual(actualanswer, expectedanswer);
		}
	};
}

