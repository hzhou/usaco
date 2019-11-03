//Alex Yang 45 minutes
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ifstream fin ("sort.in");
	ofstream fout ("sort.out");
	int N;
	fin >> N;
	int sorted[N];
	int value;
	map<int, int> index;
	for(int i = 0; i < N; i++)
	{
		fin >> sorted[i];
		index[sorted[i]] = i;
	}//the index of value is i
	sort(sorted, sorted + N);
	int high = 0;
	for(int i = 0; i < N; i++)
	{
		if( i - index[sorted[i]] < high)
		{
			high = i - index[sorted[i]];
		}
	}
	fout <<  -high + 1 << "\n";
}
