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
	void EnterEventData(EventData& event)
	{
		std::cout << std::endl;
		std::cout << "Enter event's name\n:";
		std::cin >> event.name;

		std::cout << "Enter event's year\n:";
		std::cin >> event.year;

		std::cout << "Enter event's topic\n:";
		std::cin >> event.topic;

		std::cout << "Enter event's leader\n:";
		std::cin >> event.otherData.leader;

		std::cout << "Enter event's result\n:";
		std::cin >> event.otherData.result;

		std::cout << "Enter number of participants\n";
		std::string count = "";
	}
	void EnterNumber(std::string& num)
	{
		while (true)
		{
			std::cout << ":";
			std::cin >> num;
			if (std::all_of(num.begin(), num.end(), ::isdigit))
			{
				if (std::stoi(num) > 0)
					break; // break if num is a non-negative number
			}
		}
	}
}