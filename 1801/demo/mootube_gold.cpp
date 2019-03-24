#include <cstdio>
#include <cstdio>
#include <algorithm>

int find_root(int i);

int *pointers;

int main(int argc, char** argv)
{
    int i_edge_start;
    int n_edges;
    int i_q;
    int i;
    int i_a;
    int i_b;

    FILE* In = fopen("mootube.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    int Q;
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
    int P[Q];
    for (int  i = 0; i<Q; i++) {
        P[i] = i;
    }
    std::sort(P, P+Q, [&](int a, int b){
        return K[a] > K[b];
    } );
    int E[N-1];
    for (int  i = 0; i<N-1; i++) {
        E[i] = i;
    }
    std::sort(E, E+N-1, [&](int a, int b){
        return R[a] > R[b];
    } );
    i_edge_start = 0;
    n_edges = N - 1;
    int region_sizes[N];
    for (int  i = 0; i<N; i++) {
        region_sizes[i] = 1;
    }
    pointers = new int[N];
    for (int  i = 0; i<N; i++) {
        pointers[i] = i;
    }
    int Ans[Q];
    for (int  i_q2 = 0; i_q2<Q; i_q2++) {
        i_q = P[i_q2];
        while (i_edge_start < n_edges) {
            i = E[i_edge_start];
            if (R[i] >= K[i_q]) {
                i_a = find_root(A[i]);
                i_b = find_root(B[i]);
                region_sizes[i_a] += region_sizes[i_b];
                pointers[i_b] = i_a;
                i_edge_start++;
            } else {
                break;
            }
        }
        Ans[i_q] = region_sizes[find_root(V[i_q])] - 1;
    }
    FILE* Out = fopen("mootube.out", "w");
    for (int  i_q = 0; i_q<Q; i_q++) {
        fprintf(Out, "%d\n", Ans[i_q]);
    }
    fclose(Out);
    return 0;
}

int find_root(int i)
{
    while (pointers[i] != i) {
        i = pointers[i];
    }
    return i;
}
