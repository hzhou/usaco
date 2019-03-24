#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(int argc, char** argv){
    FILE* In = fopen("crossroad.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    int cows[10];
    for(int  i=0; i<10; i++){
        cows[i] = -1;
    }
    int count = 0;
    for(int  i=0; i<N; i++){
        int i_cow;
        int i_side;
        fscanf(In, " %d %d" ,&i_cow,&i_side);
        i_cow--;
        if(cows[i_cow] >= 0 && cows[i_cow] != i_side){
            count++;
        }
        cows[i_cow] = i_side;
    }
    fclose(In);
    std::cout<<"count="<<count<<'\n';
    FILE* Out = fopen("crossroad.out", "w");
    fprintf(Out, "%d\n", count);
    fclose(Out);
    return 0;
}

