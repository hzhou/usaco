//Alex Yang 1hour 45 minutes
//No idea why I'm failing so many cases

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int* graph;
int n;
int perimeter;
int area;

int findperi(int i, int j)
{
	graph[i*n+j] = 3;
	if(i < n - 1)
        {
                if(graph[(i+1)*n+j] == 2)
                {
                        findperi(i+1,j);
                }
		else if(graph[(i+1)*n+j] == 0)
		{
			perimeter++;
		}
        }
	else
	{
		perimeter++;
	}
        if(i > 0)
        {
                if(graph[(i-1)*n+j] == 2)
                {
                        findperi(i-1,j);
                }
		else if(graph[(i-1)*n+j] == 0)
                {
                        perimeter++;
                }
        }
	else
        {
                perimeter++;
        }
        if(j < n - 1)
        {
                if(graph[i*n+j+1] == 2)
                {
                        findperi(i,j+1);
                }
		else if(graph[i*n+j+1] == 0)
                {
                        perimeter++;
                }
        }
	else
        {
                perimeter++;
        }
        if(i > 0)
        {
                if(graph[i*n+j-1] == 2)
                {
                        findperi(i,j-1);
                }
		else if(graph[i*n+j-1] == 0)
                {
                        perimeter++;
                }
        }
	else
        {
                perimeter++;
        }
	return 0;
}

int fill(int i, int j)//coordinates to a point. row i+1, column j+1
{//watch the edges
	area++;
	graph[i*n+j] = 2;
	if(i < n - 1)
	{
		if(graph[(i+1)*n+j] == 1)
		{
			fill(i+1,j);
		}
	}
	if(i > 0)
        {
                if(graph[(i-1)*n+j] == 1)
                {
                        fill(i-1,j);
                }
        }
	if(j < n - 1)
        {
                if(graph[i*n+j+1] == 1)
                {
                        fill(i,j+1);
                }
        }
	if(i > 0)
        {       
                if(graph[i*n+j-1] == 1)
                {       
                        fill(i,j-1);
                }
        }
	return 0;
}

int main()
{
	ifstream fin ("perimeter.in");
	ofstream fout ("perimeter.out");
	fin >> n;
	graph = new int[n*n];
	string a;
	for(int i = 0; i < n; i++)
	{
		fin >> a;
		for(int j = 0; j < n; j++)//row i+1, column j+1
		{
			if(a[j] == '#')
			{
				graph[i*n+j] = 1;
			}
			else
			{
				graph[i*n+j] = 0;
			}
		}
	}
	int maxarea = 0;
	int maxperimeter;
	int temparea;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(graph[i*n+j] == 1)
                	{
				//cout << i << ", " << j << "\n";
                        	area = 0;
                      		fill(i,j);//area will change
				if(area > maxarea)
                        	{
                                	maxarea = area;
					perimeter = 0;
					findperi(i,j);
					maxperimeter = perimeter;
                        	}
                	}
		}
	}
	fout << maxarea << " "<< maxperimeter<< "\n";
}
