//Harry Zhou
//10 mins
//Just made some quick changes to my bronze level code
#include <cstdio>
#include <algorithm>
#include <limits.h>

struct pos {
    int x;
    int y;
};

int N;
pos *plist;

int rempts(int pt1, int pt2, int pt3);

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

    int *outsidePts = new int[12];
    outsidePts[0] = ilistx[0];
    outsidePts[1] = ilistx[1];
    outsidePts[2] = ilistx[2];
    outsidePts[3] = ilistx[N-1];
    outsidePts[4] = ilistx[N-2];
    outsidePts[5] = ilistx[N-3];
    outsidePts[6] = ilisty[0];
    outsidePts[7] = ilisty[1];
    outsidePts[8] = ilisty[2];
    outsidePts[9] = ilisty[N-1];
    outsidePts[10] = ilisty[N-2];
    outsidePts[11] = ilisty[N-3];
    
    int minArea = INT_MAX;
    for (int i1=0; i1<10; i1++) {
        for (int i2=i1; i2<11; i2++) {
            for (int i3=i1; i3<12; i3++) {
                int area = rempts(outsidePts[i1], outsidePts[i2], outsidePts[i3]);
                if (area < minArea) {
                    minArea = area;
                }
            }
        }
    }

    printf("%d\n", minArea);
    fprintf(fileOut, "%d\n", minArea);
}

int rempts(int pt1, int pt2, int pt3) {
    int minX = INT_MAX;
    int maxX = INT_MIN;
    int minY = INT_MAX;
    int maxY = INT_MIN;
    for (int i=0; i<N; i++) {
        if (i == pt1 || i==pt2 || i==pt3) {
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
