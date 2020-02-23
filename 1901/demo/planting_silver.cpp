#include <cstdio>
#include <cstdio>
#include <algorithm>

int N;

int main(int argc, char** argv)
{

    FILE* In = fopen("planting.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d" ,&N);
    int A[N-1];
    int B[N-1];
    for (int  i = 0; i<N-1; i++) {
        fscanf(In, " %d %d" ,&A[i],&B[i]);
        A[i]--;
        B[i]--;
    }
    fclose(In);

    int count_list[N];
    for (int  i = 0; i<N; i++) {
        count_list[i] = 0;
    }

    for (int  i = 0; i<N-1; i++) {
        count_list[A[i]]++;
        count_list[B[i]]++;
    }

    int count_max = count_list[0]+1;
    for (int  i = 1; i<N; i++) {
        if (count_max < count_list[i] + 1) {
            count_max = count_list[i] + 1;
        }
    }

    FILE* Out = fopen("planting.out", "w");
    fprintf(Out, "%d\n", count_max);
    fclose(Out);
    return 0;
}
