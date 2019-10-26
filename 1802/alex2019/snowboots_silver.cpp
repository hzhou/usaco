//Alex Yang, 1 hour
#include <iostream>
#include <fstream>
using namespace std;

int N, B, snow[250], depth[250], dist[250];
bool visited[250][250];
int low = 250;

void backtrack(int a, int b)
{//a is snow index. b is boot index
	if(visited[a][b])
	{
		return;
	}
	visited[a][b] = true;
	for(int i = b; i < B; i++)
	{
		if(depth[i] >= snow[a])
		{
			for(int j = 1; j <= dist[i]; j++)
			{
				if(a+j == N - 1)
				{
					if(low > i)
					{
						low = i;
					}
					return;
				}
				if(depth[i] >= snow[a+j])
				{
					backtrack(a+j, i);
				}
			}
		}
	}
}

int main()
{
	ifstream fin ("snowboots.in");
	ofstream fout ("snowboots.out");
	fin >> N >> B;
	for(int i = 0; i < N; i++)
	{
		fin >> snow[i];
	}
	for(int i = 0; i < B; i++)
        {
                fin >> depth[i] >> dist[i];
        }

	backtrack(0,0);
	fout << low << "\n";
}
