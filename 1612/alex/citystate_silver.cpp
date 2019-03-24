//Alex Yang, can't figure out how to use a hash map, 50 minutes
#include <iostream>
#include <fstream>
#include <string>
#include <map>
//#include <algorithm>
using namespace std;

int main()
{
	ifstream fin ("citystate.in");
	ofstream fout ("citystate.out");

	int n;
	fin >> n;
	string temp;
	string temp2;
	string temp3;
	string pairs[n];
	for(int i = 0; i < n; i++)
	{
		temp2 = "";
		fin >> temp >> temp3;
		temp2.append(1, temp[0]);
		temp2.append(1, temp[1]);
		temp3.append(1, temp2);
		temp3.append(1, temp3);
		pairs[i] = temp3;

	}
	map<int, string> listt;
	int answer = 0;
	int x = 0;
	for(int i = 0; i < n; i++)
	{
		if (listt.find(pairs[i]) == listt.end())
		{
			listt[x] = pairs[i];
			x++;
		}
		else
		{
			answer++;
		}
	}
	fout << answer/2 << "\n";
}
