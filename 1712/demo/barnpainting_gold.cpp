#include <vector>
#include <cstdio>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
    int flag;
    int c[3];
    vector<int> L;
};

int get_cnt(node *nodes, int i, int parent, int color);

int main(int argc, char** argv)
{
    int N;
    int K;
    int n;

    FILE* In = fopen("barnpainting.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d" ,&N,&K);
    node nodes[N];
    for (int  i = 0; i<N; i++) {
        nodes[i].flag = 0;
    }
    for (int  _i = 0; _i<N-1; _i++) {
        int i;
        int j;
        fscanf(In, " %d %d" ,&i,&j);
        i--;
        j--;
        nodes[i].L.push_back(j);
        nodes[j].L.push_back(i);
    }
    for (int  _i = 0; _i<K; _i++) {
        int i;
        int color;
        fscanf(In, " %d %d" ,&i,&color);
        i--;
        color--;
        for (int  c = 0; c<3; c++) {
            if (c != color) {
                nodes[i].flag |= 1 << c;
                nodes[i].c[c] = 0;
            }
        }
    }
    fclose(In);
    n = 0;
    for (int  c = 0; c<3; c++) {
        n += get_cnt(nodes, 0, -1, c);
    }
    n %= 1000000007;
    FILE* Out = fopen("barnpainting.out", "w");
    fprintf(Out, "%d\n", n);
    fclose(Out);
    return 0;
}

int get_cnt(node *nodes, int i, int parent, int color)
{
    int n;

    if (nodes[i].flag & (1 << color)) {
        return nodes[i].c[color];
    }
    n = 1;
    for(auto j : nodes[i].L){
        if (j != parent) {
            int n2 = 0;
            for (int  _i = 0; _i<3; _i++) {
                if (_i != color) {
                    n2 += get_cnt(nodes, j, i, _i);
                }
            }
            n = ((long long) n * n2) % (1000000007);
        }
    }
    nodes[i].flag |= 1 << color;
    nodes[i].c[color] = n;
    return n;
}
