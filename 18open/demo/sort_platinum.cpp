#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int *A;
long long count = 0;

int main(int argc, char** argv)
{
    int i_max;
    int n;

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
    int P[N];
    for (int  i = 0; i<N; i++) {
        P[i] = i;
    }
    std::sort(P, P+N, [&](int a, int b){
        if (A[a] == A[b]) {
            return a < b;
        } else {
            return A[a] < A[b];
        }
    } );
    int Q[N];
    i_max = 0;
    for (int  i = 0; i<N; i++) {
        if (i_max < P[i]) {
            i_max = P[i];
        }
        Q[i] = i_max - i;
    }
    for (int  i = 0; i<N; i++) {
        n = 0;
        if (n < Q[i]) {
            n = Q[i];
        }
        if (i > 0) {
            if (n < Q[i-1]) {
                n = Q[i-1];
            }
        }
        if (n == 0 && N > 1) {
            n++;
        }
        count += n;
    }
    std::cout<<"count="<<count<<'\n';
    FILE* Out = fopen("sort.out", "w");
    fprintf(Out, "%lld\n", count);
    fclose(Out);
    return 0;
}
