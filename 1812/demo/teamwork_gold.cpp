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
    int *maxes = new int[N*K];
    for (int  i = 0; i<N; i++) {
        maxes[(i)*K+0] = Skills[i];
        for (int  k = 1; k<K; k++) {
            if (i >= k) {
                maxes[(i)*K+k] = std::max(maxes[(i-1)*K+k-1], Skills[i]);
            }
        }
    }
    for (int  i = 1; i<N; i++) {
        sum[i] = 0;
        for (int  k = 0; k<K; k++) {
            if (i < k) {
                break;
            }
            int t = maxes[(i)*K+k] * (k+1);
            if (i > k) {
                t += sum[i-k-1];
            }
            if (sum[i] < t) {
                sum[i] = t;
            }
        }
    }
    FILE* Out = fopen("teamwork.out", "w");
    fprintf(Out, "%d\n", sum[N-1]);
    fclose(Out);
    return 0;
}
