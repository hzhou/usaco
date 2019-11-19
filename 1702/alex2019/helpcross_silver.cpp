#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;
struct cow
{
	int start;
	int end;
};
int main()
{
	ifstream fin ("helpcross.in");
	ofstream fout ("helpcross.out");
	int C, N, T[20000];
	fin >> C >> N;
	for(int i = 0; i < C; i++)
	{
		fin >> T[i];
	}
	sort(T, T+C);
	map<int, int> start;
	cow cows[N];
	for(int i = 0; i < N; i++)
	{
		fin >> cows[i].start >> cows[i].end;
	}
	sort(cows, cows + N,[](cow a, cow b){return a.end<b.end;});
	int used[N];
	for(int i = 0; i < N; i++)
	{
		used[i] = 0;
	}
	int count = 0;
	for(int i = 0; i < C; i++)
	{
		for(int j = 0; j < N; j++)
		{
			//cout << i << " " << j << "   " << cows[j].start << " " << cows[j].end <<" " << T[i]<< "\n";
			if(cows[j].start<=T[i] and T[i]<=cows[j].end and used[j] != 1)
			{
				//cout << i << " " << j << "   " << cows[j].start << " " << cows[j].end <<" " << T[i]<< "\n";
				count++;
				used[j] = 1;
				break;
			}
		}
	}
	fout << count << "\n";
}
