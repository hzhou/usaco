//Harry Zhou
//1hr 30min
//10-12-2019
//Took a while to realize that iterating up from the leaf nodes is not topological ordering
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

#define MOD 1000000007

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

int ladd(LL a, LL b) {
    return (int) ((a+b) % MOD);
}

int lmul(LL a, LL b) {
    return (int) (a*b % MOD);
}

int main() {
    std::ifstream fin;
    fin.open("barnpainting.in");
    std::ofstream fout;
    fout.open("barnpainting.out");

    int N, K;
    fin >> N >> K;
    ivec *graph = new ivec[N];
    for (int i=0; i<N-1; i++) {
        int a, b;
        fin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int *fc = new int[N];
    for (int i=0; i<N; i++) {fc[i] = 0;}
    for (int i=0; i<K; i++) {
        int b, c;
        fin >> b >> c;
        b--;
        fc[b] = c;
    }

    int *tree = new int[N];
    for (int i=0; i<N; i++) {tree[i]=-1;}
    istack stk;
    tree[0] = 0;
    stk.push(0);
    while (!stk.empty()) {
        int v = stk.top();
        stk.pop();
        for (auto itr = graph[v].begin(); itr!= graph[v].end(); itr++) {
            if (tree[*itr] == -1) {
                tree[*itr] = v;
                stk.push(*itr);
            }
        }
    }

    int *c1 = new int[N];
    int *c2 = new int[N];
    int *c3 = new int[N];
    for (int i=0; i<N; i++) {
        c1[i] = 1;
        c2[i] = 1;
        c3[i] = 1;
    }

    istack ord_stk;

    int *visited = new int[N];
    for (int i=0; i<N; i++) {visited[i]=0;}

    for (int i=0; i<N; i++) {
        if (visited[i]) {continue;}
        visited[i] = 1;
        stk.push(i);
        while (!stk.empty()) {
            int n = stk.top();
            if (!visited[tree[n]]) {
                visited[tree[n]] = 1;
                stk.push(tree[n]);
            }
            else {
                ord_stk.push(n);
                stk.pop();
            }
        }
    }

    while (!ord_stk.empty()) {
        int node = ord_stk.top();
        ord_stk.pop();
        int parent = tree[node];
        if (fc[node] == 1) {
            c2[node] = 0;
            c3[node] = 0;
        }
        else if (fc[node] == 2) {
            c1[node] = 0;
            c3[node] = 0;
        }
        else if (fc[node] == 3) {
            c1[node] = 0;
            c2[node] = 0;
        }

        if (node == 0) {break;}

        c1[parent] = lmul( c1[parent] , ladd(c2[node],c3[node]) );
        c2[parent] = lmul( c2[parent] , ladd(c1[node],c3[node]) );
        c3[parent] = lmul( c3[parent] , ladd(c1[node],c2[node]) );
    }

    int ans = ladd( ladd(c1[0],c2[0]) , c3[0] );
    cout << ans << endl;
    fout << ans << endl;
}
