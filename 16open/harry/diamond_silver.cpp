//Harry Zhou
//25 min
//I started with a copy of my bronze program, but algorithm ends up being quite a bit different.
//The end result is quite a bit different from the algorithm I orignally had in mind
//I took your advice about trying simple methods first. Of course, this resulted in a lot of timing out.
//My final method is actually a lot cleaner and easier to read than the brute-force method. It also took less time to write.
#include <cstdio>
#include <algorithm>
#include <limits.h>

int main() {
    FILE *fileIn = fopen("diamond.in", "r");
    FILE *fileOut = fopen("diamond.out", "w");

    int N, K;
    fscanf(fileIn, "%d %d", &N, &K);
    
    int *sizes = new int[N];
    for (int i=0; i<N; i++) {
        fscanf(fileIn, "%d", sizes+i);
    }

    std::sort(sizes, sizes+N);

    /*for (int i=0; i<N; i++) {
        printf("%d\n", sizes[i]);
    }
    printf("\n");*/

    int *endList = new int[N];

    int b = 0;
    for (int a=0; a<N; a++) {
        while (sizes[b]-sizes[a]<=K && b<N) {
            b++;
        }
        endList[a] = b;
    }

    int maxDiamonds = 2;
    for (int a=0; a<N-1; a++) {
        int b = endList[a];
        for (int c=b; c<N; c++) {
            int d = endList[c];
            int numDiamonds = (b-a) + (d-c);
            if (numDiamonds > maxDiamonds) {
                maxDiamonds = numDiamonds;
            }
        }
    }

    printf("%d\n", maxDiamonds);
    fprintf(fileOut, "%d\n", maxDiamonds);
}
