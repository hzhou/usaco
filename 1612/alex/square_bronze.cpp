//ALEX YANG

#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
        ifstream fin ("square.in");
        ofstream fout ("square.out");
        int x1, x2, x3, x4, y1, y2, y3, y4;
        fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        fout << pow(max(max(max(y1,y2),max(y3,y4)) - min( min(y1,y2),min(y3,y4) ), max(max(x1,x2),max(x3,x4)) - min(min(x1,x2),min(x3,x4))) , 2)<< "\n";
}