//Alex Yang, 30 minutes, stuck on binary search
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int finda(int haybales[], int a, int length)
{
	int x1 = 0;
	int x2 = length;
	int m;
	while (x2 > x1)
	{
		m = (x1+x2)/2;
		if (haybales[m] > a)
		{
			x2 = m - 1;
		}
		else if(haybales[m] < a)
		{
			x1 = m + 1;
		}
		else if(haybales[m] == a)
		{
			return m;//exact number, not index
		}
	}
	return x1;
}
int findb(int haybales[], int a, int length)
{
        int x1 = 0;
        int x2 = length;
        int m;
        while (x2 > x1)
        {
                m = (x1+x2)/2;
                if (haybales[m] > a)
                {
                        x2 = m - 1;
                }
                else if(haybales[m] < a)
                {
                        x1 = m + 1;
                }
                else if(haybales[m] == a)
                {
                        return m + 1;//exact number, not index
                }
        }
	int asdf = 0;
	if (haybales[x1] <= a)
	{
		asdf = 1;
	}
        return x1 + asdf;
}
int main()
{
	ifstream fin ("haybales.in");
	ofstream fout ("haybales.out");
	
	int n, q;
	fin >> n >> q;
	

	int haybales[n];
	for (int i = 0; i < n; i++)
	{
		fin >> haybales[i];
	}
	sort(haybales, haybales + n);
	int a;
	int b;
	for (int i = 0; i < q; i++)
	{
		fin >> a >> b;
		fout << findb(haybales, b, n - 1) - findb(haybales, a - 1, n - 1) << "\n";
	}
}
