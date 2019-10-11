//Alex Yang, 1 hour, WHY IS MY FILE MISSING? Does fout not work?
#include <iostream>
#include <fstream>
#include <map>
using namespace std;
struct log
{
	int day;
	int id;
	int change;
};
bool compare(log a, log b)
{
	return a.day<b.day;
}
int main()
{
	ifstream fin ("measurement.in");
	ofstream fout ("measurement.out");
	int n, g;
	fin >> n >> g;
	log logs[n];
	for(int i = 0; i < n; i++)
	{
		fin >> logs[i].day >> logs[i].id >> logs[i].change;
	}
	map<int, int> cows;
	sort(logs, logs+n,compare);
	//run through every data thing.
	int maxx = 0;
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		if(cows.find(logs[i].id) == cows.end())
		{
			cows[logs[i].id] = logs[i].change;
			if(logs[i].change >= maxx)
			{
				count++;
				maxx = logs[i].change;
			}
		}
		else
		{
			if(cows[logs[i].id] == maxx)
			{
				if(logs[i].change<0)
				{
					count++;
				}
			}
			cows[logs[i].id] = cows[logs[i].id] + logs[i].change;
			if(cows[logs[i].id] >= maxx)
			{
				maxx = cows[logs[i].id];
				count++;
			}
		}
	}
	fout << count << "\n";
}
