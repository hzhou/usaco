#include <unordered_map>
#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv){
    int R;
    int n_region;
    int k;
    int k_prev;
    int dir;
    int dir2;
    int n_gate;
    int N;
    FILE* In = fopen("gates.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d" ,&N);
    char str[N+1];
    fscanf(In, "%s", str);
    fclose(In);
    R = 1000 * 2;
    std::unordered_map<int, int> Point;
    n_region = 0;
    k = 0;
    for(int  i=0; i<N; i++){
        k_prev = k;
        if(str[i] == 'N'){
            k += R;
            dir = 1;
            dir2 = 4;
        }
        else if(str[i] == 'E'){
            k++;
            dir = 2;
            dir2 = 8;
        }
        else if(str[i] == 'S'){
            k -= R;
            dir = 4;
            dir2 = 1;
        }
        else if(str[i] == 'W'){
            k--;
            dir = 8;
            dir2 = 2;
        }
        if(Point.count(k)){
            if((Point[k] & dir) == 0){
                n_region++;
            }
        }
        Point[k_prev] |= dir2;
        Point[k] |= dir;
    }
    n_gate = n_region;
    std::cout<<"n_gate="<<n_gate<<'\n';
    FILE* Out = fopen("gates.out", "w");
    fprintf(Out, "%d\n", n_gate);
    fclose(Out);
    return 0;
}

