//ALEX
//45 MINUTES

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
int main ()
{	
	ifstream fin ("circlecross.in");
	ofstream fout ("circlecross.out");
	
	string order;
	fin >> order;

	int count;
	char temp;
	int first[26];
	int second[26];
	fill(first, first + 26, -1);
	int num;

	for (int i = 0; i < 52; i++)
	{
		num = -int('A' - order.at(i));
		if (first[num] == -1)
		{
			first[num] = i;
		}
		else 
		{
			second[num] = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{		
		for (int k = 0; k < 26; k++)
		{
			if (first[i] < first[k] && first[k] < second[i] && second[i] < second[k])
			{
				cout << i << " " << k << "\n";
				//cout << first[i] << " " << first[k] << " " << second[i] << " " << second[j] << "\n";
				count ++;
			}
		}
	}
	fout << count << "\n";
}
