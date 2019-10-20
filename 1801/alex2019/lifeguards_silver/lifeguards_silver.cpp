#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct log
{
	int start;
	int end;
};
bool compare(struct log a, struct log b)
{
	return a.start < b.start;
}
int main()
{
	ifstream fin ("lifeguards.in");
	ofstream fout ("lifeguards.out");
	int n;
	fin >> n;
	struct log times[n];
	for(int i = 0; i < n; i++)
	{
		fin >> times[i].start >> times[i].end;
	}
	sort(times, times + n, compare);
	int minn = 10000000;
	//find time w/o removing things
	int a, b;
	a = 0;
	b = 0;
	int endval = times[b].end;
	int length = 0;
	int check = 0;
	while(b < n)
	{
		if(endval > times[b+1].start)
		{
			b++;
			if(endval < times[b+1].end)
			{
				endval = times[b+1].end;
			}
		}
		else
		{
			check = 1;
			length += endval - times[a].start;
			a = b + 1;
			b = b + 1;
			endval = times[b].end;
		}
		if(b >= n-1 and check == 0)
		{
			length += endval - times[a].start;
		}
	}
	for(int i = 0; i < n-1; i++)
	{//what if no intersection
		if(minn > min(times[i+1].start, times[i].end) - times[i].start)
		{
			minn = min(times[i+1].start, times[i].end) - times[i].start;
		}
		times[i+1].start = max(times[i+1].start, times[i].end);
	}
	//if minn is smaller than 0 then there is no gap
	fout << length - max(0,minn) << "\n";
}
