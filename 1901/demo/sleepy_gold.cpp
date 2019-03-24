#include <cstdio>
#include <cstdio>
#include <algorithm>

int bin_search(int *p_list, int t, int i1, int i2);

int main(int argc, char** argv)
{
    int k;
    int j;
    int n;

    FILE* In = fopen("sleepy.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    int p_list[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d" ,&p_list[i]);
    }
    fclose(In);
    int i_N;
    for (int  i = N-1; i >= 1; i--) {
        if (p_list[i-1] > p_list[i]) {
            i_N = i;
            break;
        }
    }
    int C[i_N];
    int P[i_N];
    for (int  i = 0; i<i_N; i++) {
        P[i] = i;
    }
    std::sort(P, P+i_N, [&](int a, int b){
        return p_list[a] < p_list[b];
    } );
    int Q[i_N];
    for (int  i = 0; i<i_N; i++) {
        Q[P[i]] = i;
    }
    int _C[N];
    for (int  i = 0; i<N; i++) {
        _C[i] = 0;
    }
    for (int  i = i_N-1; i >= 0; i--) {
        k = Q[i];
        int sum = 0;
        j = k;
        if (j == 0) {
            sum = _C[0];
        } else {
            while (j > 0) {
                sum += _C[j];
                j -= j &- j;
            }
        }
        C[i] = k - sum + (i_N - i - 1);
        j = k;
        while (j < N) {
            _C[j] += 1;
            if (j == 0) {
                j++;
            } else {
                j += j &- j;
            }
        }
    }
    int count_1[i_N];
    for (int  i = 0; i<i_N; i++) {
        n = bin_search(p_list, p_list[i], i_N, N - 1);
        C[i] += n - i_N;
    }
    FILE* Out = fopen("sleepy.out", "w");
    fprintf(Out, "%d\n", i_N);
    for (int  i = 0; i<i_N-1; i++) {
        fprintf(Out, "%d ", C[i]);
    }
    fprintf(Out, "%d\n", C[i_N-1]);
    fclose(Out);
    return 0;
}

int bin_search(int *p_list, int t, int i1, int i2)
{
    int i3;

    if (t < p_list[i1]) {
        return i1;
    }
    if (t > p_list[i2]) {
        return i2 + 1;
    }
    while (i1 <= i2) {
        i3 = (i1 + i2) / 2;
        if (t < p_list[i3]) {
            i2 = i3 - 1;
        } else {
            i1 = i3 + 1;
        }
    }
    return i1;
}
