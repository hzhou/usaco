//Jasmine Zhang
//2 hours
//9/11 cases passed 
#include <cstdio>
#include <cstdlib>
#include <map>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

void dijkstra (vector <int> neighbours[], long long dist [], long long pCount[], int cows []);
void updateParent (int parents [], long long pCount [], int cows [], int p, int c);
int N, M, T;
map <pair <int, int>, int> edgewt;

int main () {
    FILE * In = fopen("shortcut.in", "r");
    
    fscanf(In, "%d %d %d", &N, &M, &T);

    int cows [N];
    for (int i = 0; i < N; i++) 
        fscanf(In, "%d", &cows[i]);

    vector <int> neighbours [N];
    for (int i = 0; i < M; i++) {
        int a, b, t;
        fscanf(In, "%d %d %d", &a, &b, &t);
        a--; 
        b--;
        edgewt[make_pair(a,b)] = t;
        edgewt[make_pair(b,a)] = t;
        neighbours[a].push_back(b);
        neighbours[b].push_back(a);
    }

    long long dist [N];
    long long pCount [N]; 
    fill_n(pCount, N, 0);
    dijkstra(neighbours, dist, pCount, cows);
    /* 
    for (int i = 0; i < N; i++) {
        cout << dist [i] << " " << pCount[i] << "\n";
    }
    */

    long long saved [N]; 
    for (int i = 0; i < N; i++) {
        saved[i] = (pCount[i]+cows[i])*(dist[i]-T);
        //cout << saved[i] << "\n";
    }

    sort(saved, saved + N);
    //cout << saved[0] << "\n";
    //cout << saved[N-1] << "\n";

    FILE * Out = fopen("shortcut.out", "w");
    fprintf(Out, "%lld\n", saved[N-1]);
    return 0;
}

void dijkstra (vector <int> neighbours[], long long dist [], long long pCount[], int cows []) {
    priority_queue <pair <int,int>, vector<pair<int,int> >, greater<pair<int, int> > > pq; 
    int parents [N];
    fill_n(dist, N, -1);
    fill_n(parents, N, -1);
    dist[0] = 0;
    parents[0] = 0;

    pq.push(make_pair(0, 0));

    while (!pq.empty()) {
        pair <int, int> p = pq.top();
        pq.pop();
        long long time = p.first;
        int field = p.second;
        //cout << time << "+" << field << "\n";
        for (int n : neighbours[field]) {
            pair <int, int> edge = make_pair(field,n); 
            long long totalTime = time + edgewt[edge];
            if (dist[n] == -1 || totalTime < dist[n] ||
                (totalTime == dist[n] && parents[n] > field)) {
                updateParent (parents, pCount, cows, field, n);
                dist[n] = totalTime;
                pq.push(make_pair(totalTime, n));
            }
            
        }
    }
}

void updateParent (int parents [], long long pCount [], int cows [], int p, int c) {
    //cout << p << "-" << c << "\n";
    int oldParent = parents[c];
    long long nCows = cows[c];
    if (oldParent != -1) {
        while (oldParent != 0) {
            pCount[oldParent]-= nCows;
            oldParent = parents[oldParent];
        }
    }
    parents[c] = p;
    while (p != 0) {
        pCount[p]+=nCows;
        p = parents[p];
    }
}