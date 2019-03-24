#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{
    FILE* In = fopen("spainting.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    int M;
    int K;
    fscanf(In, " %d %d %d" ,&N,&M,&K);
    fclose(In);
    long long S[1000001];
    long long dp = 1;
    S[0] = 1;
    for (int  i = 1; i<K; i++) {
        dp = (dp * M + 1000000007) % 1000000007;
        S[i] = (S[i-1] + dp + 1000000007) % 1000000007;
    }
    for (int  i = K; i <= N; i++) {
        S[i] = (S[i-1] * M - S[i-K] * (M - 1) + 1000000007) % 1000000007;
    }
    dp = S[N] - S[N-1];
    long long n = 1;
    for (int  i = 0; i<N; i++) {
        n = (n * M + 1000000007) % 1000000007;
    }
    n = (n - dp + 1000000007) % 1000000007;
    std::cout<<"n="<<n<<'\n';
    FILE* Out = fopen("spainting.out", "w");
    fprintf(Out, "%d\n", n);
    fclose(Out);
    return 0;
}
