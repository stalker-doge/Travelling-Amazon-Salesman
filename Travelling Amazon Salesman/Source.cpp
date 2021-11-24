#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void main()
{
	string strVal, strLine;
	ifstream ArrayInputFile;
	ArrayInputFile.open("TSP10.csv", ios::in);
	const int ROWS = 15;
	const int COLS = 15;
	int cityDistances[ROWS][COLS];
	int tspPath[16]
	int startPos, pos;

	for (int row = 0; row < ROWS; row++)
	{
		ArrayInputFile >> strLine;
		startPos = 0;
		pos = strLine.find(",");
		for (int col = 0; col < COLS - 1; col++)
		{
			strVal = strLine.substr(startPos, pos - startPos);
			cityDistances[row][col] = atoi(strVal.c_str());
			startPos = pos + 1;
			pos = strLine.find(",", startPos);
		}
		strVal = strLine.substr(startPos, strLine.length() - startPos);
		cityDistances[row][COLS - 1] = atoi(strVal.c_str());
	}
	cout << "\nCity Distances:\n";
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			cout << "\t" << cityDistances[row][col];
		}
		cout << "\n";
	}
	system("pause");
}