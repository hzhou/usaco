//Alex Yang
//35 minutes
#include <iostream>
#include <fstream>
using namespace std;
int main ()
//ONLY KEEP EARLIEST TIME A PERSON DRANK A MILK
{//input: peoples milks dranks sicks
	ifstream fin ("badmilk.in");
	ofstream fout ("badmilk.out");
	int a, b, c, d;
	fin >> a >> b >> c >> d;
	int people[a][b] = {}; 
	int tempperson;
	int tempmilk;
	int temptime;
	for (int i = 0; i < c; i++)
	{
		fin >> tempperson >> tempmilk >> temptime;
		if (temptime < people[tempperson-1][tempmilk-1] | people[tempperson-1][tempmilk-1] == 0)
		{
			people[tempperson-1][tempmilk-1] = temptime;
		}
	}//time milk m drank by person p = people[p-1][m-1]
	
	int possible[b] = {};//if a sick person didn't drink a certain milk before getting sick, change the milk's possible value to 1
	for (int i = 0; i < d; i++)
	{
		fin >> tempperson >> temptime;
		for (int j = 0; j < b; j++)
		{
			if (people[tempperson-1][j] >= temptime | people[tempperson-1][j] == 0)
			{
				possible[j] = 1;
			}
		}
	}
	
	int countt;
	int maxx = 0;

	for (int i = 0; i < b; i++)
	{
		countt = 0;
		if (possible[i] == 0)
		{
			for (int j = 0; j < a; j++)
			{
				if (people[j][i] != 0)
				{
					countt ++;
				}
			}
		}
		if (countt > maxx)
		{
			maxx = countt;
		}
	}
	fout << maxx << "\n";
}//calculate max amount of possible sicks
