#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int findindex(int arr[], int l, int var)
{
	for(int i = 0; i < l; i++)
	{
		if(arr[i] == var)
		{
			return i;
		}
	}
}
int piqas(int x1, int x2, int y1, int y2)
{
	return (x2-x1)*(y2-y1);
}
int main()
{
	ifstream fin ("reduce.in");
	ofstream fout ("reduce.out");
	
	int n;
	fin >> n;
	int x[n];
	int y[n];
	int xa[n];
	int ya[n];
	for(int i = 0; i < n; i++)
	{
		fin >> x[i] >> y[i];
		xa[i] = x[i];
		ya[i] = y[i];
	}
	sort(xa, xa + n);
	sort(ya, ya + n);
	int x1 = xa[0];
	int x2 = xa[1];
	int x3 = xa[n-2];
	int x4 = xa[n-1];
	int y1 = ya[0];
	int y2 = ya[1];
	int y3 = ya[n-2];
	int y4 = ya[n-1];
        printf("%d %d %d %d\n", xa[0], xa[1], xa[2], xa[3]);
        printf("%d %d %d %d\n", ya[0], ya[1], ya[2], ya[3]);
        printf("%d %d %d %d %d %d %d %d\n", x1, x2, x3, x4, y1, y2, y3, y4);
	//test remove x1 , x4, y1, y4;
	//find second to last x's and y's
	int min = 999999;
	if(y[findindex(x, n, x1)] == y1)
	{
		if(piqas(x2, x4, y2, y4) < min)
		{
			min = piqas(x2, x4, y2, y4);
		}
	}
	else if(y[findindex(x, n, x1)] == y4)
        {
                if(piqas(x2, x4, y1, y3) < min)
                {
                        min = piqas(x2, x4, y1, y3);
                }
        }
	else
	{
		if(piqas(x2, x4, y1, y2) < min)
		{
			min = piqas(x2, x4, y1, y4);
		}
	}
	
	
	if(y[findindex(x, n, x4)] == y1)
        {
                if(piqas(x1, x3, y2, y4) < min)
                {
                        min = piqas(x1, x3, y2, y4);
                }
        }
        else if(y[findindex(x, n, x4)] == y4)
        {
                if(piqas(x1, x3, y1, y3) < min)
                {
                        min = piqas(x1, x3, y1, y3);
                }
        }
        else
        {
                if(piqas(x2, x4, y1, y2) < min)
                {
                        min = piqas(x1, x3, y1, y4);
                }
        }

	fout << min << "\n";
}
