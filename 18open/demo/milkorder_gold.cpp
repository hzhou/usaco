#include <vector>
#include <unordered_set>
#include <cstdio>
#include <set>
#include <iostream>
#include <cstdio>
#include <algorithm>

int find_k();
int check_cycle(int k);

int N;
int M;
std::vector<int> *order_list;

int main(int argc, char** argv)
{
    int k;
    int n_edges;
    int i1;
    int i2;
    int i;

    FILE* In = fopen("milkorder.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    fscanf(In, " %d %d" ,&N,&M);
    order_list = new std::vector < int > [M];
    for (int  i = 0; i<M; i++) {
        int m;
        fscanf(In, " %d" ,&m);
        for (int  j = 0; j<m; j++) {
            int t;
            fscanf(In, " %d" ,&t);
            order_list[i].push_back(t - 1);
        }
    }
    fclose(In);
    k = find_k();
    std::cout<<"k="<<k<<'\n';
    int L[N];
    int dep_counts[N];
    for (int  i = 0; i<N; i++) {
        dep_counts[i] = 0;
    }
    std::unordered_set<int> followers[N];
    n_edges = 0;
    for (int  i = 0; i<k; i++) {
        for (int  j = 0; j<order_list[i].size()-1; j++) {
            i1 = order_list[i][j];
            i2 = order_list[i][j + 1];
            dep_counts[i2]++;
            followers[i1].insert(i2);
            n_edges++;
        }
    }
    std::set<int> stack;
    for (int  i = 0; i<N; i++) {
        if (dep_counts[i] == 0) {
            stack.insert(i);
        }
    }
    int *p = L;
    while (stack.size() > 0) {
        auto it = stack.begin();
        i = *it;
        stack.erase(it);
        *p = i + 1;
        p++;
        for(auto j : followers[i]){
            dep_counts[j]--;
            if (dep_counts[j] == 0) {
                stack.insert(j);
            }
            n_edges--;
        }
    }
    FILE* Out = fopen("milkorder.out", "w");
    for (int  i = 0; i<N-1; i++) {
        fprintf(Out, "%d ", L[i]);
    }
    fprintf(Out, "%d\n", L[N-1]);
    fclose(Out);
    return 0;
}

int find_k()
{
    int i1;
    int i2;
    int i3;

    i1 = 1;
    i2 = M;
    while (i1 <= i2) {
        i3 = (i1 + i2) / 2;
        if (check_cycle(i3)) {
            i2 = i3 - 1;
        } else {
            i1 = i3 + 1;
        }
    }
    return i2;
}

int check_cycle(int k)
{
    int n_edges;
    int i1;
    int i2;
    int i;

    int dep_counts[N];
    for (int  i = 0; i<N; i++) {
        dep_counts[i] = 0;
    }
    std::unordered_set<int> followers[N];
    n_edges = 0;
    for (int  i = 0; i<k; i++) {
        for (int  j = 0; j<order_list[i].size()-1; j++) {
            i1 = order_list[i][j];
            i2 = order_list[i][j + 1];
            dep_counts[i2]++;
            followers[i1].insert(i2);
            n_edges++;
        }
    }
    std::vector<int> stack;
    for (int  i = 0; i<N; i++) {
        if (dep_counts[i] == 0) {
            stack.push_back(i);
        }
    }
    while (stack.size() > 0) {
        i = stack.back();
        stack.pop_back();
        for(auto j : followers[i]){
            dep_counts[j]--;
            if (dep_counts[j] == 0) {
                stack.push_back(j);
            }
            n_edges--;
        }
    }
    if (n_edges > 0) {
        return 1;
    } else {
        return 0;
    }
}
