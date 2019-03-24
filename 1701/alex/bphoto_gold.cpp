//Alex Yang. I thought of finding the total number of cows taller than each cow by taking all the heights and sorting them into a list.
//I would then only have to find how many cows are taller on either its left or right side. I can't think of any ways to cache values;
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
	ifstream fin ("bphoto.in");
	ofstream fout ("bphoto.out");
	int n;
	fin >> n;
	int realarr[n];
	int sortarr[n];
	for(int i = 0; i < n; i++)
	{
		fin >> realarr[n];
		sortarr[n] = realarr[n];
	}
	sort(sortarr, sortarr+n);
}
