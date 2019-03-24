#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv){
    int n;
    int j;
    int C;
    int N;
    FILE* In = fopen("helpcross.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d" ,&C,&N);
    std::cout<<"C="<<C<<", "<<"N="<<N<<'\n';
    int C_list[C];
    for(int  i=0; i<C; i++){
        fscanf(In, " %d" ,&C_list[i]);
    }
    int A[N];
    int B[N];
    for(int  i=0; i<N; i++){
        fscanf(In, " %d %d" ,&A[i],&B[i]);
    }
    fclose(In);
    std::sort(C_list, C_list+C, [&](int a, int b){
        return a < b;
    } );
    int P[N];
    for(int  i=0; i<N; i++){
        P[i] = i;
    }
    std::sort(P, P+N, [&](int a, int b){
        return B[a] < B[b];
    } );
    n = 0;
    j = 0;
    int t_max = C_list[C-1] + 1;
    std::cout<<"t_max="<<t_max<<'\n';
    for(int  i=0; i<C; i++){
        while(j < N && B[P[j]] < C_list[i]){
            j++;
        }
        if(j == N){
            break;
        }
        for(int  k=j; k<N; k++){
            if(A[P[k]] <= C_list[i]){
                n++;
                A[P[k]] = t_max;
                break;
            }
        }
    }
    std::cout<<"n="<<n<<'\n';
    FILE* Out = fopen("helpcross.out", "w");
    fprintf(Out, "%d\n", n);
    fclose(Out);
    return 0;
}

