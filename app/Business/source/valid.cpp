#include "pch.h"
#include "valid.h"
namespace Validation
{
	bool IsValidUser(const User& acc)
	{
		return IsValidUsername(acc.username) && IsValidPass(acc.password);
	}
	bool IsValidUsername(const std::string& username)
	{
		std::regex pattern("(^[A-Za-z0-9]+$)");
		return std::regex_match(username, pattern);
	}
	bool IsValidPass(const std::string& pass)
	{
		if (pass.size() < 8) return false;

		std::regex pattern(R"(^[0-9A-Za-z\"<>{}\[\]\\^`|/]+$)");
		return std::regex_match(pass,pattern);
	}
}