#include <cstdio>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{
    FILE* In = fopen("shell.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    int A[N];
    int B[N];
    int G[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d %d %d" ,&A[i],&B[i],&G[i]);
        A[i]--;
        B[i]--;
        G[i]--;
    }
    fclose(In);
    int poss[3] = {0, 1, 2};
    int wins[3] = {0};
    for (int  i = 0; i<N; i++) {
        for (int  j = 0; j<3; j++) {
            if (poss[j] == A[i]) {
                poss[j] = B[i];
            } else if (poss[j] == B[i]) {
                poss[j] = A[i];
            }
            if (G[i] == poss[j]) {
                wins[j]++;
            }
        }
    }
    int max = 0;
    for (int  j = 0; j<3; j++) {
        if (max < wins[j]) {
            max = wins[j];
        }
    }
    FILE* Out = fopen("shell.out", "w");
    fprintf(Out, "%d\n", max);
    fclose(Out);
    return 0;
}
