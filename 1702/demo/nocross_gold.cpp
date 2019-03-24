#include <cstdio>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{
    int j_min;
    int j_max;
    int tn_tmp;

    FILE* In = fopen("nocross.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    int A[N];
    int B[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d" ,&A[i]);
        A[i]--;
    }
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d" ,&B[i]);
        B[i]--;
    }
    fclose(In);
    int PA[N];
    for (int  i = 0; i<N; i++) {
        PA[A[i]] = i;
    }
    int dp[N][N];
    j_min = B[0] - 4;
    if (j_min < 0) {
        j_min = 0;
    }
    j_max = B[0] + 4;
    if (j_max > N - 1) {
        j_max = N - 1;
    }
    int iA_list[10];
    int n_iA;
    n_iA = j_max - j_min + 1;
    iA_list[n_iA] = N;
    for (int  i = 0; i<n_iA; i++) {
        iA_list[i] = PA[j_min+i];
    }
    std::sort(iA_list, iA_list+n_iA, [&](int a, int b){
        return a < b;
    } );
    for (int  j = 0; j<iA_list[0]; j++) {
        dp[0][j] = 0;
    }
    for (int  j = iA_list[0]; j<N; j++) {
        dp[0][j] = 1;
    }
    for (int  i = 1; i<N; i++) {
        j_min = B[i] - 4;
        if (j_min < 0) {
            j_min = 0;
        }
        j_max = B[i] + 4;
        if (j_max > N - 1) {
            j_max = N - 1;
        }
        int iA_list[10];
        int n_iA;
        n_iA = j_max - j_min + 1;
        iA_list[n_iA] = N;
        for (int  i2 = 0; i2<n_iA; i2++) {
            iA_list[i2] = PA[j_min+i2];
        }
        std::sort(iA_list, iA_list+n_iA, [&](int a, int b){
            return a < b;
        } );
        for (int  i2 = 0; i2<iA_list[0]; i2++) {
            dp[i][i2] = dp[i-1][i2];
        }
        for (int  j = 0; j<n_iA; j++) {
            tn_tmp = 0;
            if (iA_list[j] > 0) {
                tn_tmp = dp[i-1][iA_list[j] - 1];
            }
            for (int  i2 = iA_list[j]; i2<iA_list[j+1]; i2++) {
                if (dp[i-1][i2] > tn_tmp) {
                    dp[i][i2] = dp[i-1][i2];
                } else {
                    dp[i][i2] = tn_tmp + 1;
                }
            }
        }
    }
    FILE* Out = fopen("nocross.out", "w");
    fprintf(Out, "%d\n", dp[N-1][N - 1]);
    fclose(Out);
    return 0;
}
