//Alex
//15 minutes
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;


int main ()
{
	ifstream fin ("hps.in");
	ofstream fout ("hps.out");
	
	int n;
	fin >> n;
	
	int wins[] = {0,0};
	int a, b;

	for (int i = 0; i < n; i++)
	{
		fin >> a >> b;
		if (a == b + 1 | a == b - 2)
		{
			wins[0]++;
		}
		else if (a == b - 1 | a == b + 2)
		{
			wins[1]++;
		}
	}
	fout << max(wins[0], wins[1]) << "\n";
}
