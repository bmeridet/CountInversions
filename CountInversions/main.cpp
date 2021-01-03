#include <iostream>
#include <fstream>
#include <string>

using namespace std;

long long MergeSort(int* arr, int l, int r);
long long Merge(int* arr, int l, int m, int r);
void Print(int* arr, int l);

int main()
{
	int* arr = new int[100000];

	ifstream ifS("numbers.txt");

	string line;

	for (int i = 0; i < 100000; ++i)
	{
		getline(ifS, line);
		arr[i] = stoi(line);
	}

	long long result = MergeSort(arr, 0, 99999);
	cout << "Number of Inversions: " << result << endl;

	return 0;
}

long long MergeSort(int* arr, int l, int r)
{
	long long count = 0;

	if (l < r)
	{
		int mid = l + (r - l) / 2;

		count += MergeSort(arr, l, mid);
		count += MergeSort(arr, mid + 1, r);

		count += Merge(arr, l, mid, r);
	}

	return count;
}

long long Merge(int* arr, int l, int m, int r)
{
	long long count = 0;

	int lenL = m - l + 1;
	int lenR = r - m;

	int* left = new int[lenL];
	int* right = new int[lenR];

	for (int i = 0; i < lenL; ++i)
	{
		left[i] = arr[l + i];
	}

	for (int i = 0; i < lenR; ++i)
	{
		right[i] = arr[m + 1 + i];
	}

	int i = 0, j = 0, k = l;

	while (i < lenL && j < lenR)
	{
		if (left[i] < right[j])
			arr[k++] = left[i++];
		else
		{
			arr[k++] = right[j++];
			count += lenL - i;
		}
	}

	while (i < lenL)
		arr[k++] = left[i++];

	while (j < lenR)
		arr[k++] = right[j++];

	delete[] left;
	delete[] right;
	
	return count;
}

void Print(int* arr, int l)
{
	for (int i = 0; i < l; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
