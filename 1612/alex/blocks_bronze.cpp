//ALEX YANG
//Comments: I don't know how to use a map. I don't know any way to convert the alphabet to numbers. If I could, my algorithm would beas follows: Seperate the pairs of words into two arrays, so the coresponding word of word1[1] would be word2[1]. Make an array of 26 integers, coresponding to a...z. Test each combo of words. If the number of any letter is larger than the value for that letter in the26 integers array, replace it.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main ()
{
        ifstream fin ("blocks.in");
        ofstream fout ("blocks.out");


        int n;
        string word1[n];
        string word2[n];
        fin >> n;
        fout << n;

        for (int i = 0; i < n; i++)
        {
                fin >> word1[i] >> word2[i];
        }
}