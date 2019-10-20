//alex yang 2 hours
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct lifeguard
{
	int start;
	int end;
};
bool compare(struct lifeguard a, struct lifeguard b)
{
	return a.start < b.start;
}
int main()
{
	ifstream fin ("lifeguards.in");
	ofstream fout ("lifeguards.out");
	int n;
	fin >> n;
	struct lifeguard times[n];
	for(int i = 0; i < n; i++)
	{
		fin >> times[i].start >> times[i].end;
	}
	sort(times, times + n, compare);
	int minn = 10000000;
	int t1, t2;
	t1 = times[0].start;
	t2 = times[0].end;
	int length = 0;
	for(int i = 1; i < n; i++)
	{
		if(t2 > times[i].start)
		{
			if(t2 < times[i].end)
			{
				t2 = times[i].end;
			}
		}
		else
		{
			length += t2 - t1;
			t1 = times[i].start;
			t2 = times[i].end;
		}
	}
	length += t2 - t1;
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
