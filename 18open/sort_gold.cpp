#include <iostream>
#include <algorithm>

int main(int argc, char** argv)
{
    int n_max;
    int count;

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
    for (int  i = 0; i<N; i++) {
        if (P[i] > i) {
            for (int  j = i; j<P[i]; j++) {
                C[j]++;
            }
        }
    }
    n_max = 0;
    for (int  i = 0; i<N-1; i++) {
        if (n_max < C[i]) {
            n_max = C[i];
        }
    }
    count = n_max;
    if (count == 0) {
        count = 1;
    }
    std::cout<<"count="<<count<<'\n';
    return 0;
}
