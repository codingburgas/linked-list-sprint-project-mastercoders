#include "pch.h"
#include "list.h"

bool ListEvent::InsertDate(const EventData& data)
{
	if (data.year < 0) return false; // if year is incorrect, or has default value -1, return
	Node* thead = head;
	Node* ppos = nullptr; // node before pos to insert

	if (!head)
	{
		InsertBack(data); // if list is empty, insert data using insert back
		return true;
	}

	while (thead && thead->data.year < data.year)
	{
		ppos = thead;
		thead = thead->next;
	}
	if (!ppos) // if node to insert first, ppos is null and insert front is used
	{
		InsertFront(data);
		return true;
	}
	return InsertPos(ppos, data); // if pos is not first or list is not empty, insert using insert pos
}
bool ListEvent::ReplaceEvent(int pos, const EventData& data) const
{
	if (pos <= 0 || pos > count) return false; // if pos is not valid, return
	
	Node* thead = head;
	for (int i = 0; thead && i < pos - 1; i++)
	{
		thead = thead->next;
	}

	if (!thead) return false; // if node at pos doesn't exist, return

	thead->data = data;
	return true;
}
bool ListEvent::SearchEvent(int year, const std::string& topic) const
{
	if (!head) return false;

	Node* thead = head;
	while (thead && thead->data.year != year && thead->data.topic != topic) // loop while data does not match
	{
		thead = thead->next;
	}

	if (!thead) return false; // check if node at pos is not null
	if (thead->data.year == year && thead->data.topic == topic) return true;
	return false;
}
void ListEvent::PrintEvent() const
{
	Node* thead = head;
	int id = 1;

	std::cout << std::string(30, '-') << std::endl;
	while (thead)
	{
		EventData* event = &thead->data;
		std::cout << "Event number: " << id++ << std::endl;
		std::cout << "Event name: " << event->name << std::endl;
		std::cout << "Year: " << event->year << std::endl;
		std::cout << "Topic: " << event->topic << std::endl;
		std::cout << "Leader: " << event->otherData.leader << std::endl;
		std::cout << "Result: " << event->otherData.result << std::endl;
		std::cout << "Participants:\n\n";

		for (size_t i = 0; i < event->otherData.participants.size();i++)
		{
			std::cout << "Participant " << i + 1 << ": " << event->otherData.participants[i] << std::endl;
		}

		std::cout << std::string(30, '-') << std::endl;
		thead = thead->next;
	}
}
std::shared_ptr<List<std::string>> ListEvent::NameList() const
{
	if (!head) 
		return nullptr;
	Node* thead = head;
	
	auto names = std::make_shared<List<std::string>>();
	while (thead)
	{
		names->InsertBack(thead->data.name);
		thead = thead->next;
	}
	return names;
}
std::shared_ptr<ListEvent> ListEvent::EventList(const std::string& topic) const
{	
	if (!head || topic.empty()) 
		return nullptr; // if list is empty or topic is empty return empty list
		
	auto events = std::make_shared<ListEvent>();
	Node* thead = head;

	while (thead)
	{
		if (thead->data.topic == topic) // if topic matches append to new list
		events->InsertBack(thead->data);
		thead = thead->next;
	}
	return events;
}
ListEvent::Node* ListEvent::Merge(Node* a, Node* b)
{
	if (!a) return b;
	if (!b) return a;

	Node* t = a->data.year < b->data.year ? a : b;
	Node* other = t == a ? b : a;

	t->next = Merge(t->next, other);
	t->next->prev = t;
	t->prev = nullptr;
	return t;
}

ListEvent::Node* ListEvent::MidElement(Node* head)
{
	if (!head || !head->next) return head;
	Node* thead,*thead2,*ppos = nullptr; // ppos is last node, node before mid

	thead = thead2 = head;
	while (thead2 && thead2->next)
	{
		ppos = thead;
		thead = thead->next;
		thead2 = thead2->next->next;
	}

	if (ppos) 
		ppos->next = nullptr;
	return thead;
}

ListEvent::Node* ListEvent::MergeSort(Node* head)
{
	if (!head || !head->next) return head;
	Node* mid = MidElement(head), *left = MergeSort(head), * right = MergeSort(mid);

	return Merge(left, right);
}

void ListEvent::SortEvents()
{
	if (!head) return;
	head = MergeSort(head);

	Node* thead = head;
	Node* ppos = head;
	while (thead)
	{
		ppos = thead;
		thead = thead->next;
	}
	tail = ppos; // reassign tail to point to new last element
}
bool ListEvent::IsSorted() const
{
	Node* thead = head;
	while (thead && thead->next)
	{
		if (thead->data.year > thead->next->data.year)
			return false;
		thead = thead->next;
	}
	return true;
}
