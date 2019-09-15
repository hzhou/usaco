//Harry Zhou
//9-14-2019
//30min
//I never figured out why there was in inconsistency between my output and the testing machine's output but I noticed a different problem and everything worked after I fixed it
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

typedef std::pair<int,int> ipair;
typedef std::set<int> iset;
typedef std::map<int,int> imap;
typedef std::vector<int> ivec;
typedef std::stack<int> istack;
typedef std::priority_queue<ipair, std::vector<ipair>, std::greater<ipair>> dijkstra_priority_queue;

int main() {
    std::ifstream fin("teamwork.in");
    std::ofstream fout("teamwork.out");

    int N, K;
    fin >> N >> K;
    int *cows = new int[N+1];
    for (int i=1; i<=N; i++) {fin >> cows[i];}

    int dp[N+1];
    dp[0] = 0;
    for (int i=1; i<N+1; i++) {
        int max = 0;
        dp[i] = 0;
        for (int j=0; j<K && i-j>=1; j++) {
            max = std::max(cows[i-j], max);
            int sk = dp[i-j-1] + max*(j+1);
            dp[i] = std::max(dp[i], sk);
        }
    }

    std::cout << dp[N] << '\n';
    fout << dp[N] << '\n';
}
