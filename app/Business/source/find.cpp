#include "pch.h"
#include "find.h"
#pragma warning(disable : 4996)

namespace Find
{
	bool FindUser(User data)
	{
		std::string dir = "./Data/Users/user" + data.username + ".txt";
		return !access(dir.c_str(),0); // return if user's data file is found
	}
}