#include "pch.h"
#include "list.h"

bool ListEvent::InsertDate(const EventData& data)
{
	if (data.year < 0) return false;
	if (!head)
	{
		List<EventData>::InsertBack(data);
	}
	else
	{
		Node* ppos = head;
		Node* t = nullptr;
		while (ppos&& ppos->data.year < data.year)
		{
			t = ppos;
			ppos = ppos->next;
		}
		
		Node* add = new Node;
		add->data = data;
		if(List<EventData>::InsertPos(t, add)) return true;
	}
	return false;
}
bool ListEvent::ReplaceEvent(int pos, const EventData& data)
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
bool ListEvent::SearchData(int year, std::string topic)
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
void ListEvent::PrintEvent()
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