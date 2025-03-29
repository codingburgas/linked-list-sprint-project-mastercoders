#include "pch.h"
#include "valid.h"
namespace Validation
{
	bool IsValidAccount(const User& acc)
	{
		return IsValidUsername(acc.username) && IsValidPass(acc.password);
	}
	bool IsValidUsername(const std::string& username)
	{
		std::regex pattern("(^[A-Za-z0-9]+"), forbidden(R"([-_.~!$ & () *= +:; #\"<>{}\[\]\\^`|/])");
		return std::regex_match(username, pattern) && !std::regex_match(username,forbidden) && username.size() > 8;
	}
	bool IsValidPass(const std::string& pass)
	{
		if (pass.size() < 8) return false;

		std::regex num("([0-9])"), upper("([A-Z])"), forbidden("([-_.~!$ & () *= +:; #])"), permited(R"([\"<>{}\[\]\\^`|/])");

		if (std::regex_match(pass, num) && std::regex_match(pass, upper) && std::regex_match(pass, permited) && !std::regex_match(pass, forbidden))
			return false;
		return true;
	}
}