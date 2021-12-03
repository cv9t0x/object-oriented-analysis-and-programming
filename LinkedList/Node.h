#ifndef NODE_H
#define NODE_H

template <typename T> 
class Node
{
private:

	Node* next;
	T data;

public:
	Node(const T data, Node* next = nullptr);
	~Node();

	T getData();
	Node* getNext();

	template <typename T> friend class LinkedList;
};

template <typename T> 
Node<T>::Node(const T data, Node* next)
{
	this->next = next;
	this->data = data;
}

template <typename T>
T Node<T>::getData()
{
	return data;
}

template<typename T>
Node<T>* Node<T>::getNext()
{
	return next;
}

template <typename T> 
Node<T>::~Node()
{
}

#endif // !NODE_H