//Harry Zhou
//1hr
//Well I tried this thing that acts stepwise based on the largest quandrant but it was too much work and so I gave up and did it the straightforward way.
#include <cstdio>
#include <algorithm>
#include <limits.h>

int N, B;
int *xlist;
int *ylist;
int *sxlist;
int *sylist;

void partition(int A, int B, int p[4]) {
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    int a = sxlist[A]-1;
    int b = sylist[B]-1;
    for (int i=0; i<N; i++) {
        if (xlist[i] > a) {
            if (ylist[i] > b) {
                p[0]++;
            }
            else {
                p[3]++;
            }
        }
        else {
            if (ylist[i] > b) {
                p[1]++;
            }
            else {
                p[2]++;
            }
        }
    }
    //printf("%d %d %d %d\n", p[0], p[1], p[2], p[3]);
}

int main() {
    FILE *fileIn = fopen("balancing.in", "r");
    FILE *fileOut = fopen("balancing.out", "w");

    fscanf(fileIn, "%d %d", &N, &B);
    xlist = new int[N];
    ylist = new int[N];
    sxlist = new int[N];
    sylist = new int[N];
    
    for (int i=0; i<N; i++) {
        fscanf(fileIn, "%d %d", xlist+i, ylist+i);
        sxlist[i] = xlist[i];
        sylist[i] = ylist[i];
    }
    std::sort(sxlist, sxlist+N);
    std::sort(sylist, sylist+N);

    /*int a = N/2;
    int b = N/2;
    int p[4];
    partition(a, b, p);
    
    int minM = 0;
    int pIndex = 0;
    for (int i=0; i<4; i++) {
        if (p[i] > minM) {
            minM = p[i];
            pIndex = i;
        }
    }
    
    int xDir;
    int yDir;
    if (pIndex == 0 || pIndex == 3) {
        xDir = 1;
    }
    else {
        xDir = -1;
    }
    if (pIndex == 0 || pIndex == 1) {
        yDir = 1;
    }
    else {
        yDir = -1;
    }

    for (a = N/2; a<N && a>=0; a += xDir) {
        for (b = N/2; b<N && b>=0; b += yDir) {
            partition(a, b, p);
            int M = 0;
            for (int i=0; i<4; i++) {
                if (p[i] > M) {
                    M = p[i];
                }
            }
            printf("%d\n", M);
            if (M < minM) {
                minM = M;
            }
        }
    }*/
    
    int p[4];
    int minM = INT_MAX;
    int lasta = -1;
    int lastb = -1;
    for (int a=0; a<N; a++) {
        if (a == lasta) {
            continue;
        }

        for (int b=0; b<N; b++) {
            if (b == lastb) {
                continue;
            }

            partition(a, b, p);
            int M = p[0];
            for (int i=1; i<4; i++) {
                if (p[i] > M) {
                    M = p[i];
                }
            }
            if (M < minM) {
                minM = M;
            }

            lastb = b;
        }

        lasta = a;
    }

    printf("%d\n", minM);
    fprintf(fileOut, "%d\n", minM);
}
