#include <cstdio>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
    int A[4];
    int B[4];
    FILE* In = fopen("square.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d %d %d" ,&A[0],&A[1],&A[2],&A[3]);
    fscanf(In, " %d %d %d %d" ,&B[0],&B[1],&B[2],&B[3]);
    fclose(In);
    int C[4];
    C[0] = min(A[0], B[0]);
    C[1] = min(A[1], B[1]);
    C[2] = max(A[2], B[2]);
    C[3] = max(A[3], B[3]);
    int l;
    if (C[2] - C[0] < C[3] - C[1]) {
        l = C[3] - C[1];
    } else {
        l = C[2] - C[0];
    }
    FILE* Out = fopen("square.out", "w");
    fprintf(Out, "%d\n", l * l);
    fclose(Out);
    return 0;
}

