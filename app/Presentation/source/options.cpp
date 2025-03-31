#include "pch.h"
#include "options.h"
namespace Options
{
	void ShowAllEvents()
	{
		Utils::Clear();
		Utils::CheckNotInit();

		auto events = Global::GetEvents();

		events->PrintEvent(); // print all events
		_getch(); // wait for user to press

		Utils::Clear();
	}
	void InsertEvent()
	{		
		Utils::CheckNotInit();

		auto events = Global::GetEvents();
		EventData event; // entered event data

		Utils::EnterEventData(event);

		Utils::Clear();
		events->InsertDate(event); // insert event sorted by year
	}
	void ReplaceEvent()
	{
		Utils::CheckNotInit();
		auto events = Global::GetEvents();

		std::cout << "Enter number of event to replace:\n:";

		std::string num = "";
		Utils::EnterNumber(num);
		
		EventData data;
		std::cout << "Enter new event's data:\n";
		Utils::EnterEventData(data);

		events->ReplaceEvent(std::stoi(num), data); // replace event after inserting its data
	}
}