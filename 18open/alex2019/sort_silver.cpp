//Alex Yang 30 minutes
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
	for(int i = 0; i < N; i++)
	{
		sorted[i] = index[sorted[i]];
	}
	int high = 0;
	int answer = 1;
	for(int i = 1; i < N; i++)
	{
		if(sorted[i] >= high)
		{
			answer++;
			high = sorted[i];
		}
	}
	fout << N - answer + 1 << "\n";
}
