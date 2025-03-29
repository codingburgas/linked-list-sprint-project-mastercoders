#pragma once

namespace Global
{
	static std::shared_ptr<ListEvent> events;
	bool Init();
	std::shared_ptr<ListEvent>& GetEvents();
}