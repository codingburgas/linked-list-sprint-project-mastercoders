#include "pch.h"
#include "create.h"

namespace Create
{
	int CreateUser(const User& data)
	{
		std::ofstream handle(R"(C:\Users\User\Pictures\projects\linked-list-sprint-project-mastercoders\app\Builder\Data\Users\user)" + data.username + ".txt"); 
		// dir isn't correct

		if (!handle.is_open())
			return Error::ERROR_STREAM;

		handle << data.username << std::endl;
		handle << data.password << std::endl;

		handle.close();
		return Error::SUCCESSFUL;
	}
}