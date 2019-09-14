//Jasmine Zhang
//All cases pased
//9/13/18
//2 hours 30 minutes
//Not familiar with c++ 
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;
int N, M, K;
map <pair <int,int>, int> edgewt;
void dijkstra (vector <int> neighbors [], int dist [], int dest) {
    //pops out minimum value instead of max
    priority_queue <pair <int,int>, vector<pair<int,int> >, greater<pair<int, int> > > pq; 
    //have to use the long std instead of INT_MAX, changed to -1
    fill_n(dist, N, -1);
    //ordered by first element
    pq.push(make_pair(0, dest));
    dist[dest] = 0;

    while (!pq.empty()) {
        pair <int,int> p = pq.top();
        pq.pop();
        int cost = p.first;
        int node = p.second;
        //if (visited.find(node) == visited.end)
            //continue;
        for (int n : neighbors[node]) {
            pair <int, int> edge = make_pair(node,n);
            int weight = edgewt[edge];
            int newDist = dist[node] + weight;
            //cout << dist[node] << " " << node << "\n";
            if (dist[n] == -1 || dist[n] > newDist) {
                dist[n] = newDist;
                //cout << n << "-" << dist[n] << "\n";
                pq.push(make_pair(dist[n], n));
            }
        }
        //visited.
        //(node);
        
        
        
    }

    //return dist;
}

int main () {
    FILE * In = fopen("dining.in", "r");
    fscanf(In, "%d %d %d", &N, &M, &K);
    //array of vectors
    vector <int> neighbours [N+1];

    for (int i = 0; i < M; i++) {
        int a, b, t;
        fscanf(In, "%d %d %d", &a, &b, &t);
        a--; 
        b--;
        neighbours[a].push_back(b);
        neighbours[b].push_back(a);
        edgewt[make_pair(a,b)] = t;
        edgewt[make_pair(b,a)] = t;
    }
    int origDist [N];
    dijkstra(neighbours, origDist, N-1);
    for (int i = 0; i < N; i++) {
            cout << origDist[i] << " ";
        }
    cout << "\n";

    for (int i = 0; i < K; i++) {
        int in, y;
        fscanf(In, "%d %d", &in, &y);
        in--; //bug that took 30 minutes to finds :(s
        //must go through pastures with haybale for new distances, 
        //create extra node as source that only links to pastures with haybale
        edgewt[make_pair(N,in)] = origDist[in]-y;
        neighbours[N].push_back(in);
        
    } 
    int newDist [N+1];
    //shortest distance from new node
    dijkstra(neighbours, newDist, N);

    for (int i = 0; i < N; i++) {
            cout << newDist[i] << " ";
        }
    cout << "\n";

    FILE * Out = fopen ("dining.out", "w");
    for (int i = 0; i < N-1; i++) {
        if (newDist[i] <= origDist[i]) 
            fprintf(Out, "%d\n", 1);
        else
            fprintf(Out, "%d\n", 0);
            
    }
    return 0;
}