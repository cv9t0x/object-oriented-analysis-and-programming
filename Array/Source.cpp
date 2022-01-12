#include <iostream>
#include <istream>
#include "Array.h"

using namespace std;

int main(void)
{
    Array arr(4);

    for (int i = 0; i < 4; i++)
        arr.insert(i + 1);

    Array newArr(2);

    for (int i = 0; i < 3; i++)
        newArr.insert(i + 10);

    cout << newArr;

    arr.insert(newArr, 4);

    cout << arr;
}