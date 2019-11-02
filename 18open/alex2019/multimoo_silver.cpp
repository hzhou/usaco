//Alex Yang 1.5 hours.. Tried 2nd part. couldn't think of a way
#include <iostream>
#include <fstream>
using namespace std;
//findregion function?
//row i, column j

int N;
int* graph;
int findregion(int i, int j, int val)
{//i,j is i*N + j
	if (graph[i*N + j] != val)
	{
		return 0;
	}
	int answer = 1;
	graph[i*N + j] = -1;
	if(i > 0)
	{//down
		answer += findregion(i - 1, j, val);
	}
	if(i < N - 1)
	{//up
		answer += findregion(i + 1, j, val);
	}
	if(j > 0)
	{//left
		answer += findregion(i, j - 1, val);
	}
	if(j < N - 1)
	{//right
		answer += findregion(i, j + 1, val);
	}
	return answer;
}

int main()
{
	ifstream fin ("multimoo.in");
	ofstream fout ("multimoo.out");
	fin >> N;
	graph = new int[N*N];
	for(int i = 0; i < N*N; i++)
	{
		fin >> graph[i];
	}

	int high = 0;
	int temp;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(graph[i*N+j] != -1)
			{
				temp = findregion(i, j, graph[i*N + j]);
				if(temp > high)
				{
					high = temp;
				}
			}
		}
	}
	//one team at a time. sweep through all the ones adjacent to it. mark them. restart, mark the region

}
