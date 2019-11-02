//Shouldn't this be a bronze problem???
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;


int main(void)
{
  ifstream fin("lemonade.in");
  ofstream fout("lemonade.out");
  int N;
  fin >> N;
  int W[N];
  for (int i=0; i<N; i++)
  {
    fin >> W[i];
  }
  sort(W,W+N);
  
  int cowsinline = 0;
  for(int i = N-1; i > -1; i--)
  {
    if(W[i] >= cowsinline)
    {
      cowsinline++;
    }
  }
  fout << cowsinline << "\n";
}
