//ALEX YANG
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main ()
{
        ifstream fin ("cowsignal.in");
        ofstream fout ("cowsignal.out");
        int a, b, c;
        string abc;
        fin >> a >> b >> c;
        for (int i = 0; i < b; i++)
        {
                for (int x = 0; x < a; x++)
                {
                        //Can you do this? Does fin overwrite abc?
                        fin >> abc;//MY COMPILER WON'T WORK FOR SOME REASON. WHEN I USE fout, A NEW FILE APPEARS BUT THE FILE IS EMPTY.
                        for (int z = 0; z < c; z++)
                        {
                                fout << abc;
                        }
                }
                fout << "\n";
        }
}
