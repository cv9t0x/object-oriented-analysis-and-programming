#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList<int> list;

	int arr[5]{ 1, 2, 3, 4, 5 };

	for (int i = 0; i < 5; i++)
	{
		list.push_front(arr[i]);
	}

	list.pop_back();
	list.pop_front();

	list.remove(1);
	list.insert(666, 1);

	cout << "\n";
	cout << list;

	list.clear();

	cout << "\n";
	cout << list;
	cout << "\n";

	return 0;
}