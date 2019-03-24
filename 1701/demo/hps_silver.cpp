#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int get_phs(char c);
int get_max(int stats[3]);

int main(int argc, char** argv){
    int N;
    int n_max;
    int n;
    FILE* In = fopen("hps.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d" ,&N);
    std::cout<<"N="<<N<<'\n';
    int A[N];
    for(int  i=0; i<N; i++){
        char s[2];
        fscanf(In, "%s", s);
        A[i] = get_phs(s[0]);
    }
    fclose(In);
    int stats_front[3] = {0,0,0};
    int stats_back[3] = {0,0,0};
    for(int  i=0; i<N; i++){
        stats_back[A[i]]++;
    }
    n_max = 0;
    for(int  i=0; i<N; i++){
        n = get_max(stats_front) + get_max(stats_back);
        if(n_max < n){
            n_max = n;
        }
        stats_front[A[i]]++;
        stats_back[A[i]]--;
    }
    std::cout<<"n_max="<<n_max<<'\n';
    FILE* Out = fopen("hps.out", "w");
    fprintf(Out, "%d\n", n_max);
    fclose(Out);
    return 0;
}

int get_phs(char c){
    if(c == 'P'){
        return 0;
    }
    else if(c == 'H'){
        return 1;
    }
    else{
        return 2;
    }
}

int get_max(int stats[3]){
    if(stats[0] >= stats[1] && stats[0] >= stats[2]){
        return stats[0];
    }
    else if(stats[1] >= stats[0] && stats[1] >= stats[2]){
        return stats[1];
    }
    else{
        return stats[2];
    }
}

