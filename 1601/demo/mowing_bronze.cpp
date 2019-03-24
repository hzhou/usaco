#include <unordered_map>
#include <cstdio>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv){
    int R;
    int k;
    int t;
    FILE* In = fopen("mowing.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    char D[N];
    int S[N];
    for(int  i=0; i<N; i++){
        char s[2];
        fscanf(In, "%s %d", s, &S[i]);
        D[i] = s[0];
    }
    fclose(In);
    std::unordered_map<int, int> M;
    R = 100 * 20;
    k = 0;
    t = 0;
    M[0] = 0;
    int x = -1;
    for(int  i=0; i<N; i++){
        int d;
        if(D[i] == 'N'){
            d = -R;
        }
        else if(D[i] == 'E'){
            d = 1;
        }
        else if(D[i] == 'S'){
            d = R;
        }
        else if(D[i] == 'W'){
            d = -1;
        }
        else{
            fprintf(stderr, "Bad input\n");
            exit(-1);
        }
        for(int  j=0; j<S[i]; j++){
            k += d;
            t++;
            if(M.count(k)){
                if(x == -1 || x > t - M[k]){
                    x = t - M[k];
                }
            }
            M[k] = t;
        }
    }
    FILE* Out = fopen("mowing.out", "w");
    fprintf(Out, "%d\n", x);
    fclose(Out);
    return 0;
}

