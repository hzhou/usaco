//Alex Yang
//3 Minutes
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin ("paint.in");
	ofstream fout ("paint.out");
	
	int a, b, c, d;
	fin >> a >> b >> c >> d;
	
	fout << min(abs(a-b)+abs(c-d),max(max(a,b),max(c,d))-min(min(a,b),min(c,d))) << "\n";
}
