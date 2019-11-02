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
	sort(stops, stops + N, [](struct stop a, struct stop b){return a.distance>b.distance;});
	int high = 0;
	struct stop realstops[N];
	int index = 0;
	for(int i = 0; i < N; i++)
	{//stops is sorted backwards. Farthest first
		if(stops[i].taste > high)
		{
			realstops[index].distance = stops[i].distance;
			realstops[index].taste = stops[i].taste;
			high = stops[i].taste;
			index++;
		}//realstops[0] is the farthest. Run through realstops backwards
	}
	long long answer = 0;
	long long start = 0;
	long long rate = rF - rB;
	for(int i = index - 1; i > -1; i--)
	{
		cout << realstops[i].distance << " " << realstops[i].taste << "\n";
		answer += realstops[i].taste*(realstops[i].distance-start);
		start = realstops[i].distance;
	}
	answer = answer * rate;
	fout << answer << "\n";
}
