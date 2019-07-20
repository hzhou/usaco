#include <cstdio>
#include <cstdio>
#include <algorithm>

int find_root(int i);

int *P;

int main(int argc, char** argv)
{
    FILE* In = fopen("factory.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    int A[N];
    int B[N];
    for (int  i = 0; i<N-1; i++) {
        fscanf(In, " %d %d" ,&A[i],&B[i]);
        A[i]--;
        B[i]--;
    }
    fclose(In);
    P = new int[N];
    for (int  i = 0; i<N; i++) {
        P[i] = i;
    }
    for (int  i = 0; i<N-1; i++) {
        if (P[A[i]] == A[i]) {
            P[A[i]] = find_root(B[i]);
        } else {
            break;
        }
    }
    int i_root = -1;
    for (int  i = 0; i<N; i++) {
        if (P[i] == i) {
            if (i_root < 0) {
                i_root = i;
            } else {
                i_root = -1;
                break;
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

int find_root(int i)
{
    while (i != P[i]) {
        i = P[i];
    }
    return i;
}
