#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
	ifstream fin ("angry.in");
	ofstream fout ("angry.out");
	int n;
	fin >> n;
	int haybales[n];
	for (int i = 0; i < n; i++)
	{
		fin >> haybales[n];
	}
	sort(haybales, haybales+n);
	
	
	for (int i = 0; i < n; i++)
	{
		//cout << haybales[n] << "\n";
	}
	cout << haybales[2];
	
	
	int temp;
	int radius;
	int maxx = 0;
	int exploded;
	for (int i = 0; i < n; i++)
	{
		temp = i;
		radius = 1;
		exploded = 0;
		while (temp > 0)
		{
			if (haybales[temp]-haybales[temp-1] <= radius)
			{
				temp--;
				radius++;
				exploded++;
			}
			else
			{
				break;
			}
		}
		
		temp = i;
		radius = 1;
		while (temp < n - 1)
                {
                        if (haybales[temp+1]-haybales[temp] <= radius)
                        {
                                temp++;
				radius++;
                                exploded++;
                        }
                        else
                        {
                        	break;
			}
                }


		if (exploded > maxx)
		{
			maxx = exploded;
		}
	}
	fout << maxx << "\n";
}
