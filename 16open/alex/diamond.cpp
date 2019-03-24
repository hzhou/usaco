#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
	ifstream fin ("diamond.in");
	ofstream fout ("diamond.out");

	int n, k;
	fin >> n >> k;
	int diamond[n];
	for(int i = 0; i < n; i++)
	{
		fin >> diamond[i];
	}
	sort(diamond, diamond + n);
	int x = 0;
	int answer = 0;
	for(int i = 0; i < n; i++)
	{
		x = 0;
		for(int j = i; j < n; j++)
		{
			if(diamond[j]-diamond[i] <= k)
			{
				x++;
			}
		}
		if (x > answer)
		{
			answer = x;
		}
	}
	fout << answer << "\n";
}
