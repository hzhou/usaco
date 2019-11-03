//Harry Zhou
//11-2-2019
//1hr 10min
//Only about 10 minutes was actually spent coding. The rest was spent trying to figure out the problem.
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

int N;
int BIT[100001];

int sum(int idx) {
    int sum=0;
    idx++;
    while (idx>0) {
        sum += BIT[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

void update(int idx, int val) {
    idx++;
    while (idx<=N) {
        BIT[idx] += val;
        idx += idx & (-idx);
    }
}

int main() {
    std::ifstream fin;
    fin.open("sort.in");
    std::ofstream fout;
    fout.open("sort.out");

    fin >> N;
    int *A = new int[N];
    for (int i=0; i<N; i++) {
        fin >> A[i];
    }

    int *P = new int[N];
    for (int i=0; i<N; i++) P[i]=i;
    std::sort(P, P+N, [A](int a, int b){return A[a]<A[b] || (A[a]==A[b] && a<b);});

    int max = 1;
    for (int i=0; i<N-1; i++) {
        update(P[i], 1);
        int s = (i+1)-sum(i);
        max = std::max(max, s);
    }

    cout << max;
    fout << max;
}
