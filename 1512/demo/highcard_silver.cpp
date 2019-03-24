#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int N;

int main(int argc, char** argv){
    int j;
    int i_a;
    FILE* In = fopen("highcard.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d" ,&N);
    int A[N];
    for(int  i=0; i<N; i++){
        fscanf(In, " %d" ,&A[i]);
    }
    std::sort(A, A+N, [&](int a, int b){
        return a < b;
    } );
    fclose(In);
    int B[N];
    j = 0;
    int card = 1;
    for(int  i=0; i<N; i++){
        for(int  k=card; k<A[i]; k++){
            B[j++] = k;
        }
        card = A[i] + 1;
    }
    for(int  k=card; k<2*N+1; k++){
        B[j++] = k;
    }
    int win = 0;
    i_a = 0;
    for(int  i_b=0; i_b<N; i_b++){
        if(A[i_a] < B[i_b]){
            i_a++;
            win++;
        }
    }
    std::cout<<"win="<<win<<'\n';
    FILE* Out = fopen("highcard.out", "w");
    fprintf(Out, "%d\n", win);
    fclose(Out);
    return 0;
}

