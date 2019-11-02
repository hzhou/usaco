// Brian Lu
//3. MultiMoo
//30 min spent
//NOT DONE
/*
The plan is to basically find blobs with floodfill, in the process building another graph. This new graph connects adjacent blobs. Combinations of adjacent blobs are tested, and a second floodfill is done.
*/



#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <limits>
struct blob {
  int size;
};
int main() {

  int N;
  FILE *input = fopen("lemonade.in","r");
  fscanf(input, "%d", &N);
  int grid[N*N];
  for (int i = 0; i < N*N; i++) {
    fscanf(input, "%d", &grid[i]);
  }
  fclose(input);

  std::set<int> cache;
  std::vector<int> stack;
  int direction = 0;
  int target = -1;

  for (int i = 0; i < N*N; i++) {
    if (cache.count(i)) {
      cache.insert(i);
      stack.push_back(i);
      target = grid[i];
      direction = 0;
      while (cache.size() != 0) {
        if (stack[i] == target) {

        }
      }
    }
  }

  FILE *output = fopen("lemonade.out", "w");
  fprintf(output, "%d", 1);
  fclose(output);
  
  return 0;
}
