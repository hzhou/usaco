#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv){
    FILE* In = fopen("cowcode.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    char S[32];
    long long N;
    fscanf(In, "%s %lld", S, &N);
    fclose(In);
    int len = strlen(S);
    std::cout<<"S="<<S<<", "<<"N="<<N<<", "<<"len="<<len<<'\n';
    long long n;
    long long j;
    n = len;
    while(n < N){
        n *= 2;
    }
    j = N - 1;
    while(n > len){
        n /= 2;
        if(j >= n){
            j -= n;
            j--;
            if(j < 0){
                j = n - 1;
            }
        }
    }
    FILE* Out = fopen("cowcode.out", "w");
    fprintf(Out, "%c\n", S[j]);
    fclose(Out);
    return 0;
}

