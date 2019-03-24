#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv){
    FILE* In = fopen("art.in", "r");
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
    int HAS[10] = {0};
    int X1[10] = {0};
    int X2[10] = {0};
    int Y1[10] = {0};
    int Y2[10] = {0};
    for(int  i=0; i<N; i++){
        for(int  j=0; j<N; j++){
            int color = grid[i*N+j];
            HAS[color]++;
            if(HAS[color] == 1){
                X1[color] = j;
                X2[color] = j;
                Y1[color] = i;
                Y2[color] = i;
            }
            else{
                if(X1[color] > j){
                    X1[color] = j;
                }
                if(X2[color] < j){
                    X2[color] = j;
                }
                if(Y1[color] > i){
                    Y1[color] = i;
                }
                if(Y2[color] < i){
                    Y2[color] = i;
                }
            }
        }
    }
    for(int  i=1; i<10; i++){
        X2[i]++;
        Y2[i]++;
    }
    int count = 0;
    for(int  i=1; i<10; i++){
        if(HAS[i] == 0){
            continue;
        }
        for(int  j=1; j<10; j++){
            if(i == j || HAS[j] == 0){
                continue;
            }
            int x1;
            int x2;
            int y1;
            int y2;
            x1 = std::max(X1[i], X1[j]);
            x2 = std::min(X2[i], X2[j]);
            y1 = std::max(Y1[i], Y1[j]);
            y2 = std::min(Y2[i], Y2[j]);
            for(int  ii=y1; ii<y2; ii++){
                for(int  jj=x1; jj<x2; jj++){
                    if(grid[ii*N+jj] == i){
                        goto next_i;
                    }
                }
            }
        }
        count++;
        next_i:
            continue;
    }
    std::cout<<"count="<<count<<'\n';
    FILE* Out = fopen("art.out", "w");
    fprintf(Out, "%d\n", count);
    fclose(Out);
    return 0;
}

