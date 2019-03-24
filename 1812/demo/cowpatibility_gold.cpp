#include <cstdio>
#include <map>
#include <iostream>
#include <cstdio>
#include <algorithm>

struct S5 {
	int n;
	int v[5];
};

bool operator<(const S5 & a, const S5 & b);
S5 get_S5(int i, int *L);

int main(int argc, char** argv)
{
    std::map<S5, int> M;

    FILE* In = fopen("cowpatibility.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    fscanf(In, " %d" ,&N);
    int L[N][5];
    for (int  i = 0; i<N; i++) {
        fscanf(In, " %d %d %d %d %d" ,&L[i][0],&L[i][1],&L[i][2],&L[i][3],&L[i][4]);
        std::sort(L[i], L[i] + 5);
    }
    fclose(In);
    long long count = 0;
    for (int  i = 0; i<N; i++) {
        for (int  j = 1; j<32; j++) {
            M[get_S5(j,L[i])]++;
        }
    }
    count = (long long) N * (N - 1) / 2;
    for(auto &p : M){
        const int *v = &p.first.v[0];
        if (p.first.n % 2 == 1) {
            count -= (long long) p.second * (p.second - 1) / 2;
        } else {
            count += (long long) p.second * (p.second - 1) / 2;
        }
    }
    std::cout<<"count="<<count<<'\n';
    FILE* Out = fopen("cowpatibility.out", "w");
    fprintf(Out, "%d\n", count);
    fclose(Out);
    return 0;
}

bool operator<(const S5 & a, const S5 & b)
{
    for (int  i = 0; i<5; i++) {
        if (a.v[i] == b.v[i]) {
            continue;
        }
        return a.v[i] < b.v[i];
    }
    return false;
}

S5 get_S5(int i, int *L)
{
    S5 ret = {0, {0, 0, 0, 0, 0} };
    for (int  j = 0; j<5; j++) {
        if ((i >> j) & 1) {
            ret.v[ret.n++] = L[j];
        }
    }
    return ret;
}
