#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void FillWithZeros(int** const arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i][0] = 0;
		arr[i][1] = 0;
	}
}

void FillWithCoordinates(ifstream& file, int** const arr, const int size)
{
	int count = 0;

	while (!file.eof())
	{
		int x = 0, y = 0;

		file >> x >> y;

		if (count < size)
		{
			arr[count][0] = x;
			arr[count][1] = y;

			count++;
		}

	}
}

double CountFigureSquare(int** const arr, const int size) 
{
	int sum1 = arr[size - 1][1] + arr[0][1];
	int sum2 = arr[size - 1][1] + arr[0][0];

	for (int i = 0; i < size - 1; i++)
	{
		sum1 = sum1 + arr[i][0] + arr[i + 1][1];
		sum2 = sum2 + arr[i][1] + arr[i + 1][0];
	}

	double result = (sum1 > sum2) ? (double)(sum1 - sum2) / 2 : (double)(sum2 - sum1) / 2;

	return result;
}

int main()
{
	string path = "data.txt";

	ifstream file;
	file.exceptions(ifstream::badbit | ifstream::failbit);

	try
	{
		file.open(path);
		cout << "---------------" << endl;
		cout << "File is opened!" << endl;
		cout << "---------------" << endl;
	}
	catch (const ifstream::failure& e)
	{
		cout << "---------------" << endl;
		cout << "Error can't open file" << endl;
		cout << "---------------" << endl;
	}

	

	if (file.is_open())
	{
		int vertexQuantity;

		file >> vertexQuantity;

		int** vertexCoordinates = new int* [vertexQuantity];

		for (int i = 0; i < vertexQuantity; i++)
		{
			vertexCoordinates[i] = new int[2]{};
		}


		FillWithZeros(vertexCoordinates, vertexQuantity);

		FillWithCoordinates(file, vertexCoordinates, vertexQuantity);

		cout << "Figure square is: " << CountFigureSquare(vertexCoordinates, vertexQuantity) << endl;
			

		file.close();

		for (int i = 0; i < vertexQuantity; i++)
		{
			delete[] vertexCoordinates[i];
		}

		delete[] vertexCoordinates;
	}

		

	return 0;
}