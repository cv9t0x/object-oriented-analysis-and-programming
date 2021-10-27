#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

bool isFileExist(ifstream &file, char *input_file)
{
	if (!file)
		return false;
	return true;
}

bool isFileEmpty(ifstream &file, char *input_file)
{
	file.open(input_file);

	if (file.peek() != EOF)
		return false;
	return true;
}

bool fileCheck(ifstream &file, char *input_file)
{
	if (!isFileExist(file, input_file))
	{
		cout << "File is not exist" << endl;
		return false;
	}
	else
	{
		if (isFileEmpty(file, input_file))
		{
			cout << "File is empty" << endl;
			return false;
		}
		return true;
	}
}

int findFirstYear(ifstream &file)
{
	int first_year;

	for (int i = 0; i < 2; i++)
	{
		int data;
		file >> data;
		if (i == 1)
			first_year = data;
	}

	file.clear();
	file.seekg(0, ios::beg);

	return first_year;
}

int countNumberOfYears(ifstream &file, int first_year)
{
	int count = 1;
	int year = first_year;
	int a1, current_year, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14;

	while (true)
	{
		if (file.eof())
			break;

		file >> a1 >> current_year >> a3 >> a4 >> a5 >> a6 >> a7 >> a8 >> a9 >> a10 >> a11 >> a12 >> a13 >> a14;

		if (current_year != year)
		{
			year = current_year;
			count++;
		}
	}

	file.clear();
	file.seekg(0, ios::beg);

	return count;
}

void getInputFileData(ifstream &file, double **input_data, int first_year)
{
	int days = 0;
	int winter_days = 0;
	int summer_days = 0;
	int row = 0;
	int year = first_year;
	int max_temp = 500;
	double avr_temp = 0;
	double avr_sum_temp = 0;
	double avr_win_temp = 0;
	int a1, current_year, month, a4, a5, a6, a7, temp, a9, a10, a11, a12, a13, a14;

	while (true)
	{
		file >> a1 >> current_year >> month >> a4 >> a5 >> a6 >> a7 >> temp >> a9 >> a10 >> a11 >> a12 >> a13 >> a14;

		if (file.eof() || current_year != year)
		{
			input_data[row][0] = year;

			if (avr_temp == 0 || days < 330)
			{
				input_data[row][1] = 0;
				input_data[row][2] = 0;
				input_data[row][3] = 0;
			}
			else
			{
				input_data[row][1] = floor(avr_temp / days);
				input_data[row][2] = floor(avr_sum_temp / summer_days);
				input_data[row][3] = floor(avr_win_temp / winter_days);
			}

			if (file.eof())
				break;
			else
			{
				days = 0;
				winter_days = 0;
				summer_days = 0;
				row++;
				year = current_year;
				avr_temp = 0;
				avr_win_temp = 0;
				avr_sum_temp = 0;
			}
		}
		else
		{
			if (abs(temp) < max_temp)
			{
				avr_temp += temp;

				if (month == 1 || month == 2 || month == 12)
				{
					avr_win_temp += temp;
					winter_days++;
				}
				if (month == 6 || month == 7 || month == 8)
				{
					avr_sum_temp += temp;
					summer_days++;
				}

				days++;
			}
		}
	}

	file.close();
}

void outputInFileData(ofstream &file, double **input_data, const int NUMBER_OF_YEARS, const int OUTPUT_FILE_COLUMNS)
{
	for (int i = 0; i < NUMBER_OF_YEARS; i++)
	{
		if (input_data[i][1] != 0)
		{
			for (int j = 0; j < OUTPUT_FILE_COLUMNS; j++)
			{
				file << input_data[i][j] << " \t";
			}
			file << endl;
		}
	}
	file.close();
	cout << "Done!" << endl;
}