#include <vector>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <deque>
#include <cstdio>
#include <cassert>
#include <algorithm>

int N;
int *A;
int *B;

int main(int argc, char** argv)
{
    int n_ret;
    std::vector<int> *adj_list;
    int count;
    std::deque<int> queue;
    int *cache;
    int i;
    int n_children;
    int k;
    int n;

    n_ret = scanf(" %d" ,&N);
    assert(n_ret > 0);
    A=(int*)malloc(N*sizeof(int));
    B=(int*)malloc(N*sizeof(int));
    for (int  i = 0; i<N-1; i++) {
        n_ret = scanf(" %d %d" ,&A[i],&B[i]);
        assert(n_ret > 0);
        A[i]--;
        B[i]--;
    }

    adj_list=(std::vector<int>*)malloc(N*sizeof(std::vector<int>));
    for (int  i = 0; i<N-1; i++) {
        adj_list[A[i]].push_back(B[i]);
        adj_list[B[i]].push_back(A[i]);
    }

    count = 0;

    cache=(int*)calloc(N, sizeof(int));

    queue.push_back(0);
    cache[0] = 1;
    int parent = -1;
    while (!queue.empty()) {
        i = queue.front();
        queue.pop_front();
        n_children = adj_list[i].size();
        for (int  j = 0; j<n_children; j++) {
            if (!cache[adj_list[i][j]]) {
                queue.push_back(adj_list[i][j]);
                cache[adj_list[i][j]] = 1;
            }
        }
        if (i > 0) {
            n_children--;
        }
        if (n_children > 0) {
            k = 0;
            n = 1;
            while (n <= n_children) {
                k++;
                n *= 2;
            }
            count += k + n_children;
        }
        parent = i;
    }

    printf("%d\n", count);
    return 0;
}
