#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv){
    int N;
    int total;
    int sum;
    int min;
    FILE* In = fopen("cbarn.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d" ,&N);
    int R[N];
    for(int  i=0; i<N; i++){
        fscanf(In, " %d" ,&R[i]);
    }
    fclose(In);
    total = 0;
    sum = R[0];
    for(int  i=1; i<N; i++){
        total += R[i] * i;
        sum += R[i];
    }
    min = total;
    for(int  i=1; i<N; i++){
        total -= sum;
        total += R[i-1] * N;
        std::cout<<"i="<<i<<", "<<"min="<<min<<", "<<"total="<<total<<'\n';
        if(min > total){
            min = total;
        }
    }
    FILE* Out = fopen("cbarn.out", "w");
    fprintf(Out, "%d\n", min);
    fclose(Out);
    return 0;
}

