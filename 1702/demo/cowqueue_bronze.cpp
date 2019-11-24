#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct item {
    int arrival;
    int duration;
};


int main(int argc, char** argv)
{

    FILE* In = fopen("cowqueue.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);

    item L[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d %d" ,&L[i].arrival,&L[i].duration);
    }
    std::sort(L, L+N, [&](item a, item b){
        return a.arrival < b.arrival;
    } );
    fclose(In);

    int t;
    t = L[0].arrival + L[0].duration;
    for (int  i = 1; i<N; i++) {
        if (L[i].arrival < t) {
            t += L[i].duration;
        } else {
            t = L[i].arrival + L[i].duration;
        }
    }

    std::cout<<"t="<<t<<'\n';
    FILE* Out = fopen("cowqueue.out", "w");
    fprintf(Out, "%d\n", t);




    fclose(Out);
    return 0;
}
