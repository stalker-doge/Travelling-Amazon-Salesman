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
	int tspPath[16];
	tspPath[0] = 0;
	tspPath[15] = 0;
	srand(time(NULL));
	int rndCity = rand() % 14 + 1;
	bool alreadyChosen = true;
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
	for (int currPos = 1; currPos < 15; currPos++)
	{
		alreadyChosen = true;
		do
		{
			rndCity = rand() % 14 + 1;
			alreadyChosen = false;

			for (int pos = 1; pos < currPos; pos++)
			{
				if (tspPath[pos] == rndCity)
				{
					alreadyChosen = true;
				}
			}

		} while (alreadyChosen == true);
		tspPath[currPos] = rndCity;
	}
	cout << "\nCurrent path is:\n";
	for (int i = 0; i < 16; i++)
	{
		cout << "\t" << tspPath[i];
	}
	cout << "\n";
	system("pause");
}