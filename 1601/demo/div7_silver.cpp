#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv){
    int max_size;
    FILE* In = fopen("div7.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    int IDs[N];
    for(int  i=0; i<N; i++){
        fscanf(In, " %d" ,&IDs[i]);
    }
    fclose(In);
    int M[7] = {-1, -1, -1, -1, -1, -1, -1};
    int R[N];
    R[0] = IDs[0] % 7;
    M[R[0]] = 0;
    max_size = 0;
    for(int  i=1; i<N; i++){
        R[i] = (R[i-1] + IDs[i]) % 7;
        if(M[R[i]] == -1){
            M[R[i]] = i;
        }
        else{
            int d = i-M[R[i]];
            if(max_size < d){
                max_size = d;
            }
        }
    }
    std::cout<<"max_size="<<max_size<<'\n';
    FILE* Out = fopen("div7.out", "w");
    fprintf(Out, "%d\n", max_size);
    fclose(Out);
    return 0;
}

