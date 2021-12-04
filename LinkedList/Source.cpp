#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	int size, gap;
	cout << "Input the number of people: ";
	cin >> size;
	while (size <= 0)
	{
		cout << "The number of people must be > 0: ";
		cin >> size;
	}
	cout << "Input the gap: ";
	cin >> gap;
	while (gap <= 0)
	{
		cout << "The gap must be > 0: ";
		cin >> gap;
	}

	LinkedList<int> list;
	list.fill(size);

	Node<int>* current = nullptr;
	Node<int>* previous = nullptr;

	cout << "--------------------------------------------\n";
	while (list.getSize() > 1)
	{
		for (int i = 0; i < gap; i++)
		{
			if (current == nullptr)
			{
				current = list.getHead();
				previous = current;
			}
			else
			{
				previous = current;
				current = current->getNext() == nullptr ? list.getHead() : current->getNext();
			}
		}

		cout << "The number " << current->getData() << " will quit" << endl;
		
		Node<int>* temp = current;
		list.remove(temp);

		current = previous;
	}
	cout << "--------------------------------------------\n";

	cout << "\nYou should stand on the position: " <<  list;


	/*LinkedList list;
	list.fill(10);
	list.insert(777, 5);
	cout << list;
	list.remove(4);

	list.pop_back();
	list.pop_front();

	list.remove(1);
	list.insert(666, 1);

	cout << "\n";
	cout << list;

	list.clear();

	cout << "\n";
	cout << list;
	cout << "\n";*/

	return 0;
}