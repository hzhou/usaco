#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv){
    int A[4];
    int B[4];
    FILE* In = fopen("promote.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    for(int  i=0; i<4; i++){
        fscanf(In, " %d %d" ,&A[i],&B[i]);
    }
    fclose(In);
    int C[4];
    C[3] = B[3] - A[3];
    B[3-1] += C[3];
    C[2] = B[2] - A[2];
    B[2-1] += C[2];
    C[1] = B[1] - A[1];
    B[1-1] += C[1];
    std::cout<<"C[1]="<<C[1]<<", "<<"C[2]="<<C[2]<<", "<<"C[3]="<<C[3]<<'\n';
    FILE* Out = fopen("promote.out", "w");
    for(int  i=1; i<4; i++){
        fprintf(Out, "%d\n", C[i]);
    }
    fclose(Out);
    return 0;
}

