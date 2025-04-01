#include "pch.h"
#include "process.h"
namespace Process
{
	int InputLogSign(const int& mode)
	{
		User userNew; // user data struct

		std::cout << "\nEnter username\n:";
		std::cin >> userNew.username;

		std::cout << "\nEnter password\n:";
		std::cin >> userNew.password;

		if (mode == 1)
		{
			return LogIn(userNew); // return log in result
		}
		else
		{
			return SignUp(userNew); // return sign up result
		}

		return -1; // prevent non-control void error
	}
	int LogIn(const User& data)
	{
		return Auth::LogUser(data);
	}
	int SignUp(const User& data)
	{
		return Auth::RegisterUser(data); // try to create user and return results
	}
}
