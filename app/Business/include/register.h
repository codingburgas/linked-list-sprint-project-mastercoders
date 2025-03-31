#pragma once

namespace Register
{
	// register a user: name,pass
	int RegisterUser(const User& data);
	//user folder dir
	const std::string createUserDir = R"(..\Access\Data\Users\user)";
}