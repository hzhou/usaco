//Alex Yang, 24 minutes
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream fin ("homework.in");
	ofstream fout ("homework.out");
	int n;
	fin >> n;
	int sum = 0;
	int values[n];
	int min = 10000;
	for(int i = 0; i < n; i++)
	{//find min here
		fin >> values[i];
		if (values[i] < min)
		{
			min = values[i];
		}
		sum += values[i];
	}
	float max = 0;
	string answer = "";
	for(int i = 0; i < n - 2; i++)
	{
		if(values[i] == min)
		{//find new min
			min = 10000;
			for(int j = i+1; j < n; j++)
			{
				if(values[j] < min)
				{
					min = values[j];
				}
			}
		}
		sum -= values[i];
		if(float(sum - min)/float(n-i-2) > max)
		{
			max = float(sum - min)/float(n-i-2);
			answer = to_string(i+1);
		}
		else if(float(sum - min)/float(n-i-2) == max)
		{
			answer = answer + "\n" + to_string(i+1);
		}
	}
	fout << answer <<"\n";
}
