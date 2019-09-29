//Harry Zhou
//9/28/2019
//gave up
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

struct query {
    int type;
    int a;
    int b;
};

int main() {
    std::ifstream fin;
    fin.open("cowland.in");
    std::ofstream fout;
    fout.open("cowland.out");

    int N, Q;
    fin >> N >> Q;

    int *enj_list = new int[N];
    for (int i=0; i<N; i++) {
        fin >> enj_list[i];
    }

    ivec *graph = new ivec[N];
    for (int i=0; i<N-1; i++) {
        int a, b;
        fin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    query * queries = new query[N];
    for (int i=0; i<Q; i++) {
        int t, a, b;
        fin >> t >> a >> b;
        a--;
        if (t==2) b--;
        queries[i] = {t, a, b};
    }

    int *tree = new int[N];
    int *visited = new int[N];
    for (int i=0; i<N; i++) {visited[i]=0;};
    istack stk;
    tree[0] = -1;
    visited[0] = 1;
    stk.push(0);
    while (!stk.empty()) {
        int node = stk.top();
        stk.pop();
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                tree[neighbor] = node;
                visited[neighbor] = 1;
                stk.push(neighbor);
            }
        }
    }

    /*for (int i=0; i<N; i++) {
        cout << tree[i] << " ";
    }
    cout << endl;*/

    ivec top_ord;
    for (int i=0; i<N; i++) {visited[i]=0;};
    for (int i=0; i<N; i++) {
        if (visited[i]) continue;
        visited[i] = 1;
        stk.push(i);
        while (!stk.empty()) {
            int node = stk.top();
            int parent = tree[node];
            if (!(node==0) && !visited[parent]) {
                visited[parent] = 1;
                stk.push(parent);
            }
            else {
                top_ord.push_back(node);
                stk.pop();
            }
        }
    }
    
    int *tot_enj = new int[N];
    for (int node : top_ord) {
        tot_enj[node] = enj_list[node];
        if (node != 0) {
            tot_enj[node] ^= tot_enj[tree[node]];
        }
    }

    /*for (int i=0; i<N; i++) {
        cout << tot_enj[i] << endl;
    }*/

    for (int i=0; i<Q; i++) {
        if (queries[i].type == 1) {
            int node = queries[i].a;
            int new_val = queries[i].b;
            int op = enj_list[node] ^ new_val;
            enj_list[node] = new_val;
            stk.push(node);
            while (!stk.empty()) {
                int n = stk.top();
                stk.pop();
                tot_enj[n] ^= op;
                for (int neighbor : graph[n]) {
                    if (neighbor!=tree[n]) {
                        stk.push(neighbor);
                    }
                }
            }
        }
        else {
            int a = queries[i].a;
            int b = queries[i].b;
            int res = tot_enj[a] ^ tot_enj[b] ^ enj_list[0];
            cout << tot_enj[a] << " " << tot_enj[b] << " " << enj_list[0] << endl;
            cout << res << endl;
            fout << res << endl;
        }
    }
}
