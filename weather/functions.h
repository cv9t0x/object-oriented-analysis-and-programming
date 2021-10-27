#include <fstream>

using namespace std;

//struct GetDataArgs
//{
//	ifstream file;
//	double **input_data;
//	int *output_data;
//	int first_year;
//	int NUMBER_OF_YEARS;
//	int OUTPUT_FILE_COLUMNS;
//};

//File
bool isFileExist(ifstream &, char *);
bool isFileEmpty(ifstream &, char *);
bool fileCheck(ifstream &, char *);

//Years
int countNumberOfYears(ifstream &, int);
int findFirstYear(ifstream &);

//Data
//void getInputFileData(struct &);
void getInputFileData(ifstream &, double **, int);
void outputInFileData(ofstream &, double **, const int, const int);