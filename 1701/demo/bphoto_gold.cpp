#include <cstdio>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{
    int count;
    int n;
    int j;
    int n_L;
    int n_R;

    FILE* In = fopen("bphoto.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    int h_list[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d" ,&h_list[i]);
    }
    fclose(In);
    int P[N];
    for (int  i = 0; i<N; i++) {
        P[i] = i;
    }
    std::sort(P, P+N, [&](int a, int b){
        return h_list[a] < h_list[b];
    } );
    count = 0;
    int C[N];
    for (int  i = 0; i<N; i++) {
        C[i] = 0;
    }
    for (int  i = 0; i<N; i++) {
        n = N - i - 1;
        int sum = 0;
        j = P[i];
        if (j == 0) {
            sum = C[0];
        } else {
            while (j > 0) {
                sum += C[j];
                j -= j &- j;
            }
        }
        n_L = P[i] - sum;
        n_R = n - n_L;
        j = P[i];
        while (j < N) {
            C[j] += 1;
            if (j == 0) {
                j++;
            } else {
                j += j &- j;
            }
        }
        if (n_L > n_R * 2 || n_R > n_L * 2) {
            count++;
        }
    }
    FILE* Out = fopen("bphoto.out", "w");
    fprintf(Out, "%d\n", count);
    fclose(Out);
    return 0;
}
