#include "pch.h"
#include "global.h"

namespace Global
{
	bool Init()
	{
		if(!events.get())
		events = std::make_shared<ListEvent>();
	}
	std::shared_ptr<ListEvent>& GetEvents()
	{
		return events;
	}
}