#include "pch.h"
#include "utils.h"
namespace Utils
{
	void Clear()
	{
		system("cls");
	}
	void CheckNotInit()
	{
		auto events = Global::GetEvents();
		if (!events)
		{
			std::cerr << "\nError\n";
			Sleep(500);
			exit(1);
		}
	}
}