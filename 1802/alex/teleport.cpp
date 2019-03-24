#include <cstdio>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

struct place
{
        int s, e;
};

int main()
{
        ifstream fin ("teleport.in");
        ofstream fout ("teleport.out");

        place m, t;
        fin >> m.s >> m.e;
        fin >> t.s >> t.e;

        int a, b;
        a = abs(m.s-t.s) + abs(m.e-t.e);
        b = abs(m.s-t.e) + abs(m.e-t.s);
        fout << min(abs(m.s-m.e), min(a,b)) << "\n";
}
