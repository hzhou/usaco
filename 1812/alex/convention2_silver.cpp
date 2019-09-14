//Alex Yang, total 1 hour 15 minutes
//Spend 30 min debugging a bug. 
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ifstream fin ("convention2.in");
	ofstream fout ("convention2.out");
	int n;
	fin >> n;
	int a[n][3];
	int t[n];//a is arrival time. t is how long the cow will spend
	t[3] = 3;
	for(int i = 0; i < n; i++)
	{
		fin >> a[i][0] >> t[i];//or map the times the cows will spend to when they arrive
		a[i][1] = t[i];
		a[i][2] = i;
	}
	//i couldn't find a way to sort by arrival time
	//wrote out the solution on paper
}
