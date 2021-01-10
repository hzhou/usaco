#include <cstdio>
#include <cstdio>
#include <algorithm>

int N;

int main(int argc, char** argv)
{
    int i_root;


    FILE* In = fopen("factory.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d" ,&N);
    int A[N];
    int B[N];
    for (int  i = 0; i<N-1; i++) {
        fscanf(In, " %d %d" ,&A[i],&B[i]);
        A[i]--;
        B[i]--;
    }
    fclose(In);

    int P[N];
    for (int  i = 0; i<N; i++) {
        P[i] = 0;
    }

    for (int  i = 0; i<N-1; i++) {
        P[A[i]]++;
    }

    i_root = -1;
    for (int  i = 0; i<N; i++) {
        if (P[i] == 0) {
            if (i_root >= 0) {
                i_root = -1;
                break;
            } else {
                i_root = i;

            }
        }
    }

    if (i_root >= 0) {
        i_root++;
    }

    FILE* Out = fopen("factory.out", "w");
    fprintf(Out, "%d\n", i_root);
    fclose(Out);
    return 0;
}
