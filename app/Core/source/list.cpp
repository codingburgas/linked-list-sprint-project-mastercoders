#include "pch.h"
#include "list.h"

bool ListEvent::InsertDate(const EventData& data)
{
	if (data.year < 0) return false;
	Node* thead = head;
	Node* ppos = nullptr;

	if (!head)
	{
		InsertBack(data);
		return true;
	}

	while (thead && thead->data.year < data.year)
	{
		ppos = thead;
		thead = thead->next;
	}
	if (!ppos)
	{
		InsertFront(data);
		return true;
	}
	return InsertPos(ppos, data);
}
bool ListEvent::ReplaceEvent(int pos, const EventData& data) const
{
	if (pos <= 0 || pos > count) return false;
	
	Node* thead = head;
	for (int i = 0; thead && i < pos - 1; i++)
	{
		thead = thead->next;
	}

	if (!thead) return false;

	thead->data = data;
	return true;
}
bool ListEvent::SearchEvent(int year, std::string topic) const
{
	if (!head) return false;

	Node* thead = head;
	while (thead && thead->data.year != year && thead->data.topic != topic)
	{
		thead = thead->next;
	}

	if (!thead) return false;
	if (thead->data.year == year && thead->data.topic == topic) return true;
	return false;
}
void ListEvent::PrintEvent(std::string topic) const
{
	Node* thead = head;
	//bool condition = topic.empty() ? thead != nullptr : thead && thead->data.topic == topic;

	while (thead)
	{
		/*if (topic == thead->data.topic && !topic.empty())
		{*/
			EventData* event = &thead->data;
			std::cout << "Event name: " << event->name << std::endl;
			std::cout << "Year: " << event->year << std::endl;
			std::cout << "Topic: " << event->topic << std::endl;
		/*}*/
		// other data print later on
		thead = thead->next;
	}
}
List<std::string> &ListEvent::NameList() const
{
	List <std::string> names;
	if (!head) return names;

	Node* thead = head;
	while (thead)
	{
		names.InsertBack(thead->data.name);
		thead = thead->next;
	}
	return names;		
}
ListEvent& ListEvent::EventList(std::string topic) const
{
	ListEvent events;
	if (!head || topic.empty()) return events;
		
	Node* thead = head;	
	while (thead)
	{
		if (thead->data.topic == topic)
			events.InsertBack(thead->data);
		thead = thead->next;
	}
	return events;
}