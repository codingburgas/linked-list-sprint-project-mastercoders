#include "pch.h"
#include "create.h"

namespace Create
{
	int CreateAccount(const User& data)
	{
		std::ofstream handle("Data/Users/user" + data.username + ".txt");
		if (!handle.is_open())
			return Error::ERROR_STREAM;

		handle << data.username << std::endl;
		handle << data.password << std::endl;
		return Error::SUCCESSFUL;
	}
}