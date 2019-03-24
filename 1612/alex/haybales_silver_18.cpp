#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

int binarya(int arr[], int low, int max, int x)//Binary search for x
{
        while (low <= max)
        {
                int mid = low + (max-low)/2;
                if (arr[mid] == x)
                {
                        return mid;
                }
                if (arr[mid] < x)
                {
                        low = mid + 1;
                }
                else
                {
                        max = mid - 1;
                }
        }
        return -1;
}



int binary(int arr[], int low, int max, int x)//Binary search for x
{
	while (low <= max)
	{
		int mid = low + (max-low)/2;
		if (arr[mid] == x)
		{
			return mid;
		}
		if (arr[mid] < x)
		{
			low = mid + 1;
		}
		else
		{
			max = mid - 1;
		}
	}
	return max;
}// Returns number of elements less than or equal to x.

int main()
{
	ifstream fin ("haybales.in");
	ofstream fout ("haybales.out");
	
	int length, pairs;
	fin >> length >> pairs;
	int locations[length];
	int A[pairs];
	int B[pairs];
	for (int i = 0; i < length; i++)
	{
		fin >> locations[i];
	}
	for (int i = 0; i < pairs; i++)
	{
		fin >> A[i] >> B[i];
	}

	sort(locations, locations+length);
	int extra;
	for (int i = 0; i < pairs; i++)
	{//MAKE A CASE FOR IF A VALUE IS IN HAYBALES. IF ITS IN HAYBALES, ADD 1
		extra = 1;
		if (binarya(locations, 0, length, A[i])==-1)
		{
			extra = 0;
		}
		fout << extra + binary(locations, 0, length, B[i]) - binary(locations, 0, length, A[i]) << "\n";
	}
}
