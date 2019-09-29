//Alex Yang
#include <iostream>
#include <fstream>
using namespace std;

char* grid;
int n;
void flip(int a, int b)//a = 0 row. a = 1 column.
{
	if(a == 0)//row
	{
		for(int i = 0; i < n; i++)
		{
			if(grid[b*n+i] == 'R')
			{
				grid[b*n+i] = 'L';
			}
			else
			{
				grid[b*n+i] = 'R';
			}
		}
	}
        else//column
	{
                for(int i = 0; i < n; i++)
                {
                        if(grid[b+i*n] == 'R')
                        {
                                grid[b+i*n] = 'L';
                        }
                        else
                        {
                                grid[b+i*n] = 'R';
                        }
                }
        }
}

int main()
{
	ifstream fin ("leftout.in");
	ofstream fout ("leftout.out");

	fin >> n;
	grid = new char[n*n];
	for(int i = 0; i < n*n; i++)
	{
		fin >> grid[i];
	}
	for(int i = 0; i < n; i++)//top row and left column
	{
		if(grid[i] == 'R')//columns
		{//flip
			flip(1, i);
		}
		if(grid[i*n] == 'R')//rows
		{//flip
			flip(0, i);
		}
	}
	int check = 0;
	for(int i = 1; i < n; i++)
	{
		for(int j = 1; j < n; j++)
		{
			if(grid[i*n+j] == 'L')
			{
				check = 1;
			}
		}
	}
	if(check == 0)
	{//answer is 1,1
		fout << "1 1" << "\n";
		return 0;
	}
	for(int i = 1; i < n; i++)
	{//the odd one out is on the side if its LRRRR
		for(int j = 1; j < n; j++)
		{
			if(grid[i*n+j] == 'R' and grid[i*n+j-1] == 'L')
			{
				fout << i+1 << " " << j+1 << "\n";
				return 0;
			}
			if(grid[i+j*n] == 'R' and grid[i+j*n-n] == 'L')
			{
				fout << j + 1 <<" "<<i+1<<"\n";
				return 0;
			}
		}
	}
	fout << "-1\n";
	


	//or else odd one out is answer
	//if no odd one out, return -1
	//for each row/column check for an odd one out
}
