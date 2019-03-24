#include <vector>
#include <cstdio>
#include <cstdio>
#include <algorithm>

int bin_search(std::pair<int,int> *L, int n, int k);

int main(int argc, char** argv)
{
    int n;
    int i;
    int i_e;
    int j;
    int n_up;
    bool is_needed;

    FILE* In = fopen("atlarge.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    int K;
    fscanf(In, " %d %d" ,&N,&K);
    K--;
    n = N - 1;
    std::pair<int,int> Edges[n*2];
    for (int  i = 0; i<N-1; i++) {
        int i_a;
        int i_b;
        fscanf(In, " %d %d" ,&i_a,&i_b);
        i_a--;
        i_b--;
        Edges[i].first = i_a;
        Edges[i].second = i_b;
        Edges[i+n].first = i_b;
        Edges[i+n].second = i_a;
    }
    fclose(In);
    std::sort(Edges, Edges + n * 2);
    int Levels[N];
    for (int  i = 0; i<N; i++) {
        Levels[i] = -1;
    }
    int pointers[N];
    for (int  i = 0; i<N; i++) {
        pointers[i] = i;
    }
    std::vector<int> leaf_nodes;
    std::vector<int> stack;
    stack.push_back(K);
    Levels[K] = 0;
    while (stack.size() > 0) {
        i = stack.back();
        stack.pop_back();
        i_e = bin_search(Edges, n * 2, i);
        int count = 0;
        while (i_e<n*2 && Edges[i_e].first == i) {
            j = Edges[i_e].second;
            if (Levels[j] == -1) {
                Levels[j] = Levels[i] + 1;
                pointers[j] = i;
                stack.push_back(j);
                count++;
            }
            i_e++;
        }
        if (count == 0) {
            leaf_nodes.push_back(i);
        }
    }
    for (int  i = 0; i<leaf_nodes.size(); i++) {
        n_up = Levels[leaf_nodes[i]] / 2;
        for (int  j = 0; j<n_up; j++) {
            leaf_nodes[i] = pointers[leaf_nodes[i]];
        }
    }
    int Guarded[N];
    for (int  i = 0; i<N; i++) {
        Guarded[i] = 0;
    }
    for (int  i = 0; i<leaf_nodes.size(); i++) {
        Guarded[leaf_nodes[i]] = 1;
    }
    int count = 0;
    for (int  i = 0; i<leaf_nodes.size(); i++) {
        j = leaf_nodes[i];
        if (Guarded[j] == 2) {
            continue;
        } else {
            Guarded[j] = 2;
        }
        is_needed = true;
        while (j != K) {
            j = pointers[j];
            if (Guarded[j]) {
                is_needed = false;
                break;
            }
        }
        if (is_needed) {
            count++;
        }
    }
    FILE* Out = fopen("atlarge.out", "w");
    fprintf(Out, "%d\n", count);
    fclose(Out);
    return 0;
}

int bin_search(std::pair<int,int> *L, int n, int k)
{
    int i1;
    int i2;
    int i3;

    i1 = 0;
    i2 = n - 1;
    if (k < L[i1].first) {
        return -1;
    }
    if (k > L[i2].first) {
        return -1;
    }
    while (i1 <= i2) {
        i3 = (i1 + i2) / 2;
        if (L[i3].first < k) {
            i1 = i3 + 1;
        } else {
            i2 = i3 - 1;
        }
    }
    return i1;
}
