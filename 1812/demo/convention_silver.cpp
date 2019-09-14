#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{
    int N;
    int M;
    int C;
    int j;
    int k;

    FILE* In = fopen("convention.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d %d" ,&N,&M,&C);
    std::cout<<"N="<<N<<", "<<"M="<<M<<", "<<"C="<<C<<'\n';
    int A[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d" ,&A[i]);
    }
    fclose(In);
    std::sort(A, A+N);
    std::cout<<"A[0]="<<A[0]<<", "<<"A[N-1]="<<A[N-1]<<'\n';
    int w1 = 0;
    int w2 = A[N-1];
    while (w1 <= w2) {
        int w = (w1+w2)/2;
        j = 0;
        for (int  i = 0; i<M; i++) {
            k = j;
            while (k < N && A[k] - A[j] <= w && k - j + 1 <= C) {
                k++;
            }
            j = k;
        }
        if (j >= N) {
            w2 = w - 1;
        } else {
            w1 = w + 1;
        }
    }
    std::cout<<"w1="<<w1<<'\n';
    FILE* Out = fopen("convention.out", "w");
    fprintf(Out, "%d\n", w1);
    fclose(Out);
    return 0;
}
