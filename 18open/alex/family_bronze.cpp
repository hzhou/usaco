//ALEX, DIDNT FINISH
#include <cstdio>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main ()
{
        ifstream fin ("family.in");
        ofstream fout ("family.out");

        int n;
        string bessie, elsie;
        fin >> n >> bessie >> elsie;
        cout << "bessie: "<<bessie <<"\n";
        const char* s_A = bessie.c_str();
        printf("%c\n", bessie[1]);

/*
        string mothers[n];
        string daughters[n];

        for (int i = 0; i < n; i++)
        {
                fout >> mothers[i] >> daughters[i];
        }
        int b, e;

        for (int i = 0; i < n; i++)
        {
                if (daugters[i] == besie)
                {
                        b = i;
                }
                if (daugthers[i] == elsie)
                {
                        e = i
                }
        }
        if (mothers[b] == mothers[e])
        {
                //they are siblings
        }

        //check if mother of besie/elsie is tempcow
        //mothers[b] is bessies mother, mothers[e] is elsies mom
        string tempcow = besie;
        for (int i = 0; i < 1000; i++)
        {
                for (int x = 0; x < n; x++)
                {
                        if (daughters[x] == tempcow)
                        {
                                if (mothers[x] == mothers[e])
                                {
                                        //Greatt aunt or something
                                }
                                if (mothers[x] == elsie)
                                {
                                        //Elsie is the great*(i-2)grandma of bessie
                                }
                        }
                }
        }
        tempcow = elsie;
        for (int i = 0; i < 1000; i++)
        {
                for (int x = 0; x < n; x++)
                {
                        if (daughters[x] == tempcow)
                        {
                                if (mothers[x] == mothers[b])
                                {
                                        //Greatt aunt or something
                                }
                                if (mothers[x] == besie)
                                {
                                        //Elsie is the great*(i-2)grandma of bessie
                                }
                        }
                }

        }
*/
}
