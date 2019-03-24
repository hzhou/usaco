#include <cstdio>
#include <map>
#include <iostream>
#include <cstdio>
#include <algorithm>

struct k_seq {
    int k;
    int seq;
};


int main(int argc, char** argv)
{
    int k;
    int i_seq;
    int i;
    int j;
    int i_seq_next;
    int n_min;

    FILE* In = fopen("visitfj.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    int T;
    fscanf(In, " %d %d" ,&N,&T);
    int grid[N*N];
    for (int  i = 0; i<N*N; i++) {
        fscanf(In, " %d" ,&grid[i]);
    }
    fclose(In);
    std::cout<<"N="<<N<<", "<<"T="<<T<<'\n';
    int costs[3][N*N];
    for (int  i = 0; i<N*N; i++) {
        costs[0][i] = -1;
        costs[1][i] = -1;
        costs[2][i] = -1;
    }
    costs[0][0] = 0;
    std::multimap<int, struct k_seq> stack;
    stack.insert({0, {0, 0}});
    while (stack.size() > 0) {
        int t;
        auto it = stack.begin();
        t = it->first;
        k = it->second.k;
        i_seq = it->second.seq;
        stack.erase(it);
        std::cout<<"k="<<k<<", "<<"t="<<t<<", "<<"i_seq="<<i_seq<<'\n';
        i = k / N;
        j = k % N;
        int dirs[4];
        int n_dirs;
        n_dirs = 0;
        if (i > 0) {
            dirs[n_dirs++] = k - N;
        }
        if (i + 1 < N) {
            dirs[n_dirs++] = k + N;
        }
        if (j > 0) {
            dirs[n_dirs++] = k - 1;
        }
        if (j + 1 < N) {
            dirs[n_dirs++] = k + 1;
        }
        for (int  i_dir = 0; i_dir<n_dirs; i_dir++) {
            int t2;
            t2 = t + T;
            i_seq_next = (i_seq + 1) % 3;
            if (i_seq_next == 0) {
                t2 += grid[dirs[i_dir]];
            }
            if (costs[i_seq_next][dirs[i_dir]] == -1 || costs[i_seq_next][dirs[i_dir]] > t2) {
                costs[i_seq_next][dirs[i_dir]] = t2;
                stack.insert({t2, {dirs[i_dir], i_seq_next}});
            }
        }
    }
    n_min = costs[0][N * N - 1];
    if (n_min > costs[1][N * N - 1]) {
        n_min = costs[1][N * N - 1];
    }
    if (n_min > costs[2][N * N - 1]) {
        n_min = costs[2][N * N - 1];
    }
    FILE* Out = fopen("visitfj.out", "w");
    fprintf(Out, "%d\n", n_min);
    fclose(Out);
    return 0;
}
