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
};

// sort by year