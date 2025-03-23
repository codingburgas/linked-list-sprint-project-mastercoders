#include "pch.h"
#include "list.h"

void ListEvent::InsertFront(const EventData& data)
{
	List<EventData>::InsertFront(data);
}
void ListEvent::InsertBack(const EventData& data)
{
	List<EventData>::InsertBack(data);
}
void ListEvent::InsertDate(const EventData& data)
{
    Node* ppos = head;
    Node* prevPpos = nullptr;
    Node* add = new Node;
    add->data = data;

    if (!ppos) 
    {
        List<EventData>::InsertFront(data);
        return;
    }
   
    while (ppos && ppos->data.year < data.year) 
    {
        prevPpos = ppos;
        ppos = ppos->next;
    }

    if (!ppos) 
    {
        List<EventData>::InsertBack(data);
    }
    else 
    {
        InsertPos(prevPpos, add);
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