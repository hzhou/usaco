//Harry Zhou
//1 hour 40 minutes
//9-21-2019
//Issue #1: small mistake in drawing minimum spanning tree
//Issue #2: didn't use long long ints
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

using std::cout;
using std::endl;
using std::make_pair;

using std::pair;
using std::set;
using std::map;
using std::vector;
using std::stack;
using std::priority_queue;

typedef long long int LL;

typedef pair<int,int> ipair;
typedef set<int> iset;
typedef map<int,int> imap;
typedef vector<int> ivec;
typedef stack<int> istack;
typedef priority_queue<ipair, std::vector<ipair>, std::greater<ipair>> dijkstra_priority_queue;

int main() {
    std::ifstream fin;
    fin.open("shortcut.in");
    std::ofstream fout;
    fout.open("shortcut.out");

    int N, M, T;
    fin >> N >> M >> T;
    int *init_cows = new int[N];
    for (int i=0; i<N; i++) {
        fin >> init_cows[i];
    }
    vector<ipair> *graph = new vector<ipair>[N];
    for (int i=0; i<M; i++) {
        int a, b, t;
        fin >> a >> b >> t;
        a--; b--;
        graph[a].push_back(make_pair(b,t));
        graph[b].push_back(make_pair(a,t));
    }

    for (int i=0; i<N; i++) {
        std::sort(graph[i].begin(), graph[i].end());
    }
    
    dijkstra_priority_queue pq;
    int *dist = new int[N];
    for (int i=0; i<N; i++) {dist[i] = INT_MAX;}
    dist[0] = 0;
    pq.push(std::make_pair(dist[0], 0));
    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();

        for (auto edge : graph[v]) {
            int neighbor = edge.first;
            int weight = edge.second;
            if (dist[neighbor] > dist[v]+weight) {
                dist[neighbor] = dist[v]+weight;
                pq.push(make_pair(dist[neighbor], neighbor));
            }
        }
    }

    /*for (int i=0; i<N; i++) {
        cout << dist[i] << " ";
    } cout << endl;*/

    int *path = new int[N];
    path[0] = 0;
    for (int i=1; i<N; i++) {
        int minDist = INT_MAX;
        for (auto edge : graph[i]) {
            int d = dist[edge.first] + edge.second;
            if (d<minDist) {
                minDist = d;
                path[i] = edge.first;
            }
        }
    }

    /*for (int i=0; i<N; i++) {
        cout << path[i] << " ";
    } cout << endl;*/

    int *access_order = new int[N];
    for (int i=0; i<N; i++) {
        access_order[i] = i;
    }
    std::sort(access_order, access_order+N, [dist](int a, int b){return dist[a]>dist[b];});    

    int *total_cows = new int[N];
    for (int i=0; i<N; i++) {
        total_cows[i] = init_cows[i];
    }
    for (int i=0; i<N-1; i++) {
        int v = access_order[i];
        total_cows[path[v]] += total_cows[v];
    }

    /*for (int i=0; i<N; i++) {
        cout << total_cows[i] << " ";
    } cout << endl;*/

    LL res = 0;
    for (int i=1; i<N; i++) {
        LL distChange = dist[i] - T;
        res = std::max(res, distChange*total_cows[i]);
    }
    cout << res << endl;
    fout << res << endl;
}
