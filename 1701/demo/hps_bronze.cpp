#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv){
    int N;
    int n_A;
    int n_B;
    FILE* In = fopen("hps.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d" ,&N);
    std::cout<<"N="<<N<<'\n';
    n_A = 0;
    n_B = 0;
    for(int  i=0; i<N; i++){
        int a;
        int b;
        fscanf(In, " %d %d" ,&a,&b);
        std::cout<<"i="<<i<<", "<<"a="<<a<<", "<<"b="<<b<<'\n';
        if(a == b + 1 || a == b + 1 - 3){
            n_B++;
        }
        else if(a + 1 == b || a + 1 - 3 == b){
            n_A++;
        }
    }
    fclose(In);
    FILE* Out = fopen("hps.out", "w");
    if(n_A > n_B){
        fprintf(Out, "%d\n", n_A);
    }
    else{
        fprintf(Out, "%d\n", n_B);
    }
    fclose(Out);
    return 0;
}

