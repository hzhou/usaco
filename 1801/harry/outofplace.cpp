//Harry Zhou
//35 min
//took 10 minutes to find a typo
#include <cstdio>
#include <algorithm>
int main() {
    FILE *fileIn = fopen("outofplace.in", "r");

    int N;
    fscanf(fileIn, "%d", &N);
    
    int *heights = new int[N];
    int *sheights = new int[N];
    for (int i = 0; i < N; i++) {
        fscanf(fileIn, "%d", heights+i);
        sheights[i] = heights[i];
        printf("%8d", heights[i]);
    }
    printf("\n");

    std::sort(sheights, sheights+N);

    for (int i = 0; i < N; i++) {
        printf("%8d", sheights[i]);
    }
    printf("\n");

    int off = 0;
    int prev = -1;
    for (int i=0; i<N; i++) {
        if (heights[i] != sheights[i] && prev!=heights[i]) {
            off++;
            prev = heights[i];
        }
    }

    printf("%d", off-1);

    FILE *fileOut = fopen("outofplace.out", "w");
    fprintf(fileOut, "%d\n", off-1);

}
