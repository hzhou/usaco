// Brian Lu
//1. Paired up
//35 min spent
//**********

#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <limits>
struct cowgroup {
  int times;
  int milk;
};

bool groupcomp(cowgroup a, cowgroup b) {
  return a.milk < b.milk;
}

void visualize(std::vector<cowgroup> l, int fi, int bi, int max) {
  printf("min: %-12d--------------\n",max);
  printf("|%3s|%12s|%12s|\n", "idx", "times", "milk");
  for (int i = 0; i < l.size(); i++) {
    printf("|%3d|%12d|%12d|", i, l[i].times, l[i].milk);
    if (i==fi)
      printf("<fi");
    if (i==bi)
      printf("<bi");
    printf("\n");
  }
  printf("-------------------------------\n");
}

int main() {
  int N;
  FILE *input = fopen("pairup.in","r");
  fscanf(input, "%d", &N);
  std::vector<cowgroup> milks;
  for (int i = 0; i < N; i++) {
    milks.push_back(cowgroup());
    fscanf(input, "%d %d", &milks[i].times, &milks[i].milk);
  }
  fclose(input);

  std::sort(milks.begin(), milks.end(), groupcomp);
  
  int max = -1;

  int fronti = 0;
  int backi = N-1;
  while (fronti<=backi) {
    //visualize(milks, fronti, backi, max);
    if (milks[fronti].milk + milks[backi].milk > max)
      max = milks[fronti].milk + milks[backi].milk;
    if (milks[fronti].times > milks[backi].times) {
      milks[fronti].times-=milks[backi].times;
      milks[backi].times=0;
      backi--;
    } else if (milks[fronti].times < milks[backi].times) {
      milks[backi].times-=milks[fronti].times;
      milks[fronti].times=0;
      fronti++;
    } else if (milks[fronti].times == milks[backi].times) {
      milks[backi].times=0;
      milks[fronti].times=0;
      fronti++;
      backi--;
    }
  }


  FILE *output = fopen("pairup.out", "w");
  fprintf(output, "%d\n", max);
  fclose(output);
  
  return 0;
}
