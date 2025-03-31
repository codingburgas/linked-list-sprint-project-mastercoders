#include "pch.h"
#include "options.h"
#include "global.h"
namespace Options
{
	void ShowAllEvents()
	{
		Utils::Clear();
		auto events = Global::GetEvents();
		if (!events)
		{
			std::cerr << "Error\n";
			return; // stop the function if events hasn't been init
		}

		events->PrintEvent(); // print all events
		_getch(); // wait for user to press

		Utils::Clear();
	}
	void InsertEvent()
	{
		auto events = Global::GetEvents();
		if (!events)
		{
			std::cerr << "Error\n";
			return; // stop the function if events hasn't been init
		}
		EventData event; // entered event data

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

		while(true)
		{
			std::cout << ":";
			std::cin >> count;
			if (std::all_of(count.begin(), count.end(), ::isdigit))
			{
				if (std::stoi(count) > 0)
					break; // break if count is a non-negative number
			}
		}
		std::cout << "\nEnter participants\n";
		for (int i = 0; i < std::stoi(count); i++)
		{
			std::string participant;
			std::cout << ":";
			std::cin >> participant;
			event.otherData.participants.push_back(participant);
		}
		Utils::Clear();
		events->InsertDate(event); // insert event sorted by year
	}
}