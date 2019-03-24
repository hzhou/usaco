#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv){
    int n_max;
    int count;
    int j;
    int k;
    int N;
    FILE* In = fopen("angry.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d" ,&N);
    int x[N];
    for(int  i=0; i<N; i++){
        fscanf(In, " %d" ,&x[i]);
    }
    fclose(In);
    std::sort(x, x+N, [&](int a, int b){
        return a < b;
    } );
    n_max = 0;
    for(int  i=0; i<N; i++){
        count = 1;
        int t;
        t = 1;
        j = i + 1;
        while(j < N){
            if(x[j] - x[j-1] <= t){
                k = j - 1;
                while(j<N && x[j]-x[k]<=t){
                    count++;
                    j++;
                }
                t++;
            }
            else{
                break;
            }
        }
        t = 1;
        j = i - 1;
        while(j >= 0){
            if(x[j+1] - x[j] <= t){
                k = j + 1;
                while(j>=0 && x[k]-x[j]<=t){
                    count++;
                    j--;
                }
                t++;
            }
            else{
                break;
            }
        }
        if(n_max < count){
            n_max = count;
            std::cout<<"i="<<i<<", "<<"count="<<count<<'\n';
        }
    }
    FILE* Out = fopen("angry.out", "w");
    fprintf(Out, "%d\n", n_max);
    fclose(Out);
    return 0;
}

