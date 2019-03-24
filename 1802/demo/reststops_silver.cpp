#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct stop {
    int i;
    int x;
    int c;
};


int main(int argc, char** argv)
{
    FILE* In = fopen("reststops.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int L;
    int N;
    int r_F;
    int r_B;
    fscanf(In, " %d %d %d %d" ,&L,&N,&r_F,&r_B);
    struct stop stops[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d %d" ,&stops[i].x,&stops[i].c);
        stops[i].i = i;
    }
    fclose(In);
    std::sort(stops, stops+N, [&](struct stop a, struct stop b){
        return a.c > b.c;
    } );
    int x = 0;
    int i = 0;
    unsigned long long total = 0;
    int j = 0;
    while (j < N) {
        total += (long long) (stops[j].x - x) * (r_F - r_B) * stops[j].c;
        x = stops[j].x;
        i = stops[j].i;
        while (j < N && stops[j].i <= i) {
            j++;
        }
    }
    std::cout<<"total="<<total<<'\n';
    FILE* Out = fopen("reststops.out", "w");
    fprintf(Out, "%llu\n", total);
    fclose(Out);
    return 0;
}
