#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int b_search(int * x, int N, int y);

int main(int argc, char** argv){
    int R1;
    int R2;
    int R;
    bool b_success;
    int j;
    int N;
    int K;
    FILE* In = fopen("angry.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d" ,&N,&K);
    int x[N];
    for(int  i=0; i<N; i++){
        fscanf(In, " %d" ,&x[i]);
    }
    std::sort(x, x+N, [&](int a, int b){
        return a < b;
    } );
    fclose(In);
    R1 = 0;
    R2 = 50000;
    while(R1 <= R2){
        R = (R1 + R2) / 2;
        b_success = false;
        j = 0;
        for(int  i=0; i<K; i++){
            j += b_search(x + j, N - j, x[j] + R * 2);
            if(j > N - 1){
                b_success = true;
                break;
            }
        }
        if(b_success){
            R2 = R - 1;
        }
        else{
            R1 = R + 1;
        }
    }
    R = R1;
    std::cout<<"R="<<R<<'\n';
    FILE* Out = fopen("angry.out", "w");
    fprintf(Out, "%d\n", R);
    fclose(Out);
    return 0;
}

int b_search(int * x, int N, int y){
    int i1;
    int i2;
    int i3;
    i1 = 0;
    i2 = N - 1;
    if(x[i2] < y){
        return i2 + 1;
    }
    while(i1 <= i2){
        i3 = (i1 + i2) / 2;
        if(x[i3] == y){
            return i3 + 1;
        }
        else if(x[i3] < y){
            i1 = i3 + 1;
        }
        else{
            i2 = i3 - 1;
        }
    }
    return i1;
}

