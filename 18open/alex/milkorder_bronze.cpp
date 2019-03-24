#include <cstdio>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iterator>
using namespace std;

int checknull (int anarray[], int size, int afterpos)
{
        for (int i = 0; i < size; i++)
        {
                if (anarray[size-i-1]== 0 && size-i-1 < afterpos)
                {
                        return size-i-1;
                }
        }
}

int findd (int anarray[], int size, int searchfor)
{
        for (int i = 0; i < size; i++)
        {
                if (anarray[i] == searchfor)
                {
                        return i;
                }
        }
        return 1924;
}

int main()
{
        ifstream fin ("milkorder.in");
        ofstream fout ("milkorder.out");

        int n, s, p;
        fin >> n >> s >> p; //N is number of cows. S is number of social cows. P is number of position cows
        int temp1, temp2;

        int order[n]={0};
        int social[s];

        for (int i = 0; i <s; i++)
        {
                fin >> social[i];
        }

        for (int i = 0; i < p; i++)
        {
                fin >> temp1 >> temp2;
                order[temp2 - 1] = temp1;
        }
        for (int i = 0; i < s; i++)
        {
                bool exists = findd(order, n, social[s-i-1]) != 1924;
                if (exists == false)
                {
                        if (i == 0)
                        {
                                order[checknull(order, n, 200)] = social[s-i-1];
                        }
                        else
                        {
                                order[checknull(order, n, (findd( order, n, social[s-i] )))] = social[s-i-1];
                        }
                }
        }
        fout << checknull(order, n, 200) << "\n";
}
