#include <cstdio>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{
    FILE* In = fopen("herding.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    int A[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d" ,&A[i]);
    }
    fclose(In);
    return 0;
}
