#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin ("planting.in");
	ofstream fout ("planting.out");

	int n;
	fin >> n;
	int nodes[n];
	for(int i = 0; i < n; i ++)
	{
		nodes[i] = 0;
	}
	int temp;
	for (int i = 0; i < n - 1; i++)
	{
		fin >> temp;
		nodes[temp] = nodes[temp] + 1;
		fin >> temp;
		nodes[temp] = nodes[temp] + 1;
	}
	int max = 0;
	for(int i = 0; i < n; i++)
	{
		if (nodes[i] > max)
		{
			max = nodes[i];
		}
	}
	fout << max + 1 << "\n";
}
