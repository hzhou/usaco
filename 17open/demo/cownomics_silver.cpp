#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int ACTG_idx(char ch);

int main(int argc, char** argv){
    int k;
    FILE* In = fopen("cownomics.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    int M;
    fscanf(In, " %d %d" ,&N,&M);
    std::cout<<"N="<<N<<", "<<"M="<<M<<'\n';
    char spotty[N][M+1];
    char plain[N][M+1];
    for(int  i=0; i<N; i++){
        fscanf(In, "%s", spotty[i]);
    }
    for(int  i=0; i<N; i++){
        fscanf(In, "%s", plain[i]);
    }
    fclose(In);
    int count = 0;
    for(int  i1=0; i1<M; i1++){
        for(int  i2=i1+1; i2<M; i2++){
            for(int  i3=i2+1; i3<M; i3++){
                int G[64] = {0};
                for(int  i=0; i<N; i++){
                    k = ACTG_idx(spotty[i][i1]) * 16 + ACTG_idx(spotty[i][i2]) * 4 + ACTG_idx(spotty[i][i3]);
                    G[k]++;
                }
                bool flag = true;
                for(int  i=0; i<N; i++){
                    k = ACTG_idx(plain[i][i1]) * 16 + ACTG_idx(plain[i][i2]) * 4 + ACTG_idx(plain[i][i3]);
                    if(G[k]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    count++;
                }
            }
        }
    }
    std::cout<<"count="<<count<<'\n';
    FILE* Out = fopen("cownomics.out", "w");
    fprintf(Out, "%d\n", count);
    fclose(Out);
    return 0;
}

int ACTG_idx(char ch){
    if(ch == 'A'){
        return 0;
    }
    if(ch == 'C'){
        return 1;
    }
    if(ch == 'T'){
        return 2;
    }
    if(ch == 'G'){
        return 3;
    }
}

