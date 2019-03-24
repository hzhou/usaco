//Harry Zhou
//50 mins
//First time I made a submission, I neglected to add caching, but it was a quick fix.
#define scanN() fscanf(fileIn, "%d\n", &N);
#define scanm(identifiers, ptrs...) fscanf(fileIn, #identifiers, ptrs);
#define scand(ptr) fscanf(fileIn, "%d\n", ptr);
#define scanld(ptr) fscanf(fileIn, "%ld\n", ptr);
#define scans(ptr) fscanf(fileIn, "%s\n", ptr);
#define scanmA(amount, identifiers, ptrs...) for (int i=0; i<amount; i++) {fscanf(fileIn, #identifiers, ptrs);}
#define scandA(amount, ptr) for (int i=0; i<amount; i++) {fscanf(fileIn, "%d", ptr);}
#define forN(amount) for (int i=0; i<amount; i++)
#define MOD 1000000007;

#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include <limits.h>
#include <vector>

struct barn {
    std::vector<int> connections;
    int poss[3];
    int fixedCol;
    int parent;
};

barn *barns;

int64_t getPoss(int n, int col);

int main() {
    FILE *fileIn = fopen("barnpainting.in", "r");
    FILE *fileOut = fopen("barnpainting.out", "w");

    int N, K;
    scanm(%d %d, &N, &K);
    barns = new barn[N];
    for (int i=0; i<N-1; i++) {
        int x, y;
        scanm(%d %d, &x, &y);
        x--; y--;
        barns[x].connections.push_back(y);
        barns[y].connections.push_back(x);
    }

    for (int i=0; i<N; i++) {
        barns[i].poss[0] = -1;
        barns[i].poss[1] = -1;
        barns[i].poss[2] = -1;
        barns[i].fixedCol = 0;
    }

    for (int i=0; i<K; i++) {
        int b, c;
        scanm(%d %d, &b, &c);
        b--;
        barns[b].fixedCol = c;
    }

    int64_t poss = getPoss(0, -1);
    printf("%ld\n", poss);
    fprintf(fileOut, "%ld\n", poss);
}

int64_t getPoss(int n, int pcol) {
    //printf("%d\n", n);
    int64_t tot = 0;
    if (barns[n].fixedCol == pcol) {
        return 0;
    }
    for (int col = 1; col <= 3; col++) {
        int64_t mult = 1;
        if (barns[n].fixedCol) {
            col = barns[n].fixedCol;
        }
        if (col == pcol) {continue;}
        if (barns[n].poss[col-1] == -1) {
            for (auto itr = barns[n].connections.begin(); itr != barns[n].connections.end(); itr++) {
                if (*itr == barns[n].parent) {
                    continue;
                }
                else {
                    barns[*itr].parent = n;
                    mult *= getPoss(*itr, col);
                    mult %= MOD;
                }
            }
            barns[n].poss[col-1] = mult;
        }
        else {
            mult = barns[n].poss[col-1];
        }
        tot += mult;
        tot %= MOD;
        if (barns[n].fixedCol) {
            break;
        }
    }
    return tot;
}
