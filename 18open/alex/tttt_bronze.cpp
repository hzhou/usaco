//ALEX
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int check(char a, char b, char c)
{
        if (a == b && b == c)
        {
                return 2;
        }
        if (a == b|b == c|c==a)
        {
                return 1;
        }
        return 0;
}

int main()
{
        ifstream fin ("tttt.in");
        ofstream fout ("tttt.out");

        char a, b, c, d, e, f, g, h, i;
        fin >> a >> b >> c >> d >> e >> f >> g >> h >> i;

        int x = 0;
        int y = 0;

        if (check(a,b,c) == 1)
        {
                y++;
        }
        if (check(a,b,c) == 2)
        {
                x++;
        }
        if (check(d,e,f) == 1)
        {
                y++;
        }
        if (check(d,e,f) == 2)
        {
                x++;
        }
        if (check(g,h,i) == 1)
        {
                y++;
        }
        if (check(g,h,i) == 2)
        {
                x++;
        }
        if (check(a,d,g) == 1)
        {
                y++;
        }
        if (check(a,d,g) == 2)
        {
                x++;
        }
        if (check(b,e,h) == 1)
        {
                y++;
        }
        if (check(b,e,h) == 2)
        {
                x++;
        }
        if (check(c,f,i) == 1)
        {
                y++;
        }
        if (check(c,f,i) == 2)
        {
                x++;
        }
        if (check(a,e,i) == 1)
        {
                y++;
        }
        if (check(a,e,i) == 2)
        {
                x++;
        }
        if (check(g,e,c) == 1)
        {
                y++;
        }
        if (check(g,e,c) == 2)
        {
                x++;
        }
        fout << x << "\n" << y << "\n";
}