#pragma once

namespace Global
{
	// global events list
	static std::shared_ptr<ListEvent> events;
	// assign default values to global vars
	bool Init();
	// release global vars
	bool Release();
	// getter for events ptr
	std::shared_ptr<ListEvent>& GetEvents();
}