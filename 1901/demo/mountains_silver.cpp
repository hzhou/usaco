#include <cstdio>
#include <iostream>
#include <cstdio>
#include <cassert>
#include <algorithm>

int N;

int main(int argc, char** argv)
{
    int n_ret;
    int count;
    int flag;

    FILE* In = fopen("mountains.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    n_ret = fscanf(In, " %d" ,&N);
    assert(n_ret > 0);
    int x_list[N];
    int y_list[N];
    for (int  i = 0; i<N; i++) {
        n_ret = fscanf(In, " %d %d" ,&x_list[i],&y_list[i]);
        assert(n_ret > 0);
    }
    fclose(In);

    int P[N];
    for (int  i = 0; i<N; i++) {
        P[i] = i;
    }

    std::sort(P, P+N, [&](int a, int b){
        return y_list[a] > y_list[b];
    } );

    int visible[N];

    count = 0;
    for (int  i = 0; i<N; i++) {
        flag = 1;
        for (int  j = 0; j<i; j++) {
            if (visible[j]) {
                if (abs(x_list[P[i]] - x_list[P[j]]) <= y_list[P[j]] - y_list[P[i]]) {
                    flag = 0;
                    break;
                }
            }
        }
        visible[i] = flag;
    }

    count = 0;
    for (int  i = 0; i<N; i++) {
        if (visible[i]) {
            count++;
        }
    }

    std::cout<<"count="<<count<<'\n';
    FILE* Out = fopen("mountains.out", "w");
    fprintf(Out, "%d\n", count);
    fclose(Out);
    return 0;
}
