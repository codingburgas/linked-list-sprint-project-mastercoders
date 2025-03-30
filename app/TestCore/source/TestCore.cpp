#include "pch.h"
#include "CppUnitTest.h"
#include "list.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCore
{
	
	TEST_CLASS(TestList)
	{
	public:
		
		TEST_METHOD(TestInsertFront)
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
		TEST_METHOD(TestInsertBack)
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
		TEST_METHOD(TestDelFront)
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
		TEST_METHOD(TestDelBack1)
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
		TEST_METHOD(TestDelBack2)
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
		TEST_METHOD(TestDelAll)
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
		TEST_METHOD(TestIsEmpty)
		{
			//Arrange
			List<int> ll;
			bool expected = 1;

			//Act

			//Assert
			Assert::AreEqual(expected, ll.IsEmpty());
		}
		TEST_METHOD(TestGet)
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
		TEST_METHOD(TestInsertDate)
		{
			//Arrange
			ListEvent le;
			EventData data[3];
			std::string expected = "019";

			data[0].year = 1909;
			data[1].year = 1900;
			data[2].year = 1901;

			//Act
			for (int i = 0; i < 3; i++)
				le.InsertDate(data[i]);
			
			char digits[3] = { (le.Get(1).year % 10) + '0',(le.Get(2).year % 10)+'0',(le.Get(3).year % 10)+'0'};
			std::string actual;
			for (int i = 0; i < 3; i++)
				actual.push_back(digits[i]);
			//Assert
			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(TestEventList)
		{
			//Arrange
			ListEvent le;
			EventData data[3];
			data[0].topic = "FirstWar";
			data[1].topic = "SecondWar";
			data[2].topic = "FirstWar";
			bool expected = true;
			bool actual = true;

			std::string expectedTopic = "FirstWar";
			//Act
			for (int i = 0; i < 3; i++)
				le.InsertBack(data[i]);

			ListEvent leRes = le.EventList("FirstWar");
			for (int i = 0; i < leRes.Size(); i++)
			{
				if (leRes.Get(i + 1).topic != expectedTopic)
					actual = false;
			}
			
			//Assert
			Assert::AreEqual(expected, actual);
		}
	};

}
