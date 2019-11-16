//Alex Yang, incomplete
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

struct section
{
	int val;
	int len;
};

//only check gesture changes at changes
int main()
{
	ifstream fin ("hps.in");
	ofstream fout ("hps.out");
	int N, K;
	fin >> N >> K;
	section FJ[1000000];
	char temp1;
	char temp2;
	fin >> temp1;
	map<char,int> convert;
	convert['H'] = 0;
	convert['P'] = 1;
	convert['S'] = 2;
	int count = 1;
	int index = 0;
	for(int i = 1; i < N; i++)
	{
		fin >> temp2;
		if(temp1 != temp2)
		{
			FJ[index].val = convert[temp1];
			FJ[index].len = count;
			temp1 = temp2;
			count = 0;
			index++;
		}
		count++;
	}
	FJ[index].val = convert[temp1];
	FJ[index].len = count;
	//K changes. K+1 sections
	//Start with 1 section of only the most common H P or S. 
	//Find next best section until you have K+1 sections.
}
