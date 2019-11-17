//Alex Yang, 2 hours
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int dist(int x1, int y1, int x2, int y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
long aDP[1001][1001];
long bDP[1001][1001];
int main()
{
	ifstream fin ("checklist.in");
	ofstream fout ("checklist.out");
	int a, b;
	fin >> a >> b;
	int Ax[a+1], Ay[a+1], Bx[b+1], By[b+1];
	Ax[0] = 2000;
	Ay[0] = 2000;
	Bx[0] = 2000;
	By[0] = 2000;
	for(int i = 1; i < a+1; i++)
	{
		fin >> Ax[i] >> Ay[i];
	}
	for(int i = 1; i < b+1; i++)
	{
		fin >> Bx[i] >> By[i];
	}

	for(int i = 0; i < a+1; i++)
	{
		for(int j = 0; j < b+1; j++)
		{
			aDP[i][j] = 2000000000;
			bDP[i][j] = 2000000000;
		}
	}
	aDP[1][0] = 0;
	for(int i = 1; i < a+1; i++)
	{
		for(int j = 0; j < b+1; j++)
		{
			if(i > 1)
			{
                            aDP[i][j] = min(bDP[i-1][j]+dist(Ax[i],Ay[i],Bx[j],By[j]),min(aDP[i][j],aDP[i-1][j]+dist(Ax[i-1],Ay[i-1],Ax[i],Ay[i])));
			}
			//cout << bDP[i][j] << "\n";
			if(j > 0)
			{
                            bDP[i][j] = min(aDP[i][j-1]+dist(Bx[j],By[j],Ax[i],Ay[i]),min(bDP[i][j],bDP[i][j-1]+dist(Bx[j-1],By[j-1],Bx[j],By[j])));
			}
			//cout << "i" << i << "j" << j << "\n";
			//cout << aDP[i][j] << " " << bDP[i][j] << "\n";
		}
	}
	fout << aDP[a][b] << "\n";
}
