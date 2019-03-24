#include <vector>
#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

struct T {
	int i;
	int n;
};


int main(int argc, char** argv){
    int N;
    int j;
    int i0;
    int n_groups;
    int i;
    int sum;
    int i2;
    double d;
    FILE* In = fopen("cbarn.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d" ,&N);
    int C[N];
    for(int  i=0; i<N; i++){
        fscanf(In, " %d" ,&C[i]);
    }
    fclose(In);
    std::vector<T> groups;
    j = 0;
    i0 = 0;
    for(int  i=0; i<N; i++){
        if(C[i] > 0){
            if(j <= i){
                if(j > i0){
                    groups.push_back((struct T){i0, j - i0});
                }
                j = i;
                i0 = i;
            }
            j += C[i];
        }
    }
    if(j > i0){
        groups.push_back((struct T){i0, j - i0});
    }
    n_groups = groups.size();
    while(n_groups > 1){
        groups[0].i = groups[n_groups-1].i;
        groups[0].n += groups[n_groups-1].n;
        n_groups--;
        j = groups[0].i + groups[0].n - N;
        i = 1;
        while(i<n_groups){
            if(j >= groups[i].i){
                groups[i].i = -1;
                groups[0].n += groups[i].n;
                j += groups[i].n;
            }
            else{
                break;
            }
            i++;
        }
        if(i > 1){
            n_groups -= i - 1;
            for(int  i2=1; i2<n_groups; i2++){
                groups[i2] = groups[i2+i-1];
            }
        }
    }
    sum = 0;
    j = groups[0].i;
    for(int  i=0; i<N; i++){
        i2 = (groups[0].i + i) % N;
        if(C[i2] > 0){
            for(int  k=0; k<C[i2]; k++){
                d = j - i2;
                if(d < 0){
                    d += N;
                }
                sum += d * d;
                j++;
                if(j >= N){
                    j -= N;
                }
            }
        }
    }
    std::cout<<"sum="<<sum<<'\n';
    FILE* Out = fopen("cbarn.out", "w");
    fprintf(Out, "%d\n", sum);
    fclose(Out);
    return 0;
}

