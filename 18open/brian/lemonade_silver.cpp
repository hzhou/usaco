// Brian Lu
//1. Sort
//16 mins
//
//***x**x***


#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <limits>

bool compare(int a, int b) { 
  return a > b;
} 
int main() {

  int N;
  FILE *input = fopen("lemonade.in","r");
  fscanf(input, "%d", &N);
  int cows[N];
  for (int i = 0; i < N; i++) {
    fscanf(input, "%d", &cows[i]);
  }
  fclose(input);

  std::sort(cows, cows+(sizeof(cows)/sizeof(cows[0])), compare);

  int line = 0;

  for (int i = 0; i < N; i++) {
    if (cows[i] >= line) {
      line++;
    } else {
      break;
    }
  }

  FILE *output = fopen("lemonade.out", "w");
  fprintf(output, "%d\n", line);
  fclose(output);
  
  return 0;
}
