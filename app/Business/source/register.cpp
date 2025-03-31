#include "pch.h"
#include "register.h"
#include "create.h"
namespace Register
{
	int RegisterUser(const User& data)
	{
		if (Find::FindUser(data)) return Error::ERROR_EXISTS;
		if (!Validation::IsValidUser(data)) return Error::ERROR_INPUT;
		
		if (Create::CreateUser(data, createUserDir) != Error::SUCCESSFUL) // try to create user at users folder
		{
			return Create::CreateUser(data, "");  // return final crud operation result
		}
		return Error::SUCCESSFUL;
	}
}