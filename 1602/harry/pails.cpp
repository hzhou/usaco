//Harry Zhou
//10 mins
//I thought of an O(1) solution with some weird modulus stuff but decided it would be too difficult to implement
#include <cstdio>
#include <algorithm>
#include <limits.h>

int main() {
    FILE *fileIn = fopen("pails.in", "r");
    FILE *fileOut = fopen("pails.out", "w");

    int X, Y, M;
    fscanf(fileIn, "%d %d %d", &X, &Y, &M);

    int nx = M/X;
    int ny = 0;

    int maxTotal = 0;
    while (nx>=0) {
        int total = nx*X + ny*Y;
        if (total > maxTotal) {
            maxTotal = total;
        }

        nx -= 1;
        total = nx*X + ny*Y;
        if (total<=M-Y) {
            ny++;
        }
    }

    fprintf(fileOut, "%d\n", maxTotal);
    printf("%d\n", maxTotal);
}
