#pragma once
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
	// insert by a given node
	bool InsertPos(Node* ppos, const T& data);
public:
	List() : head(nullptr), tail(nullptr), count(0)
	{

	}
	~List()
	{
		DelAll();
	}
	// insert at first pos
	void InsertFront(const T& data);
	// insert at last pos
	void InsertBack(const T& data);
	// insert by a given position
	bool InsertPos(int pos, const T& data);

	// delete at a certain pos, starting at one
	bool DelPos(int pos);
	// delete at first pos
	bool DelFront();
	// delete at last pos
	bool DelBack();
	// delete all nodes
	bool DelAll();

	// return current size
	int Size() const { return count; }
	// get data at certain pos
	const T& Get(int pos) const;
	// same as get
	const T& operator[](int pos) const
	{
		return Get(pos);
	}
	// return whether list is empty or not
	bool IsEmpty() const { return !head; }
};
class ListEvent : public List<EventData>
{
	// merge used in merge sort
	Node* Merge(Node* l1, Node* l2);
	// function to find mid node
	Node* MidElement(Node* head);
	// sorting alg
	Node* MergeSort(Node* head);
public:
	// insert event by year
	bool InsertDate(const EventData& data);
	// print all events: name,topic,year
	void PrintEvent() const;
	// replace event data at certain pos
	bool ReplaceEvent(int pos, const EventData& data) const;
	// search an event by year and topic, return true if found
	bool SearchEvent(int year, const std::string& topic) const;

	// returns a list with all events' names
	std::shared_ptr<List<std::string>> NameList() const;
	// returns list with all events' data with the same topic
	std::shared_ptr <ListEvent> EventList(const std::string& topic) const;
	// sort events by year
	void SortEvents();
	// return whether events are sorted or not
	bool IsSorted() const;
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
bool List<T>::InsertPos(Node* ppos, const T& data)
{
	if (!ppos) return false; // if node before pos is null, return

	if (!head)
	{
		InsertFront(data);
		return true;
	}
	Node* add = new Node; // new node to insert
	add->data = data;

	add->prev = ppos;
	add->next = ppos->next;
	if (ppos->next)
		ppos->next->prev = add;

	if (!ppos->next) // if node after ppos is last, assign tail to be the new node
		tail = add;
	ppos->next = add;

	count++;
	return true;
}
template<class T>
bool List<T>::InsertPos(int pos, const T& data)
{
	if (!head || pos <= 0 || pos > count + 1)
	{
		InsertBack(data);
		return true;
	}
	if (pos == 1)
	{
		InsertFront(data); // insert at front is pos is 1
		return true;
	}

	Node* thead = head;
	Node* ppos = nullptr; // prev of pos
	for (int i = 0; i < pos - 1 && thead; i++)
	{
		ppos = thead;
		thead = thead->next;
	}

	return InsertPos(ppos, data);
}
template<class T>
const T& List<T>::Get(int pos) const
{
	if (pos <= 0 || pos > count) return T(); // if pos is incorrect, return default value for T

	Node* thead = head;
	for (int i = 0; i < pos - 1 && thead; i++)
	{
		thead = thead->next;
	}
	return thead->data; // return node data at pos
}
template<class T>
bool List<T>::DelFront()
{
	if (!head) return false;
	Node* del = head;
	head = head->next;

	if (!head)
		tail = nullptr; // there's just one node in the list	
	else
		head->prev = nullptr; // make prev null

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

	if (count == 1)
	{
		return DelFront();
	}
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

	if (pos == 1)
	{
		return DelFront();
	}

	Node* thead = head;
	Node* ppos = nullptr; // node before pos
	for (int i = 0; thead && i < pos - 1; i++)
	{
		ppos = thead;
		thead = thead->next;
	}

	Node* del = thead; // node to delete
	ppos->next = thead->next;

	if (thead->next)
		thead->next->prev = ppos;
	else
		if (del == tail) tail = ppos; /// if thead is last node, no next after it, reassign tail

	if (del)
	{
		delete del;
		del = nullptr;
	}
	count--;
	return true;
}
template<class T>
bool List<T>::DelAll()
{
	if (!head) return false;
	Node* thead = head;

	while (thead)
	{
		Node* del = thead; // node to delete
		thead = thead->next;
		if (del)
		{
			delete del;
			del = nullptr;
		}
	}

	count = 0;
	return true;
}