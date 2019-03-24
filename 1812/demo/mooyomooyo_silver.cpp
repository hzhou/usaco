#include <vector>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

void find_region(char *G, int N, int k, vector<vector<int>>& regions);

int main(int argc, char** argv)
{
    int N;
    int K;
    int i2;

    FILE* In = fopen("mooyomooyo.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d" ,&N,&K);
    std::cout<<"N="<<N<<", "<<"K="<<K<<'\n';
    char grid[N*10+1];
    for (int  i = 0; i<N; i++) {
        char s[10+1];
        fscanf(In, "%s", s);
        memcpy(grid + (N - 1 - i) * 10, s, 10);
    }
    fclose(In);
    for (int  j = 0; j<10; j++) {
        i2 = 0;
        for (int  i = 0; i<N; i++) {
            while (i2 < N && grid[i2*10+j] == '0') {
                i2++;
            }
            if (i < i2) {
                if (i2 < N) {
                    grid[i*10+j] = grid[i2*10+j];
                } else {
                    grid[i*10+j] = '0';
                }
            }
            i2++;
        }
    }
    char G[N*10];
    while (1) {
        for (int  i = 0; i<N*10; i++) {
            G[i] = grid[i];
        }
        vector< vector<int> > regions;
        for (int  i = 0; i<N*10; i++) {
            if (G[i] != '0') {
                find_region(G, N, i, regions);
            }
        }
        bool flag = false;
        for (int  i = 0; i<regions.size(); i++) {
            if (regions[i].size() >= K) {
                flag = true;
                for(auto k : regions[i]){
                    grid[k] = '0';
                }
            }
        }
        regions.clear();
        if (!flag) {
            break;
        }
        for (int  j = 0; j<10; j++) {
            i2 = 0;
            for (int  i = 0; i<N; i++) {
                while (i2 < N && grid[i2*10+j] == '0') {
                    i2++;
                }
                if (i < i2) {
                    if (i2 < N) {
                        grid[i*10+j] = grid[i2*10+j];
                    } else {
                        grid[i*10+j] = '0';
                    }
                }
                i2++;
            }
        }
    }
    FILE* Out = fopen("mooyomooyo.out", "w");
    for (int  i = 0; i<N; i++) {
        fprintf(Out, "%.*s\n", 10, grid + (N - 1 - i) * 10);
    }
    fclose(Out);
    return 0;
}

void find_region(char *G, int N, int k, vector<vector<int>>& regions)
{
    vector<int> R;
    vector<int> stack;

    char c = G[k];
    stack.push_back(k);
    while (stack.size() > 0) {
        k = stack.back();
        stack.pop_back();
        int p[4];
        int n = 0;
        int i = k / 10;
        int j = k % 10;
        if (i > 0) {
            p[n++] = k - 10;
        }
        if (i < N - 1) {
            p[n++] = k + 10;
        }
        if (j > 0) {
            p[n++] = k - 1;
        }
        if (j < 10 - 1) {
            p[n++] = k + 1;
        }
        for (int  i = 0; i<n; i++) {
            if (G[p[i]] == c) {
                G[p[i]] = '0';
                stack.push_back(p[i]);
                R.push_back(p[i]);
            }
        }
    }
    regions.push_back(R);
}
