//Alex Yang 40 minutes. I know I can binary search from 0 to n for the solution and test if each one works. I can't figure out how to count how much time it will take for a number of cows on the stage.
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int works(int arr[], int t, int n)
{
	int time = 0;
	int min;
	int indexmin;
	for(int i = 0; i < n; i++)
	{
		min = arr[0];
		for(int i = 1; i < t; i++)
		{
			if(arr[i] <= )
		}
	}
}

int main()
{
	ifstream fin ("cowdance.in");
	ofstream fout ("cowdance.out");

	int n;
	int t;
	fin >> n >> t;
	int arr[n];
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		fin >> arr[i];
		sum += arr[i];
	}
	
	sum = ceil(sum/t);
	for(int i = sum; i < n; i++)
	{//check if values of i for t work
		if(works(arr, i, n) <= t)
		{
			fout << i << "\n";
			return 0;
		}
	}
}
