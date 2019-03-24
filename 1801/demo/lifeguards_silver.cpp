#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct item {
    int t1;
    int t2;
};


int main(int argc, char** argv)
{
    int N;

    FILE* In = fopen("lifeguards.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d" ,&N);
    item L[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d %d" ,&L[i].t1,&L[i].t2);
    }
    std::sort(L, L+N, [&](item a, item b){
        return a.t1 < b.t1;
    } );
    fclose(In);
    int l = 0;
    int t = L[0].t1;
    for (int  i = 0; i<N; i++) {
        int t1 = L[i].t1;
        if (t1 < t) {
            t1 = t;
        }
        if (L[i].t2 > t) {
            t = L[i].t2;
            l += t - t1;
        }
    }
    int g_min = 1000000000;
    t = 0;
    for (int  i = 0; i<N; i++) {
        if (L[i].t1 < t) {
            L[i].t1 = t;
        }
        int l2;
        if (i + 1 < N && L[i+1].t1 < L[i].t2) {
            l2 = L[i+1].t1 - L[i].t1;
        } else {
            l2 = L[i].t2 - L[i].t1;
        }
        if (l2 <= 0) {
            g_min = 0;
            break;
        }
        if (g_min > l2) {
            g_min = l2;
        }
        t = L[i].t2;
    }
    l -= g_min;
    std::cout<<"l="<<l<<'\n';
    FILE* Out = fopen("lifeguards.out", "w");
    fprintf(Out, "%d\n", l);
    fclose(Out);
    return 0;
}
