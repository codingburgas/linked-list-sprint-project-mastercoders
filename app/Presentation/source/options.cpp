#include "pch.h"
#include "options.h"
namespace Options
{
	void ShowAllEvents()
	{
		auto events = Global::GetEvents();

		if (events->IsEmpty())
		{
			std::cout << "List is empty\n";
		}
		else
		events->PrintEvent(); // print all events if list is not empty

		_getch(); // wait for user to press

		Utils::Clear();
	}
	void InsertEvent()
	{
		auto events = Global::GetEvents();
		EventData event; // entered event data

		Utils::EnterEventData(event);

		Utils::Clear();
		events->InsertDate(event); // insert event sorted by year
	}
	void ReplaceEvent()
	{
		auto events = Global::GetEvents();

		std::cout << "Enter number of event to replace:\n:";

		std::string num = "";
		Utils::EnterNumber(num);
		
		EventData data;
		std::cout << "Enter new event's data:\n";
		Utils::EnterEventData(data);

		events->ReplaceEvent(std::stoi(num), data); // replace event after inserting its data
		Utils::Clear();
	}
	void DeleteEvent()
	{
		auto events = Global::GetEvents();

		std::cout << "Enter which event to remove:\n";
		std::cout << "1. First\n";
		std::cout << "2. Last\n";
		std::string num;// number of event to delete

		Utils::EnterNumber(num);

		//events->DelPos(std::stoi(num)); // delete event at wanted position
		events->DelBack();
		Utils::Clear();
	}
	void Exit()
	{
		Utils::Exit();
	}
}