//Jasmine Zhang
//2 hours
//1/10 cases passed
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int bSearchFirstOccur (pair <int,int> pies [], int taste);
int bSearchLastOccur (pair <int,int> pies [], int taste);
int dijkstra (pair <int,int> bes [], pair <int,int> els [], int i);
int N, D;
int main () {
   
    FILE * In = fopen("piepie.in", "r");
    fscanf(In, "%d %d", &N, &D);
    pair <int, int> besPies [N];
    for (int i = 0; i < N; i++) {
        int a, b;
        fscanf(In, "%d %d", &a, &b);
        besPies[i] = make_pair(a,b);
    }
    sort(besPies, besPies+N); 
    //for (int i = 0; i < N; i++) 
       //cout << besPies[i].first << " " << besPies[i].second << "\n";

    pair <int, int> elsPies [N];
    for (int i = 0; i < N; i++) {
        int a, b;
        fscanf(In, "%d %d", &a, &b);
        elsPies[i] = make_pair(a,b);
    }
    sort(elsPies, elsPies+N); 
    //for (int i = 0; i < N; i++) 
       //cout << elsPies[i].first << " " << elsPies[i].second << "\n";

    FILE * Out = fopen ("piepie.out", "w");
    for (int i = 0; i < N; i++) {
        fprintf(Out, "%d\n", dijkstra(besPies, elsPies, i));
    }
    //cout << bSearchFirstOccur(besPies, 1) << "\n";
    //cout << bSearchLastOccur(besPies, 5);
    return 0;
}
int dijkstra (pair <int,int> bes [], pair <int,int> els [], int start) {
    priority_queue <pair <int,int>, vector<pair<int,int> >, greater<pair<int, int> > > pq; 
    pq.push(make_pair(1,start));
    while (!pq.empty()) {
        pair <int, int> p = pq.top();
        pq.pop();
        int c = p.first;
        int i = p.second;
        //cout << c << " " << i << "\n";
        if ((c % 2 == 1 && bes[i].second == 0) || (c % 2 == 0 && els[i].second == 0))  
            return c;
        else if (c % 2 == 1) {
            int t1 = bes[i].second;
            int t2 = bes[i].second + D;
            int i1 = bSearchFirstOccur(els, t1);
            int i2 = bSearchLastOccur(els, t2);
            for (int j = i1; j <= i2; j++) {
                pq.push(make_pair(c+1, j));
            }
        }
        else {
            int t1 = els[i].second;
            int t2 = els[i].second + D;
            int i1 = bSearchFirstOccur(bes, t1);
            int i2 = bSearchLastOccur(bes, t2);
            for (int j = i1; j <= i2; j++) {
                pq.push(make_pair(c+1, j));
            }
        }
    }
    return -1;
}
int bSearchFirstOccur (pair <int,int> pies [], int taste) {
    int b = 0;
    int e = N-1;
    int m = (b+e)/2;
    while (b <= e) {
        //cout << m << "\n";
        //cout << pies[m].first << "\n";
        int m = (b+e)/2;
        if (pies[m].first == taste && (m == 0 || pies[m-1].first < taste))
            return m;
        else if (pies[m].first < taste) 
            b = m + 1;
        else
            e = m - 1;
    }
    return b;
}

int bSearchLastOccur (pair <int,int> pies [], int taste) {
    int b = 0;
    int e = N-1;
    while (b <= e) {
        int m = (b+e)/2;
        if (pies[m].first == taste && (m == N-1 || pies[m+1].first > taste))
            return m;
        else if (pies[m].first < taste) 
            b = m + 1;
        else
            e = m - 1;
    }
    //cout << b << " " << e << "\n";
    return e;
}

