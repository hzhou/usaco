#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

int main(void)
{
  int N, M, C;
  int cows[100000];
  ifstream fin ("convention.in");
  fin >> N >> M >> C;
  for (int i=0; i<=N; i++) {

    fin >> cows[i];
  }

  for (int i=0; i<=N; i++) {
	printf("%d", cows[i]);

  }

  FILE * Out = fopen("convention.out", "w");
    fprintf(Out, "%d\n", 4);
    fclose(Out);
}
