#include <vector>
#include <cstdio>
#include <cstdio>
#include <algorithm>
using namespace std;

struct rel {
    int i;
    int r;
};

int get_adj(vector<rel> *Adj, int i, int K, vector<int>& cache);

int N;
int Q;

int main(int argc, char** argv)
{
    FILE* In = fopen("mootube.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d" ,&N,&Q);
    int A[N-1];
    int B[N-1];
    int R[N-1];
    for (int  i = 0; i<N-1; i++) {
        fscanf(In, " %d %d %d" ,&A[i],&B[i],&R[i]);
        A[i]--;
        B[i]--;
    }
    int V[Q];
    int K[Q];
    for (int  i = 0; i<Q; i++) {
        fscanf(In, " %d %d" ,&K[i],&V[i]);
        V[i]--;
    }
    fclose(In);
    vector<rel> Adj[N];
    for (int  i = 0; i<N-1; i++) {
        Adj[A[i]].push_back({B[i], R[i]});
        Adj[B[i]].push_back({A[i], R[i]});
    }
    int Ans[Q];
    for (int  i = 0; i<Q; i++) {
        vector<int> cache;
        cache.resize(N, 0);
        Ans[i] = get_adj(Adj, V[i], K[i], cache) - 1;
    }
    FILE* Out = fopen("mootube.out", "w");
    for (int  i = 0; i<Q; i++) {
        fprintf(Out, "%d\n", Ans[i]);
    }
    fclose(Out);
    return 0;
}

int get_adj(vector<rel> *Adj, int i, int K, vector<int>& cache)
{
    int k;

    cache[i] = 1;
    int cnt = 1;
    for (int  j = 0; j<Adj[i].size(); j++) {
        k = Adj[i][j].i;
        if (cache[k] == 0 && Adj[i][j].r >= K) {
            cnt += get_adj(Adj, k, K, cache);
        }
    }
    return cnt;
}
