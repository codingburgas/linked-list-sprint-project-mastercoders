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
	List() : head(nullptr), tail(nullptr),count(0)
	{

	}
	void InsertFront(const T& data);
	void InsertBack(const T& data);
	bool InsertPos(Node* ppos,Node* node);

	bool DelPos(int pos);
	bool DelFront();
	bool DelBack();

	int Size() { return count; }
	const T& Get(int pos);
	const T& operator[](int pos)
	{
		return Get(pos);
	}
};
class ListEvent : public List<EventData>
{
public:
	bool InsertDate(const EventData& data);
	void PrintEvent();
	bool ReplaceEvent(int pos, const EventData& data);
	bool SearchData(int year, std::string topic);
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
bool List<T>::InsertPos(Node* p, Node* node)
{
	if (!p) return false;
	if (!head)
	{
		if (node)
			InsertBack(node->data);
		if (node)
			delete node;
		return true;
	}
	node->prev = p;
	node->next = p->next;
	if (p->next)
		p->next->prev = node;
	p->next = node;

	if (!p->next)
		tail = node;
	count++;

	return true;
}
template<class T>
const T& List<T>::Get(int pos)
{
	if (pos <= 0 || pos > count) return T();

	Node* thead = head;
	for (int i = 0; i < pos - 1 && thead; i++)
	{
		thead = thead->next;
	}
	return thead->data;
}
template<class T>
bool List<T>::DelFront()
{
	if (!head) return false;
	Node* del = head; // node to delete

	head = head->next;
	head->prev = nullptr;
	
	if(del)
	delete del;
	return true;
}
template<class T>
bool List<T>::DelBack()
{
	if (!head || !tail) return false;

	Node* del = tail; // node to delete
	del->prev->next = nullptr;
	tail = del->prev; // assign tail to be the node before tail

	delete del;
	return true;
}
