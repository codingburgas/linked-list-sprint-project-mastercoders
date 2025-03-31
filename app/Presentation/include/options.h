#pragma once

namespace Options
{
	// print all events' data
	void ShowAllEvents();
	// insert an event to global events list
	void InsertEvent();
	// replace an event from the global event list
	void ReplaceEvent();
	// check if global event list is not init
	void CheckNotInit();
}