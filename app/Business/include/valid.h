#pragma once

namespace Validation
{
	// return whether a username follows a correct pattern or not
	bool IsValidUsername(const std::string& email);
	// return if pass contains nums,special chars, upper letters and no forbidden chars
	bool IsValidPass(const std::string& pass);
	// returns whether username and pass are valid
	bool IsValidUser(const User& acc);
}