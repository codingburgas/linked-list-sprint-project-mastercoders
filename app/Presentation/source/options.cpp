#include "pch.h"
#include "options.h"
#include "global.h"
namespace Options
{
	void ShowAllEvents()
	{
		auto events = Global::GetEvents();
		if (!events)
		{
			std::cerr << "Error\n";
			return; // stop the function if events hasn't been init
		}

		events->PrintEvent(); // print all events	
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
		std::cout << "Enter event's name\n:" << event.name;
		std::cout << "Enter event's year\n:" << event.year;
		std::cout << "Enter event's topic\n:" << event.topic;

		//std::cout << "Enter event's name\n:" << event.;

	}
}