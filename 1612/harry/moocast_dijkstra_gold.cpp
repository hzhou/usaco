//Harry Zhou
//Misinterpreted problem: thought the cost was equal to the sum of the powers of the devices, rather a fixed cost getting an identical device for each cow.
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <set>
#include <map>
#include <queue>

typedef std::pair<int,int> ipair;
typedef std::set<int> iset;

struct node {
    iset edges;
    int cost;
    int visited;
};

int mta;
int mtb;
int N;
ipair cows[1000];
node graph[1000];
int tdists[1000];

int dist(int a, int b);

int main() {
    FILE *fileIn = fopen("moocast.in", "r");
    FILE *fileOut = fopen("moocast.out", "w");

    fscanf(fileIn, "%d", &N);

    for (int i=0; i<N; i++) {
        int x,y;
        fscanf(fileIn, "%d %d", &x, &y);
        cows[i].first = x;
        cows[i].second = y;
    }

    for (int i=0; i<N; i++) {
        graph[i].cost = INT_MAX;
    }

    std::priority_queue<ipair, std::vector<ipair>, std::greater<ipair>> pq;
    graph[0].cost = 0;
    pq.push(std::make_pair(graph[0].cost, 0));
    while (!pq.empty()) {
        int n = pq.top().second;
        pq.pop();

        if (graph[n].visited) {continue;}
        else {graph[n].visited = 1;}

        for (int i=0; i<N; i++) {
            int cost = std::max(graph[n].cost, dist(n, i));
            if (cost<graph[i].cost) {
                graph[i].cost = cost;
                pq.push(std::make_pair(graph[i].cost, i));
            }
        }
    }

    int maxDist = 0;
    for (int i=1; i<N; i++) {
        maxDist = std::max(maxDist, graph[i].cost);
    }

    printf("%d\n", maxDist);
    fprintf(fileOut, "%d\n", maxDist);
}

int dist(int a, int b) {
    int dx = cows[a].first - cows[b].first;
    int dy = cows[a].second - cows[b].second;
    return dx*dx + dy*dy;
}
