#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv){
    int n;
    int k;
    FILE* In = fopen("cowtip.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    std::cout<<"N="<<N<<'\n';
    int grid[N*N];
    for(int  i=0; i<N; i++){
        char s[12];
        fscanf(In, "%s", s);
        for(int  j=0; j<N; j++){
            grid[i*N+j] = s[j] - '0';
        }
    }
    fclose(In);
    n = 0;
    for(int  i=N-1; i>=0; i--){
        for(int  j=N-1; j>=0; j--){
            if(grid[i*N+j]){
                n++;
                for(int  i2=0; i2<=i; i2++){
                    for(int  j2=0; j2<=j; j2++){
                        k = i2 * N + j2;
                        grid[k] = 1 - grid[k];
                    }
                }
            }
        }
    }
    FILE* Out = fopen("cowtip.out", "w");
    fprintf(Out, "%d\n", n);
    fclose(Out);
    return 0;
}

