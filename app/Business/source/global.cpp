#include "pch.h"
#include "global.h"

namespace Global
{
	bool Init()
	{
		if (!events)
		{
			events = std::make_shared<ListEvent>();
			return true;
		}
		return false;
	}
	bool Release()
	{
		if (events)
		{
			events.reset();
			return true;
		}
		return false;
	}
	std::shared_ptr<ListEvent>& GetEvents()
	{
		return events;
	}
}