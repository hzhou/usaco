#include <cstdio>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{
    int i;

    FILE* In = fopen("snowboots.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    int B;
    fscanf(In, " %d %d" ,&N,&B);
    int D[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d" ,&D[i]);
    }
    int s[B];
    int d[B];
    for (int  i = 0; i<B; i++) {
        fscanf(In, " %d %d" ,&s[i],&d[i]);
    }
    fclose(In);
    int Ans[B];
    for (int  j = 0; j<B; j++) {
        i = 0;
        while (1) {
            for (int  k = d[j]; k >= 1; k--) {
                if (i + k >= N - 1) {
                    Ans[j] = 1;
                    goto done_with_j;
                }
                if (D[i+k] <= s[j]) {
                    i = i + k;
                    goto done_with_this_step;
                }
            }
            failed:
            Ans[j] = 0;
            goto done_with_j;
            done_with_this_step: ;
        }
        done_with_j: ;
    }
    FILE* Out = fopen("snowboots.out", "w");
    for (int  j = 0; j<B; j++) {
        fprintf(Out, "%d\n", Ans[j]);
    }
    fclose(Out);
    return 0;
}
