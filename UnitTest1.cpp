#include "pch.h"
#include "CppUnitTest.h"
#include "Push.h"
#include "Vect.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(FileNotOpenVertexTest)
		{
			Graph myGr;
			try
			{
				myGr.addVertexs("test.txt");
			}
			catch (invalid_argument error)
			{
				Assert::AreEqual("Error - file not open", error.what());
			}

		}
		TEST_METHOD(EdgesTestErrorVer)
		{
			Graph myGr;
			try
			{
				myGr.addEdge("C:\\Users\\Art\\Desktop\\test.txt");
			}
			catch (out_of_range error)
			{
				Assert::AreEqual("Error - Vertex no creates", error.what());
			}
		}
		TEST_METHOD(FileNotOpenEdgesTest)
		{
			Graph myGr;
			myGr.addVertexs("C:\\Users\\Art\\Desktop\\test.txt");
			try
			{
				myGr.addEdge("test.txt");
			}
			catch (invalid_argument error)
			{
				Assert::AreEqual("Error - file not open", error.what());
			}
		}

		TEST_METHOD(VertexNoCreateTestMax)
		{
			Graph myGr;
			try
			{
				myGr.getMaxFlow();
			}
			catch (out_of_range error)
			{
				Assert::AreEqual("Error - Vertex no create", error.what());
			}
		}

		TEST_METHOD(EdgesNoCreateTestMax)
		{
			Graph myGr;
			myGr.addVertexs("C:\\Users\\Art\\Desktop\\test.txt");
			try
			{
				myGr.getMaxFlow();
			}
			catch (out_of_range error)
			{
				Assert::AreEqual("Error - Edges no create", error.what());
			}
		}
		TEST_METHOD(TrueWorkTest)
		{
			Graph myGr;
			myGr.addVertexs("C:\\Users\\Art\\Desktop\\test.txt");
			myGr.addEdge("C:\\Users\\Art\\Desktop\\test.txt");
			Assert::AreEqual(5, myGr.getMaxFlow());
		}
	};
}