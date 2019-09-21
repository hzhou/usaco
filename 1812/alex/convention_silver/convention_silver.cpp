//Alex Yang, 1 hour 20 minutes
//Why doesn't it work?
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n, m, c;
int t[100000];
bool check(int wait)
{
	int first = 0;
	int buses = 1;
	for(int i = 1; i < n; i++)
	{
		if(t[i] - t[first] > wait or i-first+1 > c)
		{
			buses++;
			first = i;
		}
	}
	return (buses <= m);
}

int bin(int i1, int i2)
{
	if(i1 == i2)
	{
		return i1;
	}
	if(i1+1 == i2)
	{
		if(check(i1))
		{
			return i1;
		}
		return i2;
	}
	int i3 = (i1+i2)/2;
	if(check(i3))//go lower
	{
		return bin(i1, i3);
	}
	else//go higher
	{
		return bin(i3+1,i2);
	}
}

int main()
{
	ifstream fin ("convention.in");
	ofstream fout ("convention.out");
	
	fin >> n >> m >> c;
	for(int i = 0; i < n; i++)
	{
		fin >> t[i];
	}
	sort(t, t + n);
	fout << bin(0,100000) << "\n";
}
