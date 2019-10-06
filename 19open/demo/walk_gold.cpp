#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{
    int i_min;

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
    int *cache = new int[N];
    int *D = new int[N];
    for (int  i = 0; i<N; i++) {
        cache[i] = 0;
        D[i] = 2019201997;
    }
    for (int  i = 0; i<N; i++) {
        i_min = 0;
        for (int  j = 0; j<N; j++) {
            if (!cache[j] && D[i_min] > D[j]) {
                i_min = j;
            }
        }
        cache[i_min] = 1;
        for (int  j = 0; j<N; j++) {
            if (!cache[j]) {
                int tn_dist;
                if (i_min < j) {
                    tn_dist = (int) (((long long) (i_min + 1) * 2019201913 + (long long) (j + 1) * 2019201949) % 2019201997);
                } else {
                    tn_dist = (int) (((long long) (j + 1) * 2019201913 + (long long) (i_min + 1) * 2019201949) % 2019201997);
                }
                if (D[j] > tn_dist) {
                    D[j] = tn_dist;
                }
            }
        }
    }
    std::sort(D, D+N);
    int dist = D[N-K];
    FILE* Out = fopen("walk.out", "w");
    fprintf(Out, "%d\n", dist);
    fclose(Out);
    return 0;
}
