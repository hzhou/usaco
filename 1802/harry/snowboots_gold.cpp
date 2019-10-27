//Harry Zhou
//10-26-2019
//45 min
//old problem
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
    fin.open("snowboots.in");
    std::ofstream fout;
    fout.open("snowboots.out");

    int N, B;
    fin >> N >> B;
    int *tiles = new int[N];
    for (int i=0; i<N; i++) {
        fin >> tiles[i];
    }

    ipair *boots = new ipair[N];
    for (int i=0; i<N; i++) {
        fin >> boots[i].first; //depth of snow
        fin >> boots[i].second; //step size
    }

    int *tile_ord = new int[N];
    int *boot_ord = new int[B];
    for (int i=0; i<N; i++) {tile_ord[i] = i;}
    for (int i=0; i<B; i++) {boot_ord[i] = i;}
    std::sort(tile_ord, tile_ord+N, [tiles](int a, int b){return tiles[a]>tiles[b];}); //sort tiles in decreasing order of snow depth
    std::sort(boot_ord, boot_ord+B, [boots](int a, int b){return boots[a]>boots[b];}); //sort boots in decreasing order of max depth it can step in

    int *can_step = new int[N];

    ipair *linked = new ipair[N];
    for (int i=0; i<N; i++) {linked[i] = make_pair(i-1, i+1);}
    int max_barrier = 1;

    int boot = 0;
    int tile = 0;
    for (boot; boot<B; boot++) {
        int bdepth = boots[boot_ord[boot]].first;
        int bstep = boots[boot_ord[boot]].second;
        while (tile < N && tiles[tile_ord[tile]] > bdepth) {
            int prev = linked[tile_ord[tile]].first;
            int next = linked[tile_ord[tile]].second;
            linked[prev].second = next;
            linked[next].first = prev;
            int size = next-prev;
            if (size>max_barrier) {max_barrier=size;}
            tile++;
        }
        if (bstep<max_barrier) {
            can_step[boot_ord[boot]] = 0;
        }
        else {
            can_step[boot_ord[boot]] = 1;
        }
    }

    for (int i=0; i<B; i++) {
        cout << can_step[i] << endl;
        fout << can_step[i] << endl;
    }
}
