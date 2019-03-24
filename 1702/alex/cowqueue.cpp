#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;

//Map time to questioning time. Sort by arrival time. Keep a list of time. If time after questioning a cow < next cow arrival time, time is arrival + questioning time. If time > questioning time, time is time + questioning time. max(time, arrival)
//15 is answer
int main ()
{
	ifstream fin ("cowqueue.in");
	ofstream fout ("cowqueue.out");
	
	int n;
	fin >> n;
	map<int, int> qtime;//mapping arrival to questioning time

	int a, b;
	int arrival[n];//arrival times, sorted
	for (int i = 0; i < n; i++)
	{
		fin >> a >> b;
		qtime[a] = b;
		arrival[i] = a;
	}
	sort(arrival, arrival+n);
	int time = 0; //keep track of time

	for (int i = 0; i < n; i++)
	{
		time = max(time, arrival[i]) + qtime[arrival[i]];
	}
	fout << time << "\n";
}
