#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int N;
int M;
int K;

int main(int argc, char** argv){
    int k;
    int j;
    FILE* In = fopen("milkorder.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d %d" ,&N,&M,&K);
    std::cout<<"N="<<N<<", "<<"M="<<M<<", "<<"K="<<K<<'\n';
    int in_K[N];
    for(int  i=0; i<N; i++){
        in_K[i] = -1;
    }
    int Mlist[M];
    for(int  i=0; i<M; i++){
        fscanf(In, " %d" ,&Mlist[i]);
        Mlist[i]--;
    }
    printf("Mlist[%d]: ", M);
    for(int  _i=0; _i<M; _i++){
        printf("%d ", Mlist[_i]);
    }
    puts("");
    int C[K];
    int P[K];
    for(int  i=0; i<K; i++){
        fscanf(In, " %d %d" ,&C[i],&P[i]);
        C[i]--;
        P[i]--;
        in_K[C[i]] = i;
    }
    fclose(In);
    int cows[N];
    for(int  i=0; i<N; i++){
        cows[i] = -1;
    }
    for(int  i=0; i<K; i++){
        fprintf(stdout, "    :[K] P[i]=%d, C[i]=%d\n", P[i], C[i]);
        cows[P[i]] = C[i];
    }
    int i_pos = -1;
    if(in_K[0] >= 0){
        i_pos = in_K[0];
        printf("0 in K: %d\n", i_pos);
    }
    else{
        int j_min = 0;
        int i_min = 0;
        for(int  i=0; i<M; i++){
            if(in_K[Mlist[i]] >= 0){
                k = in_K[Mlist[i]];
                j = P[k];
                fprintf(stdout, "    :[in_K_M] i=%d, k=%d, Mlist[i]=%d, C[k]=%d, j=%d\n", i, k, Mlist[i], C[k], j);
                for(int i2 = i-1; i2>=0 && in_K[Mlist[i2]]==-1; i2--){
                    while(cows[j] >= 0){
                        j--;
                    }
                    cows[j] = Mlist[i2];
                    fprintf(stdout, "    :[post_fill] j=%d, i2=%d, Mlist[i2]=%d\n", j, i2, Mlist[i2]);
                }
                i_min = i + 1;
                j_min = P[k];
            }
            else if(Mlist[i] == 0){
                fprintf(stdout, "    :[in_M_0] i=%d, i_min=%d, j_min=%d\n", i, i_min, j_min);
                j = j_min;
                while(1){
                    while(cows[j] >= 0){
                        j++;
                    }
                    std::cout<<"j="<<j<<", "<<"i_min="<<i_min<<", "<<"i="<<i<<'\n';
                    if(i_min == i){
                        i_pos = j;
                        break;
                    }
                    cows[j] = Mlist[i_min];
                    i_min++;
                }
                break;
            }
        }
    }
    if(i_pos < 0){
        j = 0;
        while(cows[j] >= 0){
            j++;
        }
        i_pos = j;
    }
    i_pos++;
    std::cout<<"i_pos="<<i_pos<<'\n';
    FILE* Out = fopen("milkorder.out", "w");
    fprintf(Out, "%d\n", i_pos);
    fclose(Out);
    return 0;
}

