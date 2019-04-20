#include <cstdio>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{
    FILE* In = fopen("snakes.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    int K;
    fscanf(In, " %d %d" ,&N,&K);
    int A[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d" ,&A[i]);
    }
    fclose(In);
    int max_matrix[N][N];
    int sum_matrix[N][N];
    for (int  i = 0; i<N; i++) {
        int sum = 0;
        int max = A[i];
        for (int  j = i; j<N; j++) {
            if (max < A[j]) {
                max = A[j];
            }
            sum += A[j];
            max_matrix[i][j] = max;
            sum_matrix[i][j] = sum;
        }
    }
    int DP[K+1][N];
    for (int  i = 0; i<N; i++) {
        DP[0][i] = max_matrix[0][i] * (i + 1) - sum_matrix[0][i];
    }
    for (int  k = 1; k<K+1; k++) {
        for (int  i = 0; i<N; i++) {
            DP[k][i] = DP[k-1][i];
            for (int  j = 0; j<i; j++) {
                int t = max_matrix[i-j][i]*(j+1) - sum_matrix[i-j][i];
                if (DP[k][i] > DP[k-1][i - j - 1] + t) {
                    DP[k][i] = DP[k-1][i - j - 1] + t;
                }
            }
        }
    }
    printf("%d\n", DP[K][N - 1]);
    FILE* Out = fopen("snakes.out", "w");
    fprintf(Out, "%d\n", DP[K][N - 1]);
    fclose(Out);
    return 0;
}
