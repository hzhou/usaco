#include <cstdio>
#include <cstdio>
#include <algorithm>

int C_NKs[21][100001][3];

int main(int argc, char** argv)
{
    int n;

    FILE* In = fopen("hps.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    int K;
    fscanf(In, " %d %d" ,&N,&K);
    char FJ[N+1];
    for (int  i = 0; i<N; i++) {
        fscanf(In, "%s", FJ + i);
        if (FJ[i] == 'H') {
            FJ[i] = 0;
        } else if (FJ[i] == 'P') {
            FJ[i] = 1;
        } else {
            FJ[i] = 2;
        }
    }
    fclose(In);
    for (int  i = 1; i<N+1; i++) {
        for (int  k = 0; k<K+1; k++) {
            for (int  state = 0; state<3; state++) {
                if (k == 0) {
                    C_NKs[k][i][state] = C_NKs[k][i - 1][state] + (FJ[i-1] == state ? 1: 0);
                } else {
                    n = C_NKs[k][i - 1][state];
                    if (n < C_NKs[k-1][i - 1][(state + 1) % 3]) {
                        n = C_NKs[k-1][i - 1][(state + 1) % 3];
                    }
                    if (n < C_NKs[k-1][i - 1][(state + 2) % 3]) {
                        n = C_NKs[k-1][i - 1][(state + 2) % 3];
                    }
                    C_NKs[k][i][state] = n + (FJ[i-1] == state ? 1: 0);
                }
            }
        }
    }
    n = C_NKs[K][N][0];
    if (n < C_NKs[K][N][1]) {
        n = C_NKs[K][N][1];
    }
    if (n < C_NKs[K][N][2]) {
        n = C_NKs[K][N][2];
    }
    FILE* Out = fopen("hps.out", "w");
    fprintf(Out, "%d\n", n);
    fclose(Out);
    return 0;
}
