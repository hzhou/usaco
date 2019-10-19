// Brian Lu
//1. Lifeguards
//10 mins of just drawing pictures
//after about an hour finished writing
//****tt****


#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <limits>

struct instruction {
  int time;
  bool start;
  int guardid;
};
bool compareinsts(instruction a, instruction b) { 
  return a.time < b.time;
} 
int main() {

  int N;
  FILE *input = fopen("lifeguards.in","r");
  fscanf(input, "%d", &N);
  instruction inst[N*2];
  for (int i = 0; i < N; i++) {
    inst[i*2].guardid=i;
    inst[i*2].start=true;
    inst[i*2+1].guardid=i;
    inst[i*2+1].start=false;
    fscanf(input, "%d %d", &inst[i*2].time, &inst[i*2+1].time);
  }
  fclose(input);

  std::sort(inst, inst+(sizeof(inst)/sizeof(inst[0])), compareinsts);
  /*
  for (int i = 0; i < 2*N; i++) {
    printf("%s%d, %d\n", inst[i].start?"+":"-",inst[i].time,inst[i].guardid);
  }
  */
  std::set<int> guards;
  int totalCoverage = 0;
  int currentTime;
  int aloneTime[N];
  for (int i = 0; i < N; i++) {
    aloneTime[i] = 0;
  }

  for (int i = 0; i < 2*N; i++) {
    currentTime = inst[i].time;
    if (inst[i].start) {
      guards.insert(inst[i].guardid);
    } else {
      guards.erase(inst[i].guardid);
    }
    int nextDiff = inst[i+1].time - currentTime;
    if (guards.size() == 1) {
      aloneTime[*guards.begin()] += nextDiff;
      //printf("%d<-%d : %d\n",inst[i].guardid,aloneTime[*guards.begin()], nextDiff);
    } else {}
    if (guards.size()) {
      totalCoverage += nextDiff;
    } else {}
    for (int j : guards) {
      //printf("%d-",j);
    }
    //printf("#%d\n", guards.size());
  }
  /*
  printf("RESULTS: \n");
  for (int i = 0; i < N; i++) {
    printf("%d\n", aloneTime[i]);
  }
  printf("t%d\n", totalCoverage);
  */
  int smallestGap = std::numeric_limits<int>::max();
  for (int i = 0; i < N; i++) {
    if (aloneTime[i] < smallestGap) {
      smallestGap = aloneTime[i];
    } else {}
  }

  FILE *output = fopen("lifeguards.out", "w");
  fprintf(output, "%d", totalCoverage - smallestGap);
  fclose(output);
  
  return 0;
}
