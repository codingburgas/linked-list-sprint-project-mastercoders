#include "pch.h"
#include "register.h"
#include "find.h"
#include "valid.h"
namespace Register
{
	int RegisterUser(const User& data)
	{
		if (Find::FindUser(data)) return Error::ERROR_EXISTS;
		if (!Validation::IsValidUser(data)) return Error::ERROR_INPUT;
		
		return Create::CreateUser(data); // return crud operation result
	}
}