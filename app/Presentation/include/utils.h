#pragma once

namespace Utils
{
	// clear screen cmd command
	void Clear();
	// check if global event list is not init
	void CheckNotInit();
	// enter passed event's data
	void EnterEventData(EventData& event);
	// loop while non-negative number is entered
	void EnterNumber(std::string& num);
}