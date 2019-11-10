//Jasmine Zhang
//2.5 hours
//1/10 cases passed

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <map>


using namespace std;

int findParent (int i, int p []);

int main () {
    FILE * In = fopen("moocast.in", "r");
    int N;
    fscanf(In, "%d", &N);

    int coord [N][2];
    int parent [N];
    for (int i = 0; i < N; i++) {
        fscanf(In, "%d %d", &coord[i][0], &coord[i][1]);
        parent[i] = -1;
    }
    //parent[0] = 0;
    
    
    unordered_set <int> adj [N];
    priority_queue <pair <int,int>, vector<pair<int,int> >, greater<pair<int, int> > > pq;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            adj[i].insert(j);
            adj[j].insert(i);
            int dist = (coord[i][0]-coord[j][0])*(coord[i][0]-coord[j][0]) + (coord[i][1]-coord[j][1])*(coord[i][1]-coord[j][1]);
            //cout << dist << "\n";
            pq.push(make_pair(dist, i*1000+j));
        }
    }

    int minDist = -1;
    map <int, int> subtrees; //parent, num of nodes
    while(!pq.empty()) {
        pair <int, int> p = pq.top();
        pq.pop();
        int dist = p.first;
        int i = p.second/1000;
        int j = p.second%1000;
        //cout << dist << "\n";
        //cout << i << " " << j << "\n";
        //i should always be < j
        parent[i] = findParent(i, parent);
        parent[j] = findParent(j, parent);
        if (parent[i] != -1 && parent[j] == parent[i])
            continue;
        else if (parent[i] == -1){
            subtrees[i] = 2;
            parent[j] = i;
            parent[i] = i;
        }
        else {
            subtrees[parent[i]]++;
            parent[j] = parent[i];
        }
        if ( subtrees.find(j) != subtrees.end() ) {
            subtrees[parent[i]]+= subtrees[j]-1;
            subtrees.erase(j);
        }
        //cout << subtrees[parent[i]] << "ss\n";
        if (subtrees[parent[i]] == N) {
            minDist = dist;
            break;
        }


        //first attempt
        //different algorithm, didn't work, don't know why
        //removed the largest distances until one node is outside of the tree
        /*
        adj[i].erase(j);
        adj[j].erase(i);
        if (adj[i].empty() || adj[j].empty()) {
            minDist = dist;
            break;
        }
        */
    }

    FILE * Out = fopen ("moocast.out", "w");
    fprintf(Out, "%d\n", minDist);

    return 0;
}

int findParent (int i, int p []) {
    int current = i;
    //cout << i << "asdf\n";
    while (p[current] != -1 && p[current] != current) {
        current = p[current];
        //cout << current << "\n";
    }
    return p[current];
}