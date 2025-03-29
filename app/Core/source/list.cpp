#include "pch.h"
#include "list.h"

bool ListEvent::InsertDate(const EventData& data)
{
	if (data.year < 0) return false;
	if (!head)
	{
		List<EventData>::InsertBack(data);
		return true;
	}
	else
	{
		Node* thead = head;
		Node* ppos = nullptr;
		while (thead&& thead->data.year < data.year)
		{
			ppos = thead;
			thead = thead->next;
		}
		
		if(List<EventData>::InsertPos(ppos, data)) return true;
	}
	return false;
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
bool ListEvent::SearchData(int year, std::string topic) const
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
void ListEvent::PrintEvent() const
{
	Node* thead = head;
	while (thead)
	{
		EventData* currEvent = &thead->data;
		std::cout << "Event name: " << currEvent->name << std::endl;
		std::cout << "Year: " << currEvent->year << std::endl;
		std::cout << "Topic: " << currEvent->topic << std::endl;
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
List<EventData>& ListEvent::EventList(std::string topic) const
{
	List<EventData> events;
	if (!head) return events;
		
	Node* thead = head;	
	while (thead)
	{
		if (thead->data.topic == topic)
			events.InsertBack(thead->data);
		thead = thead->next;
	}
	return events;
}