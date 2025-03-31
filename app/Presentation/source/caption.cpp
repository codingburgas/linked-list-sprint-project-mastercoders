#include "pch.h"
#include "caption.h"
namespace Caption
{
	void PrintCaption()
	{
		std::ifstream handle(R"(../Presentation/assets/timelist.txt)");
		if (!handle.is_open()) // if file cannot be opened print non-art text
		{
			std::cout << "----------TimeList----------\n";
			return;
		}

		std::string line;
		while (std::getline(handle, line))
		{
			std::cout << line << std::endl;
		}
	}
}