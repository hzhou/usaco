//Harry Zhou
//10-27-2019
//1hr 10min
//Had to make dp[][][] as chars because there was not enough memory
//Also took a long time to find a bug where I set dp[0][1][log[0]] = 1;, which is wrong
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
    fin.open("taming.in");
    std::ofstream fout;
    fout.open("taming.out");

    int N;
    fin >> N;
    int *log = new int[N];
    for (int i=0; i<N; i++) {
        fin >> log[i];
    }

    char dp[102][102][102]; // dp[entry #][num breakouts][log value] = tampered entries
    for (int a=0; a<100; a++) {
        for (int b=0; b<101; b++) {
            for (int c=0; c<100; c++) {
                dp[a][b][c] = CHAR_MAX;
            }
        }
    }
    if (log[0] == 0) {dp[0][1][0] = 0;}
    else {dp[0][1][0] = 1;}

    for (int a=0; a<N-1; a++) {
        for (int b=1; b<=N; b++) {
            for (int c=0; c<N; c++) {
                if (dp[a][b][c] == CHAR_MAX) continue;
                dp[a+1][b][c+1] = std::min(dp[a+1][b][c+1], (char)(dp[a][b][c] + (c+1==log[a+1] ? 0 : 1))); //don't break
                dp[a+1][b+1][0] = std::min(dp[a+1][b+1][0], (char)(dp[a][b][c] + (0==log[a+1] ? 0 : 1))); //break
            }
        }
    }
    
    for (int b=1; b<=N; b++) {
        int min = CHAR_MAX;
        for (int c=0; c<N; c++) {
            if (dp[N-1][b][c] < min) {min = dp[N-1][b][c];}
        }
        cout << min << endl;
        fout << min << endl;
    }
}
