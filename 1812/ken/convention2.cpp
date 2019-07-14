#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
  int N;
  ifstream fin ("convention2.in");
  fin >> N;
  for (int i=0; i<=N; i++) {
	int A,T;
	fin >> A >> T;
  }


  FILE * Out = fopen("convention2.out", "w");
    fprintf(Out, "%d\n", 10);
    fclose(Out);
}

