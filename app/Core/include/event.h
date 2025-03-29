#pragma once

struct Other
{
	std::string leader;
	std::string* participants;
	std::string result;
};
struct EventData
{
	int year;
	std::string topic;
	std::string name;
	Other otherData;
	EventData() : year(-1) {}
};

// sort by year