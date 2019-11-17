//Harry Zhou
//50 min
//11-9-2019
//I was worried about running out of memory but looks like I was fine
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

int dp[1001][1001][2];

int dist(ipair a, ipair b) {
    int dx = a.first-b.first;
    int dy = a.second-b.second;
    return dx*dx + dy*dy;
}

int main() {
    std::ifstream fin;
    fin.open("checklist.in");
    std::ofstream fout;
    fout.open("checklist.out");

    int H, G;
    fin >> H >> G;

    ipair *hpos = new ipair[H];
    ipair *gpos = new ipair[H];
    for (int i=0; i<H; i++) {
        fin >> hpos[i].first;
        fin >> hpos[i].second;
    }
    for (int i=0; i<G; i++) {
        fin >> gpos[i].first;
        fin >> gpos[i].second;
    }

    for (int i=0; i<=H; i++) {
        for (int j=0; j<=G; j++) {
            dp[i][j][0] = INT_MAX;
            dp[i][j][1] = INT_MAX;
        }
    }

    dp[1][0][0] = 0;
    for (int h=0; h<=H; h++) {
        for (int g=0; g<=G; g++) {
            for (int s=0; s<2; s++) {
                if (dp[h][g][s] == INT_MAX) {continue;}
                /*cout << h << " " << g << " " << s << " ";
                cout << dp[h][g][s] << endl;*/

                ipair pos;
                if (s==0) {
                    pos = hpos[h-1];
                }
                else {
                    pos = gpos[g-1];
                }

                if (h<H) {
                    ipair pos2 = hpos[h];
                    int d = dist(pos, pos2);
                    dp[h+1][g][0] = std::min(dp[h+1][g][0], dp[h][g][s]+d);
                }
                if (g<G) {
                    ipair pos2 = gpos[g];
                    int d = dist(pos, pos2);
                    dp[h][g+1][1] = std::min(dp[h][g+1][1], dp[h][g][s]+d);
                }
            }
        }
    }

    cout << dp[H][G][0];
    fout << dp[H][G][0] << '\n';
}
