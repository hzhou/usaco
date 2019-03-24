#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
    int k;
    int M;
    int N;
    int K;
    FILE* In = fopen("cowsignal.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d %d" ,&M,&N,&K);
    char A[N][11];
    char B[N][11];
    char grid[M*N+2];
    for (int  i = 0; i<M; i++) {
        fscanf(In, "%s", grid + i * N);
    }
    grid[M*N] = '\0';
    fclose(In);
    puts(grid);
    char Grid[M*N*K*K];
    for (int  i = 0; i<M; i++) {
        for (int  j = 0; j<N; j++) {
            int k = i*N+j;
            for (int  i2 = 0; i2<K; i2++) {
                for (int  j2 = 0; j2<K; j2++) {
                    int k2 = (i*K+i2)*N*K + (j*K+j2);
                    Grid[k2] = grid[k];
                }
            }
        }
    }
    FILE* Out = fopen("cowsignal.out", "w");
    k = 0;
    for (int  i = 0; i<M*K; i++) {
        for (int  j = 0; j<N*K; j++) {
            fprintf(Out, "%c", Grid[k++]);
        }
        fprintf(Out, "\n");
    }
    fclose(Out);
    return 0;
}

