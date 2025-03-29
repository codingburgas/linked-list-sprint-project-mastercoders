#include "pch.h"
#include "global.h"

namespace Global
{
	bool Init()
	{
		events = std::make_shared<ListEvent>();
	}
	std::shared_ptr<ListEvent>& GetEvents()
	{
		return events;
	}
}