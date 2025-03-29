#include "pch.h"
#include "register.h"
#include "find.h"
#include "valid.h"
namespace Register
{
	int RegisterAccount(const User& data)
	{
		if (Find::FindUser(data)) return Error::ERROR_EXISTS;
		if (!Validation::IsValidAccount(data)) return Error::ERROR_INPUT;
		// create account
		return Error::SUCCESSFUL;
	}
}