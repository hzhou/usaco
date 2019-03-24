#include <vector>
#include <cstdio>
#include <set>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

using namespace std;
struct edge {
	int a;
	int b;
	int t;
};

struct hay {
	int i;
	int bonus;
};

struct edge2 {
	int b;
	int t;
};


int main(int argc, char** argv)
{
    set<pair<int, int> > stack;
    int i;

    FILE* In = fopen("dining.in", "r");
    if (!In) {
        fprintf(stderr, "Can't open In\n");
        exit(-1);
    }
    int N;
    int M;
    int K;
    fscanf(In, " %d %d %d" ,&N,&M,&K);
    std::cout<<"N="<<N<<", "<<"M="<<M<<", "<<"K="<<K<<'\n';
    struct edge edge_list[M];
    for (int  i = 0; i<M; i++) {
        int a;
        int b;
        int t;
        fscanf(In, " %d %d %d" ,&a,&b,&t);
        edge_list[i] = {a - 1, b - 1, t};
    }
    struct hay hay_list[K];
    for (int  i = 0; i<K; i++) {
        int a;
        int t;
        fscanf(In, " %d %d" ,&a,&t);
        hay_list[i] = {a - 1, t};
    }
    fclose(In);
    std::vector<struct edge2> edge2_list[N];
    for (int  i = 0; i<M; i++) {
        edge2_list[edge_list[i].a].push_back((struct edge2) {edge_list[i].b, edge_list[i].t});
        edge2_list[edge_list[i].b].push_back((struct edge2) {edge_list[i].a, edge_list[i].t});
    }
    int dist[N];
    for (int  i = 0; i<N; i++) {
        dist[i] = 1000000000;
    }
    dist[N-1] = 0;
    stack.insert(make_pair(dist[N-1], N - 1));
    while (!stack.empty()) {
        i = stack.begin()->second;
        stack.erase(stack.begin());
        for(auto e : edge2_list[i]){
            if (dist[e.b] > dist[i] + e.t && e.b < N - 1) {
                dist[e.b] = dist[i] + e.t;
                stack.insert(make_pair(dist[e.b], e.b));
            }
        }
    }
    bool has_neg = false;
    edge2_list[N-1].clear();
    for (int  i = 0; i<K; i++) {
        if (dist[hay_list[i].i] * 2 - hay_list[i].bonus < 0) {
            has_neg = true;
            break;
        }
        edge2_list[N-1].push_back((struct edge2) {hay_list[i].i, dist[hay_list[i].i] - hay_list[i].bonus});
    }
    if (has_neg) {
        FILE* Out = fopen("dining.out", "w");
        for (int  i = 0; i<N-1; i++) {
            fprintf(Out, "1\n");
        }
        fclose(Out);
    } else {
        int dist2[N];
        for (int  i = 0; i<N; i++) {
            dist2[i] = 1000000000;
        }
        dist2[N-1] = 0;
        stack.insert(make_pair(dist2[N-1], N - 1));
        while (!stack.empty()) {
            i = stack.begin()->second;
            stack.erase(stack.begin());
            for(auto e : edge2_list[i]){
                if (dist2[e.b] > dist2[i] + e.t && e.b < N - 1) {
                    dist2[e.b] = dist2[i] + e.t;
                    stack.insert(make_pair(dist2[e.b], e.b));
                }
            }
        }
        FILE* Out = fopen("dining.out", "w");
        for (int  i = 0; i<N-1; i++) {
            fprintf(Out, "%d\n", dist2[i] <= dist[i]);
        }
        fclose(Out);
    }
    return 0;
}
