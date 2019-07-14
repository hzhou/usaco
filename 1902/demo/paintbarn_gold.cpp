#include <cstdio>
#include <set>
#include <iostream>
#include <cstdio>
#include <algorithm>

int grid[200*200];

int main(int argc, char** argv)
{
    int n_max;

    FILE* In = fopen("paintbarn.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    int K;
    fscanf(In, " %d %d" ,&N,&K);
    int X1[N];
    int X2[N];
    int Y1[N];
    int Y2[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d %d %d %d" ,&X1[i],&Y1[i],&X2[i],&Y2[i]);
    }
    fclose(In);
    for (int  i = 0; i<N; i++) {
        for (int  i_y = Y1[i]; i_y<Y2[i]; i_y++) {
            for (int  i_x = X1[i]; i_x<X2[i]; i_x++) {
                grid[i_y*200+i_x]++;
            }
        }
    }
    int n_K = 0;
    int n_K_1 = 0;
    std::set<int> Xs;
    std::set<int> Ys;
    for (int  i = 0; i<200*200; i++) {
        if (grid[i] == K) {
            n_K++;
        } else if (grid[i] == K - 1) {
            n_K_1++;
            Xs.insert(i % 200);
            Ys.insert(i / 200);
        }
    }
    int pn_Xs[200];
    int pn_Ys[200];
    int n_Xs = 0;
    int n_Ys = 0;
    for(auto i_x : Xs){
        pn_Xs[n_Xs++] = i_x;
    }
    for(auto i_y : Ys){
        pn_Ys[n_Ys++] = i_y;
    }
    std::cout<<"n_K="<<n_K<<", "<<"n_K_1="<<n_K_1<<", "<<"n_Xs="<<n_Xs<<", "<<"n_Ys="<<n_Ys<<'\n';
    n_max = n_K;
    return 0;
}
