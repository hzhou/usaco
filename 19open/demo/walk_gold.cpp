#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{
    int tn_a;
    int n_merge;
    int i;
    int j;

    FILE* In = fopen("walk.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    int K;
    fscanf(In, " %d %d" ,&N,&K);
    fclose(In);
    std::cout<<"N="<<N<<", "<<"K="<<K<<'\n';
    int *pn_dist = new int[N*N];
    for (int  i = 0; i<N; i++) {
        for (int  j = 0; j<i; j++) {
            tn_a = (int) (((long long) (j + 1) * 2019201913 + (long long) (i + 1) * 2019201949) % 2019201997);
            pn_dist[i*N+j] = tn_a;
            pn_dist[j*N+i] = tn_a;
        }
    }
    for (int  i = 0; i<N; i++) {
        pn_dist[i*N+i] = -1;
    }
    n_merge = 0;
    i = N - 1;
    j = i - 1;
    while (1) {
        if (pn_dist[j*N+i] < 0) {
        } else if (n_merge == N - K) {
            break;
        } else {
            n_merge++;
            pn_dist[j*N+i] = -1;
            for (int  k = 0; k<N; k++) {
                tn_a = pn_dist[i*N+k];
                if (tn_a > pn_dist[j*N+k]) {
                    tn_a = pn_dist[j*N+k];
                }
                pn_dist[i*N+k] = tn_a;
                pn_dist[j*N+k] = tn_a;
                pn_dist[k*N+i] = tn_a;
                pn_dist[k*N+j] = tn_a;
            }
        }
        if (i > 2 && j + 1 < i - 2) {
            i -= 2;
            j++;
        } else if (i > 1 && j < i - 1) {
            i -= 1;
        } else if (j > 0) {
            j -= 1;
        } else {
            break;
        }
    }
    printf("%d\n", pn_dist[j*N+i]);
    FILE* Out = fopen("walk.out", "w");
    fprintf(Out, "%d\n", pn_dist[j*N+i]);
    fclose(Out);
    return 0;
}
