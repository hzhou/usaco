#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int *A;

int main(int argc, char** argv)
{
    int n_max;
    int j;
    int sum;
    int count;

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
    int P[N];
    for (int  i = 0; i<N; i++) {
        P[i] = i;
    }
    std::sort(P, P+N, [&](int a, int b){
        return A[a] < A[b];
    } );
    int C[N];
    for (int  i = 0; i<N; i++) {
        C[i] = 0;
    }
    n_max = 0;
    for (int  i = 0; i<N; i++) {
        if (P[i] > i) {
            j = i;
            while (j < N) {
                C[j] += 1;
                if (j == 0) {
                    j++;
                } else {
                    j += j &- j;
                }
            }
            j = P[i];
            while (j < N) {
                C[j] +=- 1;
                if (j == 0) {
                    j++;
                } else {
                    j += j &- j;
                }
            }
        }
    }
    printf("P[%d]: ", N);
    for (int  _i = 0; _i<N; _i++) {
        printf("%d ", P[_i]);
    }
    puts("");
    printf("C[%d]: ", N);
    for (int  _i = 0; _i<N; _i++) {
        printf("%d ", C[_i]);
    }
    puts("");
    for (int  i = 0; i<N; i++) {
        sum = 0;
        j = i;
        if (j == 0) {
            sum = C[0];
        } else {
            while (j > 0) {
                sum += C[j];
                j -= j &- j;
            }
        }
        if (n_max < sum) {
            n_max = sum;
        }
    }
    count = n_max;
    if (count == 0) {
        count = 1;
    }
    std::cout<<"count="<<count<<'\n';
    FILE* Out = fopen("sort.out", "w");
    fprintf(Out, "%d\n", count);
    fclose(Out);
    return 0;
}
