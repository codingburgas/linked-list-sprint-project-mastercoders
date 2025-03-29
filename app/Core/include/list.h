#pragma once
#include "event.h"
template<class T>
class List
{
protected:
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
	Node* tail;
	int count;
public:
	List() : head(nullptr), tail(nullptr)/*lastBack(nullptr), lastFront(nullptr), */,count(0)
	{

	}
	/*void Print();
	void PrintBack(int mode);*/
	void InsertFront(const T& data);
	void InsertBack(const T& data);
	void InsertPos(Node* ppos,Node* node);
};
class ListEvent : public List<EventData>
{
public:
	ListEvent() : List()
	{

	}
	void InsertFront(const EventData& data);	
	void InsertBack(const EventData& data);	
	void InsertDate(const EventData& data);
	void PrintEvent();
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
		head->prev = add;
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
		head->prev = head->next = nullptr;
		tail = head;
	}
	else
	{
		Node* add = new Node;
		add->data = data;
		add->prev = tail;
		tail->next = add;
		tail = add;
	}
	count++;
}
template<class T>
void List<T>::InsertPos(Node* p, Node* node)
{
	node->prev = p;
	node->next = p->next;
	if (p->next)
		p->next->prev = node;
	p->next = node;

	if (!p->next)
		tail = node;
}
//template<class T>
//void List<T>::InsertPos(Node* ppos, Node* node)
//{
//	if (!ppos)
//	{
//		return;
//	}
//	node->next = ppos->next;
//	if (ppos->next)
//	{
//		ppos->next->prev = node;
//	}
//	ppos->next = node;
//	node->prev = ppos;
//
//	if (node->next == nullptr)
//	{
//		lastBack = node;
//	}
//}
// 
//template <class T>
//void List<T>::Print()
//{
//	Node* t = head;
//	while (t)
//	{
//		std::cout << t->data << ' ';
//		t = t->next;
//	}
//};
//template <class T>
//void List<T>::PrintBack(int mode) /////////// fix to work with event
//{
//	Node* t = mode == 1 ? lastFront : lastBack;
//	while (t)
//	{
//		std::cout << t->data << ' ';
//		t = mode == 1 ? t->next : t->prev;
//	}
//};
