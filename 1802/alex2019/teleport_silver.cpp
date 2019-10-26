//Alex Yang 2 hours, I read solution
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
using namespace std;

int main()//-10^8 to 10^8, use long long int
{
	ifstream fin ("teleport.in");
	ofstream fout ("teleport.out");
	int N;
	fin >> N;
	int a;
	int b;
	long long currentf = 0;
	map<int, int> slopechange;//maps the change in slope to its point. slope is relative to not using the teleporter

	for(int i = 0; i < N; i++)
	{
		fin >> a >> b;
		currentf += abs(a-b);

		//find changes in slope
		if(abs(a-b) <= abs(a)) {continue;};
		slopechange[b] += 2;
		if(a<0 and b<=a) {slopechange[2*b-2*a]--; slopechange[2*a]--;};
		if(a>=0 and b>a) {slopechange[2*b-2*a]--; slopechange[2*a]--;};
		if(a>0 and b<0) {slopechange[0]--;slopechange[2*b]--;};
		if(a<0 and b>0) {slopechange[0]--;slopechange[2*b]--;};
	}

	int oldy = 0, newy, oldslope = 0;
	long long minf = currentf;
	for(auto p:slopechange)
	{
		newy = p.first;
		currentf += (newy-oldy)*oldslope;
		oldy = newy;
		oldslope += p.second;
		minf = min(minf, currentf);
	}
	fout << minf << "\n";
}
