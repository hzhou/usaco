//Alex Yang, really messy code, gave up. 
#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	ifstream fin ("bphoto.in");
	ofstream fout ("bphoto.out");

	int N;
	fin >> N;
	int Order[N], temp[N];
	for(int i = 0; i < N; i++)
	{
		fin >> Order[i];
		temp[i] = Order[i];
	}
	sort(temp, temp+N);
	map<int,int> taller;
	for(int i = 0; i < N; i++)
	{
		taller[temp[i]] = N-1-i;
	}
	int leftof = 0;
	int count = 0;
	for(int i = 0; i < N; i++)
	{
		leftof = 0;
		for(int j = 0; j < i; j++)
		{
			if(Order[j]>Order[i])
			{
				leftof++;
			}
		}
		if((taller[Order[i]]==leftof and leftof!=0) or (leftof == 0 and taller[Order[i]]!=0))
		{
			count++;
			continue;
		}
		else if(taller[Order[i]] == 0)
		{
			continue;
		}
		if(leftof/(taller[Order[i]]-leftof)>=2 || (taller[Order[i]]-leftof)/leftof>=2)
		{
			cout << Order[i]<< "\n";
			count++;
		}
	}
	cout << count << "\n";
}
