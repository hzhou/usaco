//Alex Yang, 50 minutes, issue with long int debug took 25 minutes;
//some cases still don't pass
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct stop
{
	int distance;
	int taste;
};
bool compare(struct stop a, struct stop b)
{
	return a.distance > b.distance;
}
int main()
{//fin places to stop
	ifstream fin ("reststops.in");
	ofstream fout ("reststops.out");
	int L, N, rF, rB;
	fin >> L >> N >> rF >> rB;
	struct stop stops[N];
	for(int i = 0; i < N; i++)
	{
		fin >> stops[i].distance >> stops[i].taste;
	}
	sort(stops, stops + N, compare);
	int high = 0;
	struct stop realstops[N];
	int index = 0;
	for(int i = 0; i < N; i++)
	{
		if(stops[i].taste > high)
		{
			realstops[index].distance = stops[i].distance;
			realstops[index].taste = stops[i].taste;
			high = stops[i].taste;
			index++;
		}
	}
	long long answer = 0;
        long long start = 0;
	long long rate = rF - rB;
	long long temp;
	for(int i = index - 1; i > -1; i--)
	{
		temp = realstops[i].distance-start;
		temp = temp*realstops[i].taste;
		answer = answer + temp;
		start = realstops[i].distance;
	}
	answer = answer * rate;
	fout << answer << "\n";
}
