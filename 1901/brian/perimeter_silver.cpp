// Brian Lu
//finished python prototype in ~30 mins
//~30 mins started porting from python (sorry)
//~1 hr 15 mins hit a snag (*XX!!!!!!!t) (but the python script spits out the right answer?!?)
//~1 hr 30 mins jumping ship, going to bed
//Probably should learn how to write C++ better and this wouldn'tve happened

#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

std::vector<int> areas;
std::vector<int> perimeters;
std::vector<int> grid;
std::set<int> used;
int N;

bool connected(int n) {
  return 0 <= n || n < N;
}

void fill(int i, int blobsIndex) {
  areas[blobsIndex]++;
  used.insert(i);
  int x = i % N;
  int y = i / N;
  int openSides = 4;
  if (connected(x+1) && grid[i+1]) {
    openSides--;
    if (!used.count(i+1))
      fill(i+1, blobsIndex);
  }
  if (connected(x-1) && grid[i-1]) {
    openSides--;
    if (!used.count(i-1))
      fill(i-1, blobsIndex);
  }
  if (connected(y+1) && grid[i+N]) {
    openSides--;
    if (!used.count(i+N))
      fill(i+N, blobsIndex);
  }
  if (connected(y-1) && grid[i-N]) {
    openSides--;
    if (!used.count(i-N))
      fill(i-N, blobsIndex);
  }
  perimeters[blobsIndex]+=openSides;
}

int main() {
  FILE *input = fopen("perimeter.in","r");
  fscanf(input, "%d", &N);

  char temp;
  for (int i = 0; i < N*N; i++) {
    fscanf(input, " %c", &temp);
    if (temp == '#') {
      grid.push_back(1);
    } else {
      grid.push_back(0);
    }
    //Just using push_back cause i have no clue how to initialize things properly.
  }
  fclose(input);

  for (int c : grid) {
    printf("%d",c);
  }

  //-----
  int blobCount = 0;
  int largest = -1;
  for (int i = 0; i < grid.size(); i++) {
    if (grid[i] && !used.count(i)) {
      areas.push_back(0);
      perimeters.push_back(0);
      fill(i,blobCount);
      if (areas[blobCount] > (largest == -1 ? -1 : areas[largest])) //suspect something might be wrong here
        largest = blobCount;
      blobCount++;
    }
  }
  //-----
  FILE *output = fopen("perimeter.out", "w");
  fprintf(output, "%d %d", areas[largest], perimeters[largest]);


  return 0;
}
