#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <istream>

using namespace std;

class LinkedListException {};

template <typename T> 
class LinkedList
{

private:
	int size;
	bool circular;
	Node<T>* head;

public:
	LinkedList();
	~LinkedList();
	
	int getSize();
	Node<T>* getHead();

	void fill(const int size, const bool reversed = false);

	void push_front(const T data);
	void push_back(const T data);

	void insert(const T data, const int index);
	void removeById(const int index);
	void remove(Node<T>* current);

	void pop_front();
	void pop_back();

	void clear();

	bool isEmpty();
	bool isCircular();

	T& operator[](const int index);

	template<typename T> friend ostream& operator<<(ostream& out, const LinkedList<T>& list);
};

template <typename T> 
LinkedList<T>::LinkedList()
{
	this->head = nullptr;
	this->size = 0;
}

template <typename T> 
LinkedList<T>::~LinkedList()
{
	clear();
}

template <typename T>
void LinkedList<T>::fill(const int size, const bool reversed)
{
	if (reversed)
	{
		for (int i = size; i > 0; i--)
			push_back(i);
	}
	else
	{
		for (int i = 1; i <= size; i++)
			push_back(i);
	}
}

template <typename T>
int LinkedList<T>::getSize()
{
	return size;
}

template <typename T>
Node<T>* LinkedList<T>::getHead()
{
	return head;
}

template <typename T>
void LinkedList<T>::push_front(const T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* previous = head;
		head = new Node<T>(data, previous);
	}

	size++;
}

template <typename T>
void LinkedList<T>::push_back(const T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = head;

		while (current->next != nullptr)
			current = current->next;
			
		current->next = new Node<T>(data);
	}

	size++;
}

template <typename T>
void LinkedList<T>::removeById(const int index)
{	
	if (index < 0 || index >= size)
	{
		throw LinkedListException();
	}
	else if (index == 0)
	{	
		pop_front();
	}
	else
	{
		Node<T>* previous = head;

		for (int i = 0; i < index - 1; i++)
			previous = previous->next;

		Node<T>* temp = previous->next;

		previous->next = temp->next;

		delete temp;

		size--;
	}
}

template <typename T>
void LinkedList<T>::remove(Node<T>* current)
{
	if (current == head)
	{
		pop_front();
	}
	else if (current->next == nullptr)
	{
		pop_back();
	}
	else
	{
		Node<T>* previous = head;

		while (previous->next != current)
		{
			previous = previous->next;
		}

		previous->next = current->next;
		
		delete current;

		size--;
	}
}

template <typename T>
void LinkedList<T>::insert(const T data, const int index)
{	
	if (index < 0 || index > size)
	{
		throw LinkedListException();
	}
	else if (index == 0)
	{
		push_front(data);
	}
	else if (index == size)
	{
		push_back(data);
	}
	else
	{
		Node<T>* previous = head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->next;
		}

		Node<T>* temp = previous->next;
		Node<T>* newElem = new Node<T>(data);

		previous->next = newElem;
		newElem->next = temp;
		
		size++;
	}
}

template <typename T>
void LinkedList<T>::pop_front()
{
	Node<T>* temp = head;

	head = head->next;

	delete temp;

	size--;
}

template <typename T>
void LinkedList<T>::pop_back()
{
	removeById(size - 1);
}

template <typename T>
bool LinkedList<T>::isEmpty()
{
	return size == 0 ? true : false;
}

template <typename T>
bool LinkedList<T>::isCircular()
{
	return circular == true ? true : false;
}

template <typename T>
T& LinkedList<T>::operator[](const int index)
{	
	if (index < 0 || index > size)
	{
		throw LinkedListException();
	}
	else
	{
		int count = 0;
		Node<T>* current = head;

		while (current != nullptr)
		{
			if (count == index)
				return current->data;

			current = current->next;
			count++;
		}
	}
}

template <typename T>
void LinkedList<T>::clear()
{
	while (size)
		pop_front();
}

template <typename T>
ostream& operator<<(ostream& out, const LinkedList<T>& list)
{	
	if (list.size == 0)
	{
		out << "List is empty" << endl;
	}
	else
	{
		int count = 0;
		Node<T>* current = list.head;

		while (count < list.size)
		{
			out << current->getData() << "  ";

			current = current->getNext();
			count++;
		}

		out << endl;
	}

	return out;
}

#endif // !LINKEDLIST_H