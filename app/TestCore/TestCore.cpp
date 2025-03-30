#include "pch.h"
#include "CppUnitTest.h"
#include "list.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCore
{
	TEST_CLASS(TestCore)
	{
	public:
		
		TEST_METHOD(TestListInsertFront)
		{
			//Arrange
			List<int> ll;
			int expected = 6;
			//Act
			for (int i = 0; i < 5; i++)
			{
				ll.InsertFront(i + 1);
			}
			//Assert

			Assert::AreEqual(expected, ll[1]);
		}
		TEST_METHOD(TestListInsertBack)
		{
			//Arrange
			List<int> ll;
			int expected = 1;
			//Act
			for (int i = 0; i < 5; i++)
			{
				ll.InsertBack(i + 1);
			}
			//Assert

			Assert::AreEqual(expected, ll[1]);
		}
		TEST_METHOD(TestListDelFront)
		{
			//Arrange
			List<int> ll;
			int expected = 2;
			//Act
			for (int i = 0; i < 8; i++)
			{
				ll.InsertBack(i + 1);
			}
			ll.DelFront();

			//Assert
			Assert::AreEqual(expected, ll[1]);
		}
		TEST_METHOD(TestListDelBack1)
		{
			//Arrange
			List<int> ll;
			int expected = 100;
			//Act
			for (int i = 0; i < 8; i++)
			{
				ll.InsertBack(i + 1);
			}
			ll.DelBack();
			ll.InsertBack(100);

			//Assert
			Assert::AreEqual(expected, ll[8]);
		}
		TEST_METHOD(TestListDelBack2)
		{
			//Arrange
			List<int> ll;
			int expected = 0;
			//Act
			for (int i = 0; i < 8; i++)
			{
				ll.InsertBack(i + 1);
			}
			ll.DelBack();
		
			//Assert
			Assert::AreEqual(expected, ll[8]);
		}
		TEST_METHOD(TestListDelAll)
		{
			//Arrange
			List<int> ll;
			int size = 0;
			int expected = 0;

			//Act
			for (int i = 0; i < 4; i++)
			{
				ll.InsertFront(i + 1);
			}
			ll.DelAll();
			size = ll.Size();
			//Assert
			Assert::AreEqual(expected, size);
		}
		TEST_METHOD(TestListIsEmpty)
		{
			//Arrange
			List<int> ll;
			bool expected = 1;

			//Act

			//Assert
			Assert::AreEqual(expected, ll.IsEmpty());
		}
		TEST_METHOD(TestListGet)
		{
			//Arrange
			List<int> ll;
			int expected = 15;
			int sum = 0;

			//Act
			for (int i = 0; i < 5; i++)
				ll.InsertFront(i + 1);
			for (int i = 0; i < 5; i++)
				sum += ll.Get(i + 1);

			//Assert
			Assert::AreEqual(expected, sum);
		}
	};
}
