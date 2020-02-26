#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int partition(int left, int right, int ary[])
{
	int p = ary[left];
	int i = left;
	int j = right+1;

	while (1)
	{
		do
		{
			i++;
		} while (ary[i] < p && i < j);

		do
		{
			j--;
		} while (ary[j] > p && i < j);

		if (i > j)
			break;

		swap(ary[i], ary[j]);

	}
	swap(ary[j], ary[left]);
	return j;
 }

void quickSort(int left, int right, int ary[])
{
	if (left < right)
	{
		int pivoPoint = partition(left, right, ary);
		quickSort(left, pivoPoint - 1, ary);
		quickSort(pivoPoint + 1, right, ary);
	}

}

int main()
{
	const string fileName = "p2data.txt";
	ifstream myfile;
	string p;
	int numberOfData = 0;

	myfile.open(fileName);


	if(myfile.is_open())
	{ 
		while (getline(myfile, p))
		{
			numberOfData++;
		}

		if (numberOfData < 2)
		{
			cout << "Empty file, or 1 data only." << endl;
			cin >> p;
			return 0;
		}
	}
	else
	{
		cout << "Unable to open file." << endl;
		return 0;
	}
	myfile.close();

	myfile.open(fileName);
	int *ary = new int[numberOfData];

	if (myfile.is_open())
	{
		for (int i = 0; i < numberOfData; i++)
		{
			myfile >> p;
			ary[i] = stoi(p);
		}
	}
	int left = 0;
	int right = numberOfData-1;

	quickSort(left, right, ary);

	cout << "Sorted Result: " << endl;
	for (int i = 0; i < numberOfData; i++)
	{
		cout << ary[i] << endl;
	}

	myfile.close();
	delete[] ary;
	ary = NULL;

	char c;
	cin >> c;
	return 0;
}