#include "pch.h"
#include "find.h"
#include "register.h"
namespace Find
{
	bool FindUser(const User& data)
	{
		std::string dirUser = Register::createUserDir + data.username + ".txt";
		return std::filesystem::exists(dirUser); // return if user's data file is found
	}
}