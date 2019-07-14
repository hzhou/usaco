#include <cstdio>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{
    FILE* In = fopen("revegetate.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    int M;
    fscanf(In, " %d %d" ,&N,&M);
    int A[M];
    int B[M];
    for (int  i = 0; i<M; i++) {
        fscanf(In, " %d %d" ,&A[i],&B[i]);
        if (A[i] > B[i]) {
            int temp;
            temp = A[i];
            A[i] = B[i];
            B[i] = temp;
        }
    }
    fclose(In);
    int F[N];
    F[0] = 1;
    for (int  i = 1; i<N; i++) {
        int P[5] = {0,0,0,0,0};
        for (int  j = 0; j<M; j++) {
            if (B[j] == i) {
                P[A[j]]++;
            }
        }
        for (int  j = 1; j<5; j++) {
            if (P[j] == 0) {
                F[i] = j;
                break;
            }
        }
    }
    FILE* Out = fopen("revegetate.out", "w");
    for (int  j = 0; j<N; j++) {
        fprintf(Out, "%d", F[j]);
    }
    puts("");
    fclose(Out);
    return 0;
}
