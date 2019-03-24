#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char** argv){
    int j;
    FILE* In = fopen("taming.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    int logs[N];
    for(int  i=0; i<N; i++){
        fscanf(In, " %d" ,&logs[i]);
    }
    fclose(In);
    logs[0] = 0;
    int m = 0;
    int M = 0;
    int n_missing = 0;
    j = N - 1;
    while(j >= 0){
        if(logs[j] == -1){
            n_missing++;
            j--;
        }
        else{
            if(n_missing > 0){
                M += n_missing;
                n_missing = 0;
            }
            m++;
            M++;
            while(logs[j] != 0){
                if(logs[j-1] !=- 1 && logs[j-1] != logs[j] - 1){
                    m = -1;
                    j = -1;
                    break;
                }
                logs[j-1] = logs[j] - 1;
                j--;
            }
            j--;
        }
    }
    std::cout<<"m="<<m<<", "<<"M="<<M<<'\n';
    FILE* Out = fopen("taming.out", "w");
    if(m < 0){
        fprintf(Out, "-1\n");
    }
    else{
        fprintf(Out, "%d %d\n", m, M);
    }
    fclose(Out);
    return 0;
}

