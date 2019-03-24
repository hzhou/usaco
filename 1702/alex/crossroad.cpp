//ALEX
//10 MINUTES
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin ("crossroad.in");
	ofstream fout ("crossroad.out");
	int n;
	fin >> n;

	int arr[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};//values of cow 1-10
	int cow;//cow id
	int pos;//side of road
	int count = 0; //count of crosses
	for (int i = 0; i < n; i++)
	{
		fin >> cow >> pos;
		if (arr[cow-1]!=-1)
		{
			if (arr[cow-1]!=pos)
			{
				arr[cow-1] = pos;
				count ++;
			}
		}
		else
		{
			arr[cow-1] = pos;
		}
	}
	fout << count << "\n";
}
