// Brian Lu
// port took around 1 hr 10 min
// should try to be less scared of this and go with C++ first i guess
// I keep running into the stupidest ways of causing segfaults
// **********

#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <limits>


int main() {
  int N, M;
  FILE *input = fopen("fenceplan.in","r");
  fscanf(input, "%d %d ", &N, &M);
  int x[N], y[N];
  for (int i = 0; i < N; i++) {
    fscanf(input, "%d %d", &x[i],&y[i]);
  }
  std::vector<std::vector<int> > graph(N);
  int a,b;
  for (int i = 0; i < M; i++) {
    fscanf(input, "%d %d", &a,&b);
    a--;b--;
    
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  fclose(input);

  std::set<int> cache;

  std::vector<int> moonets;
  std::vector<int> netminx;
  std::vector<int> netmaxx;
  std::vector<int> netminy;
  std::vector<int> netmaxy;

  int moonum = 0;
  std::vector<int> fillcow;
  std::vector<int> fillchild;
  int handcow;
  int handchild;

  for (int i = 0; i < graph.size(); i++) {
    if (!cache.count(i)) {
      moonets.push_back(1);
      netminx.push_back(x[i]);
      netmaxx.push_back(x[i]);
      netminy.push_back(y[i]);
      netmaxy.push_back(y[i]);
      cache.insert(i);
      fillcow.push_back(i);
      fillchild.push_back(0);
      while (fillcow.size()) {
        handcow = fillcow.back(); fillcow.pop_back();
        handchild = fillchild.back(); fillchild.pop_back();
        if (handchild < graph[handcow].size()) {
          fillcow.push_back(handcow);
          fillchild.push_back(handchild+1);
          if (!cache.count(graph[handcow][handchild])) {
            cache.insert(graph[handcow][handchild]);
            fillcow.push_back(graph[handcow][handchild]);
            fillchild.push_back(0);
            netminx[moonum] = std::min(netminx[moonum],x[graph[handcow][handchild]]);
            netmaxx[moonum] = std::max(netmaxx[moonum],x[graph[handcow][handchild]]);
            netminy[moonum] = std::min(netminy[moonum],y[graph[handcow][handchild]]);
            netmaxy[moonum] = std::max(netmaxy[moonum],y[graph[handcow][handchild]]);
            moonets[moonum]++;
          }
        }

      }
      moonum++;
    }
  }

  int minperimeter = std::numeric_limits<int>::max();
  int perimeter;
  for (int i = 0; i < moonets.size(); i++) {
    perimeter = 2*(netmaxx[i]-netminx[i])+2*(netmaxy[i]-netminy[i]);
    if (perimeter < minperimeter)
      minperimeter = perimeter;
  }



  FILE *output = fopen("fenceplan.out", "w");
  fprintf(output, "%d\n", minperimeter);
  fclose(output);

  return 0;
}
