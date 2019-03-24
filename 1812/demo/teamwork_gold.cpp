#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{
    FILE* In = fopen("teamwork.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    int K;
    fscanf(In, " %d %d" ,&N,&K);
    std::cout<<"N="<<N<<", "<<"K="<<K<<'\n';
    int Skills[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d" ,&Skills[i]);
    }
    fclose(In);
    int sum[N];
    sum[0] = Skills[0];
    int maxes[K+1];
    maxes[1] = Skills[0];
    for (int  i = 1; i<N; i++) {
        for (int  j = K; j >= 1; j--) {
            maxes[j] = maxes[j-1];
        }
        maxes[1] = Skills[i];
        for (int  j = 2; j<K+1; j++) {
            if (maxes[j] < Skills[i]) {
                maxes[j] = Skills[i];
            }
        }
        int max = 0;
        for (int  j = 1; j<K+1; j++) {
            int t;
            if (i - j <- 1) {
                break;
            } else if (i - j == -1) {
                t = maxes[j] * j;
            } else {
                t = sum[i-j] + maxes[j] * j;
            }
            if (max < t) {
                max = t;
            }
        }
        sum[i] = max;
    }
    FILE* Out = fopen("teamwork.out", "w");
    fprintf(Out, "%d\n", sum[N-1]);
    fclose(Out);
    return 0;
}
