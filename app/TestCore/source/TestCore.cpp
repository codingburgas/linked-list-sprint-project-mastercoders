#include "pch.h"
#include "CppUnitTest.h"
#include "list.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCore
{
	
	TEST_CLASS(TestList)
	{
	public:
		
		TEST_METHOD(TestListInsertFront)
		{
			//Arrange
			List<int> ll;
			int expected = 5;
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
		TEST_METHOD(TestListEventInsertData)
		{
			//Arrange
			ListEvent le;
			EventData data[3];
			std::string expected = "019";

			data[0].name = "event1";
			data[1].name = "event2";
			data[2].name = "event3";

			data[0].otherData = data[1].otherData = data[2].otherData = {};

			data[0].topic = "topic1";
			data[1].topic = "topic2";
			data[2].topic = "topic3";

			data[0].year = 1909;
			data[1].year = 1900;
			data[2].year = 1901;

			//Act
			for (int i = 0; i < 3; i++)
				le.InsertDate(data[i]);

			char digits[3] = { (le.Get(1).year % 10) + '0',(le.Get(2).year % 10),(le.Get(3).year % 10) };
			std::string actual;
			for (int i = 0; i < 3; i++)
				actual.push_back(digits[i]);
			//Assert
			Assert::AreEqual(expected, actual);
		}
	};

}
