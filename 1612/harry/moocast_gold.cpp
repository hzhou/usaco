//Harry Zhou
//more than 1hr
//11-9-2019
//In the end, it was because I didn't use a reference in the capture
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
    fin.open("moocast.in");
    std::ofstream fout;
    fout.open("moocast.out");

    int N;
    fin >> N;

    ipair *coords = new ipair[N];
    for (int i=0; i<N; i++) {
        fin >> coords[i].first;
        fin >> coords[i].second;
    }

    vector<ipair> pairs;
    ivec pair_dists;
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            pairs.push_back(make_pair(i,j));
            int dx = coords[i].first-coords[j].first;
            int dy = coords[i].second-coords[j].second;
            pair_dists.push_back(dx*dx+dy*dy);
        }
    }
    int *perm = new int[pairs.size()];
    for (int i=0; i<pairs.size(); i++) {
        perm[i] = i;
    }
    std::sort(perm, perm + pairs.size(), [&pair_dists](int a, int b){return pair_dists[a]<pair_dists[b];});

    int *tree = new int[N];
    for (int i=0; i<N; i++) {
        tree[i] = i;
    }

    int separate_parts = N;
    for (int i=0; i<pairs.size(); i++) {
        int idx = perm[i];
        ipair p = pairs[idx];

        int r1 = p.first;
        int r2 = p.second;
        while (r1 != tree[r1]) {
            r1 = tree[r1];
        }
        while (r2 != tree[r2]) {
            r2 = tree[r2];
        }
        tree[p.first]=r1;
        tree[p.second]=r2;
        if (r1!=r2) {
            separate_parts--;
            if (separate_parts == 1) {
                cout << pair_dists[idx] << endl;
                fout << pair_dists[idx] << endl;
                exit(0);
            }
        }
        tree[r1]=r2;
    }
}
