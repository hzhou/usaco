//Harry Zhou
//2 hours 10 minutes
//9-20-2019
//I've done this problem before, but it still took a long time to work everything out.
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

#define MOD 1000000007

typedef long long int LL;

typedef std::pair<int,int> ipair;
typedef std::set<int> iset;
typedef std::map<int,int> imap;
typedef std::vector<int> ivec;
typedef std::stack<int> istack;
typedef std::priority_queue<ipair, std::vector<ipair>, std::greater<ipair>> dijkstra_priority_queue;

int ladd(LL a, LL b) {
    return (int) ((a+b) % MOD);
}
int lmul(LL a, LL b) {
    return (int) (a*b % MOD);
}
int modpow(LL x, LL y)
{
    LL res = 1;
    x = x % MOD;
    while (y > 0) {
        if (y & 1) res = (res*x) % MOD;
        y = y>>1;
        x = (x*x) % MOD;
    }
    return (int) res;
}

int main() {
    std::ifstream fin;
    fin.open("poetry.in");
    std::ofstream fout;
    fout.open("poetry.out");

    int N, M, K;
    fin >> N >> M >> K;

    ipair *words = new ipair[N];
    for (int i=0; i<N; i++) {
        fin >> words[i].first >> words[i].second;
    }

    char *scheme = new char[M];
    for (int i=0; i<M; i++) {
        fin >> scheme[i];
    }

    int* wordCount = new int[K];
    std::map<int, int*> rhymeCount;
    for (int i=0; i<N; i++) {
        int s = words[i].first-1;
        int c = words[i].second;
        wordCount[s]++;
        if (!rhymeCount.count(c)) {
            rhymeCount[c] = new int[K];
        }
        rhymeCount[c][s]++;
    }

    /*for (int i=0; i<K; i++) {
        std::cout << wordCount[i] << " ";
    }
    std::cout << std::endl;
    for (auto itr : rhymeCount) {
        for (int i=0; i<K; i++) {
            std::cout << itr.second[i] << " ";
        }
        std::cout << std::endl;
    }*/

    imap rhymeCombos;
    int *dp = new int[K+1];
    dp[0] = 1;
    for (int i=1; i<=K-1; i++) {
        for (int j=1; j<=i; j++) {
            dp[i] = ladd( dp[i] , lmul(dp[i-j],wordCount[j-1]) );
        }
    }
    for (auto rhyme = rhymeCount.begin(); rhyme != rhymeCount.end(); rhyme++) {
        int *s_count = rhyme->second;
        dp[K] = 0;
        for (int j=1; j<=K; j++) {
            dp[K] = ladd( dp[K] , lmul(dp[K-j],s_count[j-1]) );
        }
        rhymeCombos[rhyme->first] = dp[K];
    }

    /*for (auto combo : rhymeCombos) {
        std::cout << combo.second << std::endl;
    }*/

    std::map<char, int> schemeCount;
    for (int i=0; i<M; i++) {
        schemeCount[scheme[i]]++;
    }

    int res = 1;
    for (auto rhyme = schemeCount.begin(); rhyme != schemeCount.end(); rhyme++) {
        int sum = 0;
        int num_lines = rhyme->second;
        for (auto combo = rhymeCombos.begin(); combo != rhymeCombos.end(); combo++) {
            int num_combos = combo->second;
            sum = ladd(sum, modpow(num_combos, num_lines));
        }
        res = lmul(res, sum);
    }

    std::cout << res << std::endl;
    fout << res << std::endl;
}
