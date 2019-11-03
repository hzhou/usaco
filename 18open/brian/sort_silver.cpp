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

struct item {
  int value;
  int origindex;
};
bool compareinsts(item a, item b) { 
  return a.value < b.value;
} 
int main() {

  int N;
  FILE *input = fopen("sort.in","r");
  fscanf(input, "%d", &N);
  item sortarr[N];
  for (int i = 0; i < N; i++) {
    sortarr[i].origindex = i;
    fscanf(input, "%d", &sortarr[i].value);
  }
  fclose(input);

  std::sort(sortarr, sortarr+(sizeof(sortarr)/sizeof(sortarr[0])), compareinsts);

  int max = -1;
  int temp = 0;
  for (int i = 0; i < N; i++) {
    temp = abs(i-sortarr[i].origindex)+1;
    if (temp > max) {
      max = temp;
    }
  }

  FILE *output = fopen("sort.out", "w");
  fprintf(output, "%d", max);
  fclose(output);
  
  return 0;
}
