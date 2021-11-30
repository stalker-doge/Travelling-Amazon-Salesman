#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

void main()
{
	string strVal, strLine;
	ifstream ArrayInputFile;
	ArrayInputFile.open("TSP10.csv", ios::in);
	const int ROWS = 15;
	const int COLS = 15;
	int cityDistances[ROWS][COLS];
	int tspPath[16],smallestTspPath[16];
	tspPath[0] = 0;
	tspPath[15] = 0;
	smallestTspPath[0] = 0;
	smallestTspPath[0] = 0;
	int totalDist = 0;
	int smallestTotalDist = 9999999;
	int biggestTotalDist = 0;
	float percentageDifferencePaths;
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
	auto start = high_resolution_clock::now();
	for (int loop = 0; loop < 1000; loop++)
	{
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
		for (int pos = 0; pos < 15; pos++)
		{
			totalDist = totalDist + cityDistances[tspPath[pos]][tspPath[pos + 1]];
		}
		if (smallestTotalDist>totalDist)
		{
			smallestTotalDist = totalDist;
				for (int pos = 0; pos < 15; pos++)
				{
					smallestTspPath[pos] = tspPath[pos];
				}
		}
		if (biggestTotalDist < totalDist)
		{
			biggestTotalDist = totalDist;
		}
		totalDist = 0;
		cout << "\ntest\n";
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	percentageDifferencePaths =((biggestTotalDist - smallestTotalDist) / ((biggestTotalDist + smallestTotalDist)*0.5))*100;
	cout << "\nSmallest path is:\n";
	for (int i = 0; i < 16; i++)
	{
		cout << "\t" << tspPath[i];
	}
	cout << "\nAnd the distance is :" << smallestTotalDist << "\n";
	cout << "\nThe worst path is: " << biggestTotalDist << "\n";
	cout << "\nPercentage difference between the two is: " << percentageDifferencePaths << "%\n";
	cout << "\nIt took: " << duration.count() << "ms for the program to process 1000 random paths";
	cout << "\n";
	system("pause");
}