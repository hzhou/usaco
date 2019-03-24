#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char** argv){
    FILE* In = fopen("hoofball.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    int X[N];
    for(int  i=0; i<N; i++){
        fscanf(In, " %d" ,&X[i]);
    }
    fclose(In);
    std::sort(X, X+N, [](int a, int b){
        return a < b;
    } );
    printf("X[%d]: ", N);
    for(int  _i=0; _i<N; _i++){
        printf("%3d ", X[_i]);
    }
    puts("");
    int D[N];
    D[0] = 0;
    for(int  i=1; i<N; i++){
        D[i] = X[i] - X[i-1];
    }
    printf("D[%d]: ", N);
    for(int  _i=0; _i<N; _i++){
        printf("%3d ", D[_i]);
    }
    puts("");
    int cnt = 0;
    int j = 0;
    j = 1;
    while(j < N){
        std::cout<<"j="<<j<<", "<<"X[j-1]="<<X[j-1]<<", "<<"D[j]="<<D[j]<<", "<<"cnt="<<cnt<<'\n';
        if(j == N - 1){
            cnt++;
            break;
        }
        else if(D[j] > D[j+1]){
            if(j > 1 && D[j] >= D[j-1]){
                cnt++;
                j++;
            }
            else{
                cnt++;
                while(j < N - 1 && D[j] > D[j+1]){
                    j++;
                }
                if(j == N - 2){
                    cnt++;
                    break;
                }
                else{
                    j += 2;
                }
            }
        }
        else{
            cnt++;
            while(j < N - 1 && D[j] <= D[j+1]){
                j++;
            }
            j += 1;
        }
    }
    FILE* Out = fopen("hoofball.out", "w");
    fprintf(Out, "%d\n", cnt);
    fclose(Out);
    return 0;
}

