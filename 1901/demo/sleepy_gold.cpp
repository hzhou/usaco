#include <cstdio>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{
    int j;

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
        p_list[i]--;
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
    int _C[N];
    for (int  i = 0; i<N; i++) {
        _C[i] = 0;
    }
    for (int  i = i_N; i<N; i++) {
        j = p_list[i];
        while (j < N) {
            _C[j] += 1;
            if (j == 0) {
                j++;
            } else {
                j += j &- j;
            }
        }
    }
    for (int  i = 0; i<i_N; i++) {
        int sum = 0;
        j = p_list[i];
        if (j == 0) {
            sum = _C[0];
        } else {
            while (j > 0) {
                sum += _C[j];
                j -= j &- j;
            }
        }
        C[i] = i_N - 1 - i + sum;
        j = p_list[i];
        while (j < N) {
            _C[j] += 1;
            if (j == 0) {
                j++;
            } else {
                j += j &- j;
            }
        }
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
