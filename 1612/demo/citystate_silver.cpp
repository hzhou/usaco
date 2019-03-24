#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
    int n;
    int n_1;
    int n_2;
    int N;
    FILE* In = fopen("citystate.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d" ,&N);
    char A[N][11];
    char B[N][3];
    for (int  i = 0; i<N; i++) {
        fscanf(In, "%s %s", A[i], B[i]);
    }
    fclose(In);
    map<int, int> M;
    for (int  i = 0; i<N; i++) {
        if (!(A[i][0] == B[i][0] && A[i][1] == B[i][1])) {
            n = (A[i][0] << 24) + (A[i][1] << 16) + (B[i][0] << 8) + (B[i][1]);
            M[n] += 1;
        }
    }
    int total_count = 0;
    for(auto it : M){
        n_1 = it.first;
        n_2 = (n_1 >> 16) + ((n_1 & 0xffff) << 16);
        total_count += M[n_1] * M[n_2];
    }
    total_count /= 2;
    FILE* Out = fopen("citystate.out", "w");
    fprintf(Out, "%d\n", total_count);
    fclose(Out);
    return 0;
}

