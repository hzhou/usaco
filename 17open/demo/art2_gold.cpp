#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>

int get_level(int i1, int i2, int c0);

int color_list[100001];
int L[100001];
int R[100001];
int *cache;

int main(int argc, char** argv)
{
    int n_max;

    FILE* In = fopen("art2.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d" ,&color_list[i]);
    }
    fclose(In);
    for (int  i = 0; i<N+1; i++) {
        L[i] = -1;
        R[i] = -1;
    }
    for (int  i = 0; i<N; i++) {
        if (L[color_list[i]] == -1) {
            L[color_list[i]] = i;
            R[color_list[i]] = i;
        } else {
            R[color_list[i]] = i;
        }
    }
    cache = new int[N+1];
    for (int  i = 0; i<N+1; i++) {
        cache[i] = 0;
    }
    n_max = get_level(0, N - 1, 0);
    if (n_max >= 100001) {
        n_max = -1;
    }
    std::cout<<"n_max="<<n_max<<'\n';
    FILE* Out = fopen("art2.out", "w");
    fprintf(Out, "%d\n", n_max);
    fclose(Out);
    return 0;
}

int get_level(int i1, int i2, int c0)
{
    int tn_max;
    int i;
    int n_level;

    cache[c0] = 1;
    tn_max = 0;
    i = i1;
    while (i <= i2) {
        int c = color_list[i];
        if (c == c0) {
            i++;
            continue;
        }
        if (cache[c]) {
            return 100001;
        }
        if (R[c] > i2) {
            return 100001;
        }
        n_level = get_level(L[c], R[c], c);
        if (tn_max < n_level) {
            tn_max = n_level;
        }
        i = R[c] + 1;
    }
    if (c0 > 0) {
        tn_max++;
    }
    return tn_max;
}
