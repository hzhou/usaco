#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int get_swaps(int* L, int N);

int main(int argc, char** argv){
    int N;
    int n;
    FILE* In = fopen("outofplace.in", "r");
    fscanf(In, " %d" ,&N);
    int L[N];
    for(int  i=0; i<N; i++){
        fscanf(In, " %d" ,&L[i]);
    }
    fclose(In);
    n = get_swaps(L, N);
    std::cout<<"n="<<n<<'\n';
    FILE* Out = fopen("outofplace.out", "w");
    fprintf(Out, "%d\n", n);
    fclose(Out);
    return 0;
}

int get_swaps(int* L, int N){
    int n_le;
    printf("L[%d]: ", N);
    for(int  _i=0; _i<N; _i++){
        printf("%d ", L[_i]);
    }
    puts("");
    n_le = 0;
    for(int  i=1; i<N; i++){
        if(L[i-1] <= L[i]){
            n_le++;
        }
    }
    std::cout<<"n_le="<<n_le<<'\n';
    int i_bad;
    bool too_left;
    int n_eq = 0;
    if(n_le == N - 2){
        for(int  i=1; i<N; i++){
            if(L[i-1] > L[i]){
                if(i == 1){
                    i_bad = 0;
                    too_left = true;
                }
                else if(L[i-2] < L[i]){
                    i_bad = i - 1;
                    too_left = true;
                }
                else{
                    i_bad = i;
                    too_left = false;
                }
            }
        }
        std::cout<<"i_bad="<<i_bad<<", "<<"too_left="<<too_left<<'\n';
        if(too_left){
            for(int  i=i_bad+1; i<N; i++){
                if(L[i_bad] <= L[i]){
                    return i - i_bad - 1 - n_eq;
                }
                else if(L[i-1] == L[i]){
                    n_eq++;
                }
            }
        }
        else{
            for(int  i=i_bad-1; i>=0; i--){
                if(L[i_bad] >= L[i]){
                    return i_bad - i - 1 - n_eq;
                }
                else if(L[i+1] == L[i]){
                    n_eq++;
                }
            }
        }
    }
    else{
        for(int  i=1; i<N; i++){
            if(L[i-1] < L[i]){
                if(i == 1){
                    i_bad = 0;
                    too_left = true;
                }
                else if(L[i-2] > L[i]){
                    i_bad = i - 1;
                    too_left = true;
                }
                else{
                    i_bad = i;
                    too_left = false;
                }
            }
        }
        std::cout<<"i_bad="<<i_bad<<", "<<"too_left="<<too_left<<'\n';
        if(too_left){
            for(int  i=i_bad+1; i<N; i++){
                if(L[i_bad] >= L[i]){
                    return i - i_bad - 1 - n_eq;
                }
                else if(L[i-1] == L[i]){
                    n_eq++;
                }
            }
        }
        else{
            for(int  i=i_bad-1; i>=0; i--){
                if(L[i_bad] <= L[i]){
                    return i_bad - i - 1 - n_eq;
                }
                else if(L[i+1] == L[i]){
                    n_eq++;
                }
            }
        }
    }
    return -1;
}

