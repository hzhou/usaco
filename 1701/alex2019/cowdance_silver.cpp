//Alex Yang, doesn't work?? Incorrect answer on sample case.
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int* cows;
int Tmax, N;
bool time(int K)
{
	int dancing[K];
	int time;
	int index = K;
	for(int i = 0; i < K; i++)
	{
		dancing[i] = cows[i];
	}
	for(int i = 0; i < N - 1; i++)
	{
		sort(dancing, dancing + K);
		time = dancing[0];
		dancing[0] = time + cows[index];
		index++;
	}
	return (time <= Tmax);
}

int main()
{
	ifstream fin ("cowdance.in");
	ofstream fout ("cowdance.out");
	fin >> N >> Tmax;
	cows = new int[N];
	for(int i = 0; i < N; i++)
	{
		fin >> cows[i];
	}
	int i1, i2, i3;
	i1 = 1;
	i2 = N;
	
	while(i1<i2)
	{
		i3 = (i1+i2)/2;
		if(time(i3))
		{//works, short enough
			i2 = i3-1;
		}
		else
		{//too long
			i1 = i3+1;
		}
	}
	fout << i1 << "\n";
}
