#include <cstdio>
#include <set>
#include <cstdio>
#include <algorithm>

int get_K(int* dur, int N, int T_max);
bool try_K(int* dur, int N, int T_max, int K);

int main(int argc, char** argv){
    int N;
    int T_max;
    FILE* In = fopen("cowdance.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d" ,&N,&T_max);
    int dur[N];
    for(int  i=0; i<N; i++){
        fscanf(In, " %d" ,&dur[i]);
    }
    fclose(In);
    int K = get_K(dur, N, T_max);
    FILE* Out = fopen("cowdance.out", "w");
    fprintf(Out, "%d\n", K);
    fclose(Out);
    return 0;
}

int get_K(int* dur, int N, int T_max){
    int K;
    int sum_1 = 0;
    for(int  i=0; i<N; i++){
        sum_1 += dur[i];
    }
    if(sum_1 < T_max){
        return 1;
    }
    int K_min = sum_1/T_max;
    if(sum_1 % T_max){
        K_min++;
    }
    K = K_min;
    while(!try_K(dur, N, T_max, K)){
        K++;
    }
    return K;
}

bool try_K(int* dur, int N, int T_max, int K){
    int i;
    std::multiset<int> M;
    for(int  i=0; i<K; i++){
        M.insert(dur[i]);
    }
    i = K;
    while(i < N){
        auto it = M.begin();
        int n = *it;
        n += dur[i++];
        if(n > T_max){
            return false;
        }
        M.erase(it);
        M.insert(n);
    }
    return true;
}

