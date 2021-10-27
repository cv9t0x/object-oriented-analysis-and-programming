#include <iostream>
#include <fstream>
#include "functions.h"

using namespace std;

const int OUTPUT_FILE_COLUMNS = 4;
const int ARGUMENTS_COUNT = 3;

//struct GetDataArgs data;

int main(int argc, char *argv[])
{
	if (argc != ARGUMENTS_COUNT)
	{
		cout << "InputError" << endl;
		return 0;
	}

	char *input_file = argv[1];
	char *output_file = argv[2];

	ifstream in;

	if (!fileCheck(in, input_file))
		return 0;

	const int first_year = findFirstYear(in);
	const int NUMBER_OF_YEARS = countNumberOfYears(in, first_year);
	double **input_data = new double *[NUMBER_OF_YEARS];

	for (int i = 0; i < NUMBER_OF_YEARS; i++)
		input_data[i] = new double[OUTPUT_FILE_COLUMNS]{};

	//cout << NUMBER_OF_YEARS << endl;

	getInputFileData(in, input_data, first_year);

	ofstream out(output_file);

	outputInFileData(out, input_data, NUMBER_OF_YEARS, OUTPUT_FILE_COLUMNS);

	for (int i = 0; i < NUMBER_OF_YEARS; i++)
		delete[] input_data[i];
	delete[] input_data;

	return 0;
}