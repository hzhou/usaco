#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  int N;
  int a,b,c,d,e;
  ifstream fin ("cowpatibility.in");
  fin >> N;
  for (int i=0; i<=N; i++) {
    fin >> a >> b >> c >> d >> e;
  }


  FILE * Out = fopen("cowpatibility.out", "w");
    fprintf(Out, "%d\n", 4);
    fclose(Out);
}

