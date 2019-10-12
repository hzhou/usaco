//Harry Zhou
//1hr 15min
//10-12-2019
//Did this problem before, but tried a slightly different method than before.
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
    fin.open("piepie.in");
    std::ofstream fout;
    fout.open("piepie.out");

    int N, D;
    fin >> N >> D;

    ipair *pies = new ipair[2*N];
    for (int i=0; i<N; i++) {
        fin >> pies[i].second >> pies[i].first;
    }
    for (int i=N; i<2*N; i++) {
        fin >> pies[i].first >> pies[i].second;
    }

    int *spies = new int[2*N];
    for (int i=0; i<2*N; i++) {spies[i]=i;}
    std::sort(spies, spies+N, [pies](int a, int b){return pies[a]<pies[b];});
    std::sort(spies+N, spies+2*N, [pies](int a, int b){return pies[a]<pies[b];});
    
    /*for (int i=0; i<2*N; i++) {
        cout << pies[spies[i]].first << " " << pies[spies[i]].second << endl;
    } cout << endl;*/

    int *dist = new int[2*N];
    for (int i=0; i<2*N; i++) {dist[i]=-1;}

    int *q = new int[2*N];
    int q_beg = 0;
    int q_end = 0;
    for (int i=0; i<2*N; i++) {
        if (pies[i].first == 0) {
            dist[i] = 1;
            q[q_end++] = i;
        }
    }

    while (q_beg < q_end) {
        int pie = q[q_beg++];
        int d = dist[pie];
        int myTaste = pies[pie].second;
        int p_beg, p_end;
        if (pie<N) {
            p_beg = N;
            p_end = 2*N;
        }
        else {
            p_beg = 0;
            p_end = N;
        }
        int *lb = std::lower_bound(spies+p_beg, spies+p_end, myTaste-D, [pies](int a, int b){return pies[a].first<b;});
        int *ub = std::upper_bound(spies+p_beg, spies+p_end, myTaste  , [pies](int a, int b){return a<pies[b].first;});
        if (ub<lb) {
            exit(0);
        }
        for (int *ptr = lb; ptr < ub; ptr++) {
            int n_pie = *ptr; //index of pie
            if (dist[n_pie] == -1) {
                dist[n_pie] = d+1;
                q[q_end++] = n_pie;
            }
        }
    }

    for (int i=0; i<N; i++) {
        cout << dist[i] << endl;
        fout << dist[i] << endl;
    }
}
