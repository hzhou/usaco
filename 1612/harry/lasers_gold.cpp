//Harry Zhou
//30 min
//11-9-2019
//Pretty straightforward
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
    fin.open("lasers.in");
    std::ofstream fout;
    fout.open("lasers.out");

    int N;
    int srcx;
    int srcy;
    int barnx;
    int barny;
    fin >> N >> srcx >> srcy >> barnx >> barny;

    ipair *posts = new ipair[N];
    for (int i=0; i<N; i++) {
        fin >> posts[i].first >> posts[i].second;
    }

    map<int, vector<ipair>> xmap;
    map<int, vector<ipair>> ymap;
    for (int i=0; i<N; i++) {
        xmap[posts[i].first].push_back(posts[i]);
        ymap[posts[i].second].push_back(posts[i]);
    }

    map<ipair,int> dist;
    std::queue<ipair> queue;
    dist[make_pair(barnx,barny)] = 0;
    queue.push(make_pair(barnx, barny));
    while (!queue.empty()) {
        ipair pos = queue.front();
        queue.pop();
        int x = pos.first;
        int y = pos.second;

        if (x==srcx || y==srcy) {
            cout << dist[pos] << endl;
            fout << dist[pos] << endl;
            exit(0);
        }

        if (xmap.count(x)) {
            for (ipair adj : xmap[x]) {
                if (adj != pos) {
                    dist[adj] = dist[pos]+1;
                    queue.push(adj);
                }
            }
            xmap.erase(x);
        }
        if (ymap.count(y)) {
            for (ipair adj : ymap[y]) {
                if (adj != pos) {
                    dist[adj] = dist[pos]+1;
                    queue.push(adj);
                }
            }
            ymap.erase(y);
        }
    }
}
