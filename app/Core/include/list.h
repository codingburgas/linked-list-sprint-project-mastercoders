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
	~List();
	void InsertFront(const T& data);
	void InsertBack(const T& data);
	bool InsertPos(Node* ppos,const T& data);

	bool DelPos(int pos);
	bool DelFront();
	bool DelBack();

	const int& Size() const { return count; }
	const T& Get (int pos) const;
	const T& operator[](int pos) const
	{
		return Get(pos);
	}
};
class ListEvent : public List<EventData>
{
public:
	bool InsertDate(const EventData& data);
	void PrintEvent() const;
	bool ReplaceEvent(int pos, const EventData& data) const;
	bool SearchData(int year, std::string topic) const;
	List<std::string>& NameList() const;
};

template<class T>
List<T>::~List()
{
	Node* thead = head;
	while (thead)
	{
		Node* del = thead;
		thead = thead->next;
		if (del)
		{
			delete del;
			del = nullptr;
		}
	}
	tail = nullptr;
}
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
bool List<T>::InsertPos(Node* p, const T& data)
{
	if (!p) return false;

	if (!head)
	{
		InsertBack(data);
		return true;
	}
	Node* add = new Node;
	add->data = data;

	add->prev = p;
	add->next = p->next;
	if (p->next)
		p->next->prev = add;
	p->next = add;

	if (!p->next)
		tail = add;
	count++;

	return true;
}
template<class T>
const T& List<T>::Get(int pos) const
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

	if (!head->next && head == tail) tail = nullptr;

	head = head->next;
	head->prev = nullptr;
	
	if (del)
	{
		delete del;
		del = nullptr;
	}
	count--;
	return true;
}
template<class T>
bool List<T>::DelBack()
{
	if (!head || !tail) return false;

	Node* del = tail; // node to delete
	del->prev->next = nullptr;
	tail = del->prev; // assign tail to be the node before tail

	if (del)
	{
		delete del;
		del = nullptr;
	}
	count--;
	return true;
}
template<class T>
bool List<T>::DelPos(int pos)
{
	if (pos <= 0 || pos > count) return false;

	Node* thead = head;
	Node* t = nullptr;
	for (int i = 0; thead && i < pos - 1; i++)
	{
		t = thead;
		thead = thead->next;
	}

	Node* del = thead;
	t->next = thead->next;

	if (thead->next)
		thead->next->prev = t;
	else
		if (del == tail) tail = t; /// thead is last node, no next after it, reassign tail

	if (del)
	{
		delete del;
		del = nullptr;
	}
	count--;
	return true;
}
