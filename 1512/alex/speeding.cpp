//ALEX YANG
//35 minutes
//
#include <iostream>
#include <fstream>
using namespace std;
//length segment format
int main()
	//if bessies seg is between two parts
{
	ifstream fin ("speeding.in");
	ofstream fout ("speeding.out");
	
	int a, b;
	fin >> a >> b;
	int temp1, temp2;
	int limit[100];
	int mile = 0;
	for (int i = 0; i < a; i++)
	{
		fin >> temp1 >> temp2;
		for (int j = 0; j < temp1; j++)
		{
			limit[mile] = temp2;
			mile++;
		}
	}
	int speed[100];
	mile = 0;
	for (int i = 0; i < b; i++)
	{
		fin >> temp1 >> temp2;
		for (int j = 0; j < temp1; j++)
		{
			speed[mile] = temp2;
			mile++;
		}
	}
	int maxx = 0;
	for (int i = 0; i < 100; i++)
	{
		if (maxx < speed[i]-limit[i])
		{
			maxx = speed[i]-limit[i];
		}
	}
	fout << maxx << "\n";
}
