#include "pch.h"
#include "create.h"

namespace Create
{
	int CreateUser(const User& data)
	{
		std::ofstream handle(std::filesystem::current_path().string() + "\\Data\\Users\\user" + data.username + ".txt"); // dir isn't correct

		if (!handle.is_open())
			return Error::ERROR_STREAM;

		handle << data.username << std::endl;
		handle << data.password << std::endl;

		handle.close();
		return Error::SUCCESSFUL;
	}
}