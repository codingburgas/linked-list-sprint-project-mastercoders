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
		std::string dir; // dir of user file
		if (Find::FindUser(data, Register::createUserDir))
		{
			dir = Register::createUserDir + data.username + ".txt"; // data folder user file dir
		}
		else if (Find::FindUser(data, ""))
		{
			dir = "user" + data.username + ".txt"; // default user file dir
		}
		else
		{
			return Error::ERROR_FAILED; // return if operation has failed
		}

		std::ifstream handle(dir); // handle to user file
		std::string line;
		while (std::getline(handle, line))
		{
			if (line == data.password) // check if any line matches entered password
				return Error::SUCCESSFUL;
		}
		return Error::ERROR_FAILED; // return failed if password is incorrect
	}
	int SignUp(const User& data)
	{
		return Register::RegisterUser(data); // try to create user and return results
	}
}
