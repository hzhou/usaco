#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{
    int i_max;
    int n_max;
    int n;

    FILE* In = fopen("herding.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int A[3];
    fscanf(In, " %d %d %d" ,&A[0],&A[1],&A[2]);
    fclose(In);
    std::sort(A, A+3, [&](int a, int b){
        return a < b;
    } );
    std::cout<<"A[0]="<<A[0]<<", "<<"A[1]="<<A[1]<<", "<<"A[2]="<<A[2]<<'\n';
    int N = 3;
    i_max = 0;
    n_max = 0;
    for (int  i = 0; i<N; i++) {
        n = N - i;
        for (int  j = i+1; j<N; j++) {
            if (A[j] - A[i] > N - 1) {
                n = j - i;
                break;
            }
        }
        if (n_max < n || (n_max == n && A[i] + N - 1 == A[i+n-1])) {
            n_max = n;
            i_max = i;
        }
    }
    int min_move;
    min_move = N - n_max;
    if (n_max == 2 && A[i_max] == A[i_max+1] - 1) {
        min_move = 2;
    }
    int max_move;
    max_move = A[N-1] - A[0] - (N - 1);
    printf("holes = %d\n", max_move);
    if (A[1] - A[0] < A[N-1] - A[N-2]) {
        max_move -= A[1] - A[0] - 1;
    } else {
        max_move -= A[N-1] - A[N-2] - 1;
    }
    FILE* Out = fopen("herding.out", "w");
    fprintf(Out, "%d\n", min_move);
    fprintf(Out, "%d\n", max_move);
    fclose(Out);
    return 0;
}
