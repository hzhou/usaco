//Alex Yang 45 minutes 7/10 cases
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin ("hps.in");
	ofstream fout ("hps.out");

	int n;
	char temp;
	fin >> n;
	int arr[n];
	int arr2[3] = {0,0,0};
	for (int i = 0; i < n; i++)
	{
		fin >> temp;
		if (temp == 'H')
		{
			arr[i] = 1;
			arr2[0]++;
		}
		if (temp == 'P')
                {
                        arr[i] = 2;
			arr2[1]++;
                }
		if (temp == 'S')
                {
                        arr[i] = 3;
			arr2[2]++;
                }
	}

	int answer = 0;
	int s1;
	int s2;
	int s3;
	int e1;// number of ones - s1
	int e2;
	int e3;
	for(int i = 0; i < n; i++)
	{
		s1 = 0;
		s2 = 0;
		s3 = 0;
		for(int j = 0; j < i ; j++)
		{
			if(arr[j] == 1)
			{
				s1++;
			}
			else if(arr[j] == 2)
			{
				s2++;
			}
			else if(arr[j] == 3)
			{
				s3++;
			}
		}
		e1 = arr2[0] - s1;
		e2 = arr2[1] - s2;
		e3 = arr2[2] - s3;
		if (s1+e2 > answer)
		{
			answer = s1+e2;
		}
		if (s1+e3 > answer)
                {
                        answer = s1+e3;
                }
		if (s2+e1 > answer)
                {
                        answer = s2+e1;
                }
		if (s2+e3 > answer)
                {
                        answer = s2+e3;
                }
		if (s3+e1 > answer)
                {
                        answer = s3+e1;
                }
		if (s3+e2 > answer)
                {
                        answer = s3+e2;
                }
	}
	fout << answer << "\n";
}
