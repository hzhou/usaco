//Alex Yang 60 minutes, missing cases where not everything connects
//no idea how to fix
//read solution
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin ("moocast.in");
	ofstream fout ("moocast.out");

	int N;
	fin >> N;
	int X[N], Y[N];
	for(int i = 0; i < N; i++)
	{
		fin >> X[i] >> Y[i];
	}
	int min;
	int highestmin = 0;
	for(int i = 0; i < N; i++)
	{
		min = 2000000000;
		for(int j = 0; j < N; j++)
		{
			if((X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]) < min and i != j)
			{
				min = (X[i]-X[j])*(X[i]-X[j])+(Y[i]-Y[j])*(Y[i]-Y[j]);
			}
		}
		if(min > highestmin and min != 2000000000)
		{
			highestmin = min;
		}
	}
	fout << highestmin << "\n";
}
