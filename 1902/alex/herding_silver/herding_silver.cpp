#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int n;
int minmoves(int location[])
{
	int start = 0;
	int end = 1;
	int maxx = 0;
	while(end < n)//ends when end index hits the end
	{
		if(location[end] - location[start] + 1 > n)
		{
			if (maxx < end - start)
			{
				maxx = end - start;
			}
			start++;
		}
		else if(location[end] - location[start] + 1 == n)
		{
			if(maxx < end - start + 1)
			{
				maxx = end - start + 1;
			}
			start++;
			end++;
		}
		else
		{
			end++;
		}
	}
	return n - maxx;
}

int main()
{
	ifstream fin ("herding.in");
	ofstream fout ("herding.out");

	fin >> n;
	int location[n];
	for(int i = 0; i < n; i++)
	{
		fin >> location[i];
	}
	sort(location, location + n);
	fout << minmoves(location) << "\n" << max(location[n-2]-location[0],location[n-1]-location[1])-n+2;
}
