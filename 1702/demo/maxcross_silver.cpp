#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int main(int argc, char** argv)
{

    FILE* In = fopen("maxcross.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    int K;
    int B;
    fscanf(In, " %d %d %d" ,&N,&K,&B);
    std::cout<<"N="<<N<<", "<<"K="<<K<<", "<<"B="<<B<<'\n';

    int broken_list[B+1];
    for (int  i = 0; i<B; i++) {
        fscanf(In, " %d" ,&broken_list[i]);
        broken_list[i]--;
    }
    broken_list[B] = N;
    fclose(In);

    std::sort(broken_list, broken_list+B, [&](int a, int b){
        return a < b;
    } );

    int broken_counts[N+1];
    int count = 0;
    int i_B = 0;
    for (int  i = 0; i<N; i++) {
        broken_counts[i] = count;
        if (i_B < B && i == broken_list[i_B]) {
            count++;
            i_B++;
        }
    }
    broken_counts[N] = B;

    int M = B;
    for (int  i = 0; i<N-K+1; i++) {
        if (M > broken_counts[i+K] - broken_counts[i]) {
            M = broken_counts[i+K] - broken_counts[i];


        }
    }
    std::cout<<"M="<<M<<'\n';
    FILE* Out = fopen("maxcross.out", "w");
    fprintf(Out, "%d\n", M);
    fclose(Out);
    return 0;
}
