#pragma once
#include "event.h"
template<class T>
class List
{
	struct Node
	{
		T data;
		Node* prev;
		Node* next;
		Node() : prev(nullptr), next(nullptr)
		{

		}
	};
	Node* head;
	Node* last;
	int count;
public:
	List() : head(nullptr), last(nullptr),count(0)
	{

	}
	void Print();
	void InsertFront(const T& node);
	void InsertBack(const T& node);	
};
class ListEvent : public List<EventData>
{
public:
	ListEvent() : List()
	{

	}
	void InsertFront(const EventData& data)
	{
		List<EventData>::InsertFront(data);
	}
	void InsertBack(const EventData& data)
	{
		List<EventData>::InsertBack(data);
	}
};
template <class T>
void List<T>::InsertFront(const T& data)
{
	if (!head)
	{
		head = new Node;
		head->data = data;
	}
	else
	{
		Node* add = new Node;
		add->data = data;
		add->next = head;
		head = add;
	}
	count++;
}
template <class T>
void List<T>::InsertBack(const T& data)
{
	if (!head)
	{
		head = new Node;
		head->data = data;
		last = head;
	}
	else
	{
		Node* add = new Node;
		add->data = data;
		add->prev = last;
		last->next = add;
		last = add;
	}
	count++;
}
template <class T>
void List<T>::Print()
{
	Node* t = head;
	while (t)
	{
		std::cout << t->data << ' ';
		t = t->next;
	}
};