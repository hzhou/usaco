//Alex
//35 mins + 2 hours debugging 3 typos
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;


string what (int na)
{
        if (na == 0)
        {
                return "Bessie";
        }
        if (na == 1)
        {
                return "Elsie";
        }
        if (na == 2)
        {
                return "Daisy";
        }
        if (na == 3)
        {
                return "Gertie";
        }
        if (na == 4)
        {
                return "Annabelle";
        }
        if (na == 5)
        {
                return "Maggie";
        }
        if (na == 6)
        {
                return "Henrietta";
        }
}
int main ()
{
        ifstream fin ("notlast.in");
        ofstream fout ("notlast.out");

        int n;
        fin >> n;
        int arr[7] { 0 };
        string cow;
        int number;
        for (int i = 0; i < n; i++)
        {
                fin >> cow;
                fin >> number;
                if (cow == "Bessie")
                {
                        arr[0] += number;
                }
                else if (cow == "Elsie")
                {
                        arr[1] += number;
                }
                else if (cow == "Daisy")
                {
                        arr[2] += number;
                }
                else if (cow == "Gertie")
                {
                        arr[3] += number;
                }
                else if (cow == "Annabelle")
                {
                        arr[4] += number;
                }
                else if (cow == "Maggie")
                {
                        arr[5] += number;
                }
                else if (cow == "Henrietta")
                {
                        arr[6] += number;
                }
        }

        int arr1[7] = { 0 };
        for (int i = 0; i < 7; i++)
        {
                arr1[i] = arr[i];
        }
        sort(arr1, arr1+7);
        int duplicates = -1;
        for (int i = 0; i < 7; i++)
        {
                if (arr1[i] == arr1[0])
                {

                        duplicates ++;
                }
        }
        //duplicates is index of array of 2nd to last
        if (duplicates == 6)
        {
                fout << "Tie" << "\n";
                return 0;
        }
        if (duplicates == 5)//find value of arr1[6] in arr. match to coresponding cow
        {
                fout << what(*find(arr, arr + 7, arr1[6])) << "\n";
                return 0;
        }
        if (arr1[duplicates] == arr1[duplicates+1])
        {
                fout << "Tie" << "\n";
                return 0;
        }
        fout << what(*find(arr, arr + 7, arr1[duplicates])-1) << "\n";
}

