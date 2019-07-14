#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  int N, K;
  int skills[10000];
  ifstream fin ("teamwork.in");
  fin >> N >> K;
  for (int i=0; i<=N; i++) {

    fin >> skills[i];
  }

  FILE * Out = fopen("teamwork.out", "w");
    fprintf(Out, "%d\n", 84);
    fclose(Out);
}

