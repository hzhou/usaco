//Harry Zhou
//10 min
//Accidentally wrote "%d %d" when I should have written "%d"
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

    int maxDiamonds = 1;
    int a = 0;
    for (int b=0; b<N; b++) {
        while (sizes[b]-sizes[a]>K) {
            a++;
        }
        if (b-a+1 > maxDiamonds) {
            maxDiamonds++;
        }
    }

    printf("%d\n", maxDiamonds);
    fprintf(fileOut, "%d\n", maxDiamonds);
}
