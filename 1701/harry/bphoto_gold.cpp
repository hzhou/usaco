//Harry Zhou
//30 mins
//11-30-2019
//
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
int update(int idx, int val) {
    idx++;
    while (idx<=100000) {
        BIT[idx] += val;
        idx += idx & (-idx);
    }
}

int main() {
    std::ifstream fin;
    fin.open("bphoto.in");
    std::ofstream fout;
    fout.open("bphoto.out");

    int N;
    fin >> N;
    int *L = new int[N];
    for (int i=0; i<N; i++) {
        fin >> L[i];
    }
    int *P = new int[N];
    for (int i=0; i<N; i++) {P[i]=i;}
    std::sort(P, P+N, [L](int a, int b){return L[a]<L[b];});

    int n_unb = 0;
    for (int i=0; i<N; i++) {
        int n_smaller_l = sum(P[i]);
        int n_larger_l = P[i]-n_smaller_l;
        int n_larger_r = (N-1-i)-n_larger_l;
        if (n_larger_l > 2*n_larger_r || n_larger_r > 2*n_larger_l) {
            n_unb++;
        }
        update(P[i], 1);
    }
    cout << n_unb << endl;
    fout << n_unb << endl;
}
