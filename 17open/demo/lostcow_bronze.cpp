#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv){
    int n;
    int step;
    int dist;
    FILE* In = fopen("lostcow.in", "r");
    if(!In){
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int x;
    int y;
    fscanf(In, " %d %d" ,&x,&y);
    std::cout<<"x="<<x<<", "<<"y="<<y<<'\n';
    fclose(In);
    n = 0;
    step = 1;
    dist = 0;
    while((x < y && x + step < y) || (x > y && x + step > y)){
        dist += abs(step) * 2;
        n++;
        step *=- 2;
    }
    dist += abs(x - y);
    std::cout<<"dist="<<dist<<'\n';
    FILE* Out = fopen("lostcow.out", "w");
    fprintf(Out, "%d\n", dist);
    fclose(Out);
    return 0;
}

