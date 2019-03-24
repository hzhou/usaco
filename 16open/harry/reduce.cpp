//Harry Zhou
//30 min
//Since the program was long, there ended up being a lot of assorted compile time errors that are straightforward to solve because the compiler tells you exactly what's wrong.
//The one error that doesn't fall into that category is the one where I forgot to initialize the permutation arrays (ilistx[i] = i).
#include <cstdio>
#include <algorithm>
#include <limits.h>

struct pos {
    int x;
    int y;
};

int N;
pos *plist;

int rempt(int pt);

int main() {
    FILE *fileIn = fopen("reduce.in", "r");
    FILE *fileOut = fopen("reduce.out", "w");

    fscanf(fileIn, "%d", &N);

    plist = new pos[N];

    for (int i=0; i<N; i++) {
        fscanf(fileIn, "%d %d", &plist[i].x, &plist[i].y);
    }

    int *ilistx = new int[N];
    int *ilisty = new int[N];
    for (int i=0; i<N; i++) {
        ilistx[i] = i;
        ilisty[i] = i;
    }
    std::sort(ilistx, ilistx+N, [](int a, int b){return plist[a].x<plist[b].x;});
    std::sort(ilisty, ilisty+N, [](int a, int b){return plist[a].y<plist[b].y;});
    
    int area1 = rempt(ilistx[0]);
    int area2 = rempt(ilistx[N-1]);
    int area3 = rempt(ilisty[0]);
    int area4 = rempt(ilisty[N-1]);

    int minArea = std::min(std::min(area1, area2), std::min(area3, area4));

    printf("%d\n", minArea);
    fprintf(fileOut, "%d\n", minArea);
}

int rempt(int pt) {
    int minX = INT_MAX;
    int maxX = INT_MIN;
    int minY = INT_MAX;
    int maxY = INT_MIN;
    for (int i=0; i<N; i++) {
        if (i == pt) {
            continue;
        }
        int x = plist[i].x;
        int y = plist[i].y;
        if (x < minX) {
            minX = x;
        }
        if (x > maxX) {
            maxX = x;
        }
        if (y < minY) {
            minY = y;
        }
        if (y > maxY) {
            maxY = y;
        }
    }
    return (maxX-minX) * (maxY-minY);
}
