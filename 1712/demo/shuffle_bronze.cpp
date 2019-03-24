#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int main(int argc, char** argv){
    int N;
    FILE* In = fopen("shuffle.in", "r");
    fscanf(In, "%d", &N);
    int P[N];
    for(int  i=0; i<N; i++){
        fscanf(In, "%d", &P[i]);
        P[i]--;
    }
    int id_list[N];
    for(int  i=0; i<N; i++){
        fscanf(In, "%d", &id_list[i]);
    }
    fclose(In);

    int A[N], B[N];
    for(int  i=0; i<N; i++){
        A[i] = i;
    }
    for(int  j=0; j<3; j++){
        for(int  i=0; i<N; i++){
            B[i] = A[P[i]];
        }
        for(int  i=0; i<N; i++){
            A[i] = B[i];
        }
    }

    FILE* Out = fopen("shuffle.out", "w");
    for(int  i=0; i<N; i++){
        fprintf(Out, "%d\n", id_list[A[i]]);
    }
    fclose(Out);
    return 0;
}

