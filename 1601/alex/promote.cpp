//Alex Yang
//6 minutes

#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
	ifstream fin ("promote.in");
	ofstream fout ("promote.out");
	int before[4];
	int after[4];
	for (int i = 0; i < 4; i++)
	{
		fin >> before[i] >> after[i];
	}

	fout << after[1]+after[2]+after[3]-before[1]-before[2]-before[3] << "\n" << after[2]+after[3]-before[2]-before[3] << "\n" << after[3]-before[3] << "\n";
}
