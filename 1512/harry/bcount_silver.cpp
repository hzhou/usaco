//Harry Zhou
//15 minutes
//pretty straightforward
#include <cstdio>
#include <algorithm>

struct breedCount {
    int b1;
    int b2;
    int b3;
};

int main() {
    FILE *fileIn = fopen("bcount.in", "r");
    FILE *fileOut = fopen("bcount.out", "w");

    int N, Q;
    fscanf(fileIn, "%d %d", &N, &Q);

    breedCount *counts = new breedCount[N+1];
    breedCount gCount;
    gCount.b1 = 0;
    gCount.b2 = 0;
    gCount.b3 = 0;
    counts[0] = gCount;
    for (int i=1; i<=N; i++) {
        int breed;
        fscanf(fileIn, "%d", &breed);
        if (breed == 1) {
            gCount.b1++;
        }
        else if (breed == 2) {
            gCount.b2++;
        }
        else if (breed == 3) {
            gCount.b3++;
        }
        counts[i] = gCount;
    }

    for (int i=0; i<Q; i++) {
        int a;
        int b;
        fscanf(fileIn, "%d %d", &a, &b);
        a--;
        int b1 = counts[b].b1 - counts[a].b1;
        int b2 = counts[b].b2 - counts[a].b2;
        int b3 = counts[b].b3 - counts[a].b3;

        printf("%d %d %d\n", b1, b2, b3);
        fprintf(fileOut, "%d %d %d\n", b1, b2, b3);
    }
}
