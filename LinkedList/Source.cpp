#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList<int> list;

	list.fill(10, false);

	cout << list;

	
	/*list.insert(777, 5);
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