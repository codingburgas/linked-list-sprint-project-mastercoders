#include "pch.h"
#include "auth.h"
#include "create.h"
namespace Auth
{
	int RegisterUser(const User& data)
	{
		if (Find::FindUser(data,createUserDir + "user") || Find::FindUser(data, "user")) return Error::ERROR_EXISTS;
		if (!Validation::IsValidUser(data)) return Error::ERROR_INPUT;
		
		if (Create::CreateUser(data, createUserDir + "user") != Error::SUCCESSFUL) // try to create user at users folder
		{
			return Create::CreateUser(data, "user");  // return final crud operation result
		}
		return Error::SUCCESSFUL;
	}
	int LogUser(const User& data)
	{
		std::string dir; // dir of user file
		if (Find::FindUser(data,createUserDir + "user"))
		{
			dir = createUserDir + "user" + data.username + ".txt"; // data folder user file dir
		}
		else if (Find::FindUser(data, "user"))
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
}