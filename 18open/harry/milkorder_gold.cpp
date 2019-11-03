//Harry Zhou
//11-2-2019
//1hr 30min
//Spent a while debugging
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
    fin.open("milkorder.in");
    std::ofstream fout;
    fout.open("milkorder.out");

    int N, M;
    fin >> N >> M;

    vector<ipair> edges;
    ivec edge_ranks;
    for (int i=0; i<M; i++) {
        int m_i;
        fin >> m_i;
        int prev;
        int next;
        fin >> prev;
        prev--;
        for (int j=1; j<m_i; j++) {
            fin >> next;
            next--;
            edges.push_back(make_pair(prev, next));
            edge_ranks.push_back(i);
            prev = next;
        }
    }

    int *in_list = new int[N];
    for (int i=0; i<N; i++) in_list[i] = 0;
    std::multiset<int> *graph = new std::multiset<int>[N];
    for (ipair edge : edges) {
        graph[edge.first].insert(edge.second);
        in_list[edge.second]++;
    }

    iset active_nodes;
    istack sources;
    for (int i=0; i<N; i++) {
        active_nodes.insert(i);
        if (in_list[i] == 0) {
            sources.push(i);
        }
    }

    while (!sources.empty()) {
        int source = sources.top();
        sources.pop();
        for (int n : graph[source]) {
            in_list[n]--;
            if (in_list[n] == 0) {
                sources.push(n);
            }
        }
        active_nodes.erase(source);
    }

    int stop_rank = M;
    if (active_nodes.empty()) {
        goto endTrim;
    }
    for (int i = edges.size()-1; i>=0; i--) {
        ipair edge = edges[i];

        if (!active_nodes.count(edge.first)) {continue;}

        in_list[edge.second]--;
        graph[edge.first].erase(graph[edge.first].find(edge.second));
        if (in_list[edge.second] == 0) {
            sources.push(edge.second);
        }

        while (!sources.empty()) {
            int source = sources.top();
            sources.pop();
            for (int n : graph[source]) {
                in_list[n]--;
                if (in_list[n] == 0) {
                    sources.push(n);
                }
            }
            active_nodes.erase(source);
        }
        
        if (active_nodes.empty()) {
            stop_rank = edge_ranks[i];
            break;
        }
    }
endTrim:

    edge_ranks.push_back(M); //sentinel

    for (int i=0; i<N; i++) in_list[i] = 0;
    ivec *graph2 = new ivec[N];
    for (int i=0; edge_ranks[i]<stop_rank; i++) {
        ipair edge = edges[i];
        graph2[edge.first].push_back(edge.second);
        in_list[edge.second]++;
    }

    priority_queue<int, ivec, std::greater<int>> sources2;
    for (int i=0; i<N; i++) {
        if (in_list[i] == 0) {
            sources2.push(i);
        }
    }

    ivec order;
    while (!sources2.empty()) {
        int source = sources2.top();
        sources2.pop();
        order.push_back(source+1);
        for (int n : graph2[source]) {
            in_list[n]--;
            if (in_list[n] == 0) {
                sources2.push(n);
            }
        }
    }
    for (int i=0; i<order.size()-1; i++) {
        cout << order[i] << " ";
        fout << order[i] << " ";
    }
        cout << order[order.size()-1] << endl;
        fout << order[order.size()-1] << endl;
}
