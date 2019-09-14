//Harry Zhou
//9-14-2019
//1hr 10min
//-
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

typedef std::pair<int,int> ipair;
typedef std::set<int> iset;
typedef std::map<int,int> imap;
typedef std::vector<int> ivec;
typedef std::stack<int> istack;
typedef std::priority_queue<ipair, std::vector<ipair>, std::greater<ipair>> dijkstra_priority_queue;

struct node {
    ivec edges;
    ivec weights;
};

int main() {
    FILE *fin = fopen("dining.in", "r");
    FILE *fout = fopen("dining.out", "w");

    int N, M, K;
    fscanf(fin, "%d %d %d", &N, &M, &K);

    node *nodes = new node[N];
    for (int i=0; i<M; i++) {
        int a, b, t;
        fscanf(fin, "%d %d %d", &a, &b, &t);
        a--; b--;
        nodes[a].edges.push_back(b);
        nodes[a].weights.push_back(t);
        nodes[b].edges.push_back(a);
        nodes[b].weights.push_back(t);
    }

    ipair * haybales = new ipair[K];
    for (int i=0; i<K; i++) {
        int idx, yum;
        fscanf(fin, "%d %d", &idx, &yum);
        idx--;
        haybales[i] = std::make_pair(idx, yum);
    }

   dijkstra_priority_queue pq;
   int *barn_dist = new int[N];
   for (int i=0; i<N; i++) {barn_dist[i] = INT_MAX;}
   barn_dist[N-1] = 0;
   pq.push(std::make_pair(barn_dist[N-1], N-1));
   while (!pq.empty()) {
       int node = pq.top().second;
       pq.pop();

       for (int i=0; i<nodes[node].edges.size(); i++) {
           int neighbor = nodes[node].edges[i];
           int weight = nodes[node].weights[i];
           if (barn_dist[neighbor] > barn_dist[node]+weight) {
               barn_dist[neighbor] = barn_dist[node]+weight;
               pq.push(std::make_pair(barn_dist[neighbor], neighbor));
           }
       }
   }

   int *bale_dist = new int[N];
   for (int i=0; i<N; i++) {bale_dist[i] = INT_MAX;}
   for (int i=0; i<K; i++) {
       int idx = haybales[i].first;
       int yum = haybales[i].second;
       int cost = barn_dist[idx] - yum;
       bale_dist[idx] = cost;
       pq.push(std::make_pair(bale_dist[idx], idx));
   }
   while (!pq.empty()) {
       int node = pq.top().second;
       pq.pop();

       for (int i=0; i<nodes[node].edges.size(); i++) {
           int neighbor = nodes[node].edges[i];
           int weight = nodes[node].weights[i];
           if (bale_dist[neighbor] > bale_dist[node]+weight) {
               bale_dist[neighbor] = bale_dist[node]+weight;
               pq.push(std::make_pair(bale_dist[neighbor], neighbor));
           }
       }
   }

   for (int i=0; i<N-1; i++) {
       int out = bale_dist[i] <= barn_dist[i] ? 1 : 0;
       printf("%d\n", out);
       fprintf(fout, "%d\n", out);
   }
}
