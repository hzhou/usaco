#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv){
    FILE* In = fopen("maxcross.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    int K;
    int B;
    fscanf(In, " %d %d %d" ,&N,&K,&B);
    std::cout<<"N="<<N<<", "<<"K="<<K<<", "<<"B="<<B<<'\n';
    int broken_list[B+1];
    for(int  i=0; i<B; i++){
        fscanf(In, " %d" ,&broken_list[i]);
        broken_list[i]--;
    }
    broken_list[B] = N;
    fclose(In);
    std::sort(broken_list, broken_list+B, [&](int a, int b){
        return a < b;
    } );
    int M = B;
    int start = 0;
    if(broken_list[B] - broken_list[B-1] - 1 >= K){
        M = 0;
    }
    else{
        for(int  j=0; j<B; j++){
            std::cout<<"K="<<K<<", "<<"start="<<start<<", "<<"j="<<j<<", "<<"broken_list[j]="<<broken_list[j]<<'\n';
            if(broken_list[j] - start >= K){
                M = 0;
                break;
            }
            int m = M;
            if(j + m > B){
                m = B - j;
            }
            for(int  i=j; i<j+m; i++){
                int end = broken_list[i+1];
                int length = end-start;
                if(length >= K){
                    M = i - j + 1;
                    break;
                }
            }
            start = broken_list[j] + 1;
        }
    }
    std::cout<<"M="<<M<<'\n';
    FILE* Out = fopen("maxcross.out", "w");
    fprintf(Out, "%d\n", M);
    fclose(Out);
    return 0;
}

