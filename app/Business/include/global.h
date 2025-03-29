#pragma once

namespace Global
{
	// global events list
	static std::shared_ptr<ListEvent> events;
	// assign default values to global vars
	bool Init();
	// getter for events ptr
	std::shared_ptr<ListEvent>& GetEvents();
}