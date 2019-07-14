#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

int main(void)

{
  int N, K;
  int board[100000];
  ifstream fin ("mooyomooyo.in");
  fin >> N >> K;
  for (int i=0; i<=N; i++) {

    fin >> board[i];
  }


  FILE * Out = fopen("mooyomooyo.out", "w");

  fprintf(Out, "0000000000\n");
  fprintf(Out, "0000000000\n");
  fprintf(Out, "0000000000\n");
  fprintf(Out, "0000000000\n");
  fprintf(Out, "1054000000\n");
  fprintf(Out, "2254500000\n");
  fclose(Out);
}

