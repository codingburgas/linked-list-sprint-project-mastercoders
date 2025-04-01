#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestAccess
{
	TEST_CLASS(TestAccess)
	{
	public:
		
		TEST_METHOD(TestCreateUser)
		{
			//Arrange
			User testUser;
			testUser.username = "Daniel";
			testUser.password = "password123";
			int actual;
			int expected = Error::SUCCESSFUL;

			//Act
			actual = Create::CreateUser(testUser, "");

			//Assert
			Assert::AreEqual(expected, actual);
			
		}
	};
}
