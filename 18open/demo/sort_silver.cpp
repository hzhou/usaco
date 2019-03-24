#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int *A;

int main(int argc, char** argv)
{
    int n_max;
    bool b_sorted;

    FILE* In = fopen("sort.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    A = new int[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d" ,&A[i]);
    }
    fclose(In);
    std::cout<<"N="<<N<<'\n';
    n_max = 0;
    while (1) {
        n_max++;
        for (int  i = 0; i <= N-2; i++) {
            if (A[i+1] < A[i]) {
                int temp;
                temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
            }
        }
        for (int  i = N-2; i >= 0; i--) {
            if (A[i+1] < A[i]) {
                int temp;
                temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
            }
        }
        b_sorted = 1;
        for (int  i = 0; i <= N-2; i++) {
            if (A[i+1] < A[i]) {
                b_sorted = 0;
            }
        }
        if (b_sorted) {
            break;
        }
    }
    std::cout<<"n_max="<<n_max<<'\n';
    FILE* Out = fopen("sort.out", "w");
    fprintf(Out, "%d\n", n_max);
    fclose(Out);
    return 0;
}
