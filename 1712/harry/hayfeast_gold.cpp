//Harry Zhou
//10-12-2019
//15min
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

int main() {
    std::ifstream fin;
    fin.open("hayfeast.in");
    std::ofstream fout;
    fout.open("hayfeast.out");

    int N;
    LL M;
    fin >> N >> M;
    
    ipair *bales = new ipair[N];
    for (int i=0; i<N; i++) {
        fin >> bales[i].first >> bales[i].second;
    }

    int minSpice = INT_MAX;
    imap s_map;
    LL total_flavor = 0;
    int beg = 0;
    int end = 0;
    for (beg = 0; beg < N; beg++) {
        while (total_flavor < M) {
            if (end==N) {goto output;}
            total_flavor += bales[end].first;
            s_map[bales[end].second]++;
            end++;
        }
        int spice = s_map.rbegin()->first;
        minSpice = std::min(spice, minSpice);

        total_flavor -= bales[beg].first;
        s_map[bales[beg].second]--;
        if (s_map[bales[beg].second] == 0) {
            s_map.erase(bales[beg].second);
        }
    }

output:
    cout << minSpice << endl;
    fout << minSpice << endl;
}
