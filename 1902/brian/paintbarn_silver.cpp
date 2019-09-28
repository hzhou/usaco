// Brian Lu
// 1 hr 13 min I think I now have something that should work.....
// 1 hr 47 min Did not have something that worked.
// *xt!!!!!!
// Saw rectangles and assumed it was an intersection problem but that might not be the case. Also got jammed trying to fix segfault caused by reading file.

#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

struct rectangle {
  int x1;
  int y1;
  int x2;
  int y2;
  bool exists;
};

rectangle intersect(rectangle a, rectangle b) {
  rectangle c;
  c.x1 = std::max(a.x1,b.x1);
  c.y1 = std::max(a.y1,b.y1);
  c.x2 = std::min(a.x2,b.x2);
  c.y2 = std::min(a.y2,b.y2);
  c.exists = c.x1<c.x2 && c.y1<c.y2;
  return c;
}

int areaOf(rectangle r) {
  int w = r.x2-r.x1;
  int h = r.y2-r.y1;
  return w*h;
}

int main() {
  int N, K;
  //printf("nk\n");
  FILE *input = fopen("paintbarn.in","r");
  fscanf(input, "%d %d ", &N, &K);
  std::vector<std::vector<rectangle> > rectangles(K);
  for (int i = 0; i < N; i++) {
    int tmpx1,tmpy1,tmpx2,tmpy2;
    fscanf(input, "%d%d%d%d", &tmpx1,&tmpy1,&tmpx2,&tmpy2);
    rectangle temp;
    temp.x1 = tmpx1;
    temp.y1 = tmpy1;
    temp.x2 = tmpx2;
    temp.y2 = tmpy2;
    temp.exists = true;
    rectangles[0].push_back(temp);
    //printf("read\n");
    //Just using push_back cause i have no clue how to initialize things properly.
  }
  fclose(input);

  rectangle temprect;
  int layer = 0;
  for (int i = 0; i < K-1; i++) {
    for (int j = 0; j < rectangles[layer].size(); j++) {
      for (int k = j+1; k < N; k++) {
        //if (!(layer == 0 && i == j)) {
          temprect = intersect(rectangles[layer][j],rectangles[layer][k]);
          //printf("a: (%d,%d),(%d,%d)\n",rectangles[layer][j].x1,rectangles[layer][j].y1,rectangles[layer][j].x2,rectangles[layer][j].y2);
          //printf("b: (%d,%d),(%d,%d)\n",rectangles[0][k].x1,rectangles[0][k].y1,rectangles[0][k].x2,rectangles[0][k].y2);
          //printf("c: (%d,%d),(%d,%d)%d\n",temprect.x1,temprect.y1,temprect.x2,temprect.y2,(int)temprect.exists);
          if (temprect.exists)
            rectangles[layer+1].push_back(temprect);
        //}
      }
    }
    //printf("new layer\n");
    layer++;
  }
/*
  for (int i = 0; i < rectangles.size(); i++) {
    for (int j = 0; j < rectangles[i].size(); j++) {
      printf(":%d: (%d,%d),(%d,%d)\n", i,
                               rectangles[i][j].x1,
                               rectangles[i][j].y1,
                               rectangles[i][j].x2,
                               rectangles[i][j].y2);
    }
  }*/

  int area = 0;
  for (int i = 0; i < rectangles.back().size(); i++) {
    area += areaOf(rectangles.back()[i]);
    for (int j = i+1; j < rectangles.back().size(); j++) {
      temprect = intersect(rectangles.back()[i], rectangles.back()[j]);
      if (temprect.exists)
        area -= areaOf(temprect);
    }
    //printf("%d\n", area);
  }

  FILE *output = fopen("paintbarn.out", "w");
  fprintf(output, "%d", area);
  fclose(output);

  return 0;
}
