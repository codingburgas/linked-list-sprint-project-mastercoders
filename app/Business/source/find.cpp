#include "pch.h"
#include "find.h"
#pragma warning(disable : 4996)
namespace Find
{
	bool FindUser(const User& data)
	{
		std::string dirUser = "Data/Users/user" + data.username + ".txt";
		return std::filesystem::exists(dirUser); // return if user's data file is found
	}
}