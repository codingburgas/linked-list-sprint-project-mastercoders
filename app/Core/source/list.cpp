#include "pch.h"
#include "list.h"

void ListEvent::InsertDate(const EventData& data)
{
	if (data.year < 0) return;
	if (!head)
	{
		head = new Node;
		head->data = data;
		count++;
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
		List<EventData>::InsertPos(t, add);
	}
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