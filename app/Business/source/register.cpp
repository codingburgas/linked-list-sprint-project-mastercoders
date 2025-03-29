#include "pch.h"
#include "register.h"
#include "find.h"
#include "valid.h"
namespace Register
{
	int RegisterAccount()
	{
		User data;
		std::cout << "Enter Username: \n";
		std::cin >> data.username;
		std::cout << "Enter Password: \n";
		std::cin >> data.password;

		if (Find::FindUser(data)) return Error::ERROR_EXISTS;
		if (!Validation::IsValidAccount(data)) return Error::ERROR_INPUT;
		// create account
		return Error::SUCCESSFUL;
	}
}