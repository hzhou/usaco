#include <cstdio>
#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>

int try_y(int y);

int N;
int W;
int *w_list;
int *t_list;

int main(int argc, char** argv)
{
    int i1;
    int i2;
    int i3;

    FILE* In = fopen("talent.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d" ,&N,&W);
    w_list = new int[N];
    t_list = new int[N];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d %d" ,&w_list[i],&t_list[i]);
    }
    fclose(In);
    std::cout<<"N="<<N<<", "<<"W="<<W<<'\n';
    i1 = 0;
    i2 = 1000 * 1000 * 250;
    while (i1 <= i2) {
        i3 = (i1 + i2) / 2;
        if (try_y(i3)) {
            i1 = i3 + 1;
        } else {
            i2 = i3 - 1;
        }
    }
    int y = i2;
    FILE* Out = fopen("talent.out", "w");
    fprintf(Out, "%d\n", y);
    fclose(Out);
    return 0;
}

int try_y(int y)
{
    int w;

    long long T[W+1];
    for (int  i = 0; i<W+1; i++) {
        T[i] = LLONG_MIN;
    }
    T[0] = 0;
    for (int  j = 0; j<N; j++) {
        long long n_inc;
        n_inc = (long long) 1000 * t_list[j] - (long long) y * w_list[j];
        for (int  i_w = W; i_w >= 0; i_w--) {
            if (T[i_w] != LLONG_MIN) {
                w = i_w + w_list[j];
                if (w > W) {
                    w = W;
                }
                if (T[w] < T[i_w] + n_inc) {
                    T[w] = T[i_w] + n_inc;
                }
            }
        }
    }
    if (T[W] >= 0) {
        return 1;
    } else {
        return 0;
    }
}
