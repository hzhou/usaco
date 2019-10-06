//Harry Zhou
//35 min
//10-5-2019
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
    fin.open("snakes.in");
    std::ofstream fout;
    fout.open("snakes.out");

    int N, K;
    fin >> N >> K;
    int *groups = new int[N];
    for (int i=0; i<N; i++) {
        fin >> groups[i];
    }

    int dp[400][400];
    int max_snakes = 0;
    for (int i=0; i<N; i++) {
        max_snakes = std::max(groups[i], max_snakes);
        dp[i][0] = max_snakes*(i+1);
    }

    for (int k=1; k<K+1; k++) {
        for (int n=0; n<N; n++) {
            int max_group = 0;
            dp[n][k] = dp[n][k-1];
            for (int i=n-1; i>=0; i--) {
                max_group = std::max(max_group, groups[i+1]);
                dp[n][k] = std::min(dp[n][k], max_group*(n-i)+dp[i][k-1]);
            }
        }
    }

    /*for (int x=0; x<K+1; x++) {
        for (int y=0; y<N; y++) {
            cout << dp[y][x] << " ";
        }
        cout << "\n";
    }*/

    int tot_space = dp[N-1][K];
    int tot_snakes = 0;
    for (int i=0; i<N; i++) {
        tot_snakes += groups[i];
    }
    int ans = tot_space-tot_snakes;

    cout << ans << endl;
    fout << ans << endl;;
}
