//Harry Zhou
#define scanN() fscanf(fileIn, "%d\n", &N);
#define scanm(identifiers, ptrs...) fscanf(fileIn, #identifiers, ptrs);
#define scand(ptr) fscanf(fileIn, "%d\n", ptr);
#define scanld(ptr) fscanf(fileIn, "%ld\n", ptr);
#define scans(ptr) fscanf(fileIn, "%s\n", ptr);
#define scanmA(amount, identifiers, ptrs...) for (int i=0; i<amount; i++) {fscanf(fileIn, #identifiers, ptrs);}
#define scandA(amount, ptr) for (int i=0; i<amount; i++) {fscanf(fileIn, "%d", ptr);}
#define forN(amount) for (int i=0; i<amount; i++)

#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include <limits.h>
#include <set>
#include <vector>

typedef std::pair<int,int> ipair;

struct connection {
    int v1;
    int v2;
    int r;
};

int getRoot(int node, ipair *forest);

int main() {
    FILE *fileIn = fopen("mootube.in", "r");
    FILE *fileOut = fopen("mootube.out", "w");

    int N, Q;
    scanm(%d %d, &N, &Q);

    std::vector<connection> connections;
    for (int i=0; i<N-1; i++) {
        int p, q, r;
        scanm(%d %d %d, &p, &q, &r);
        p--; q--;
        connections.push_back({p, q, r});
    }

    std::sort(connections.begin(), connections.end(), [](connection a, connection b){return a.r<b.r;});

    ipair *qL = new ipair[Q];
    for (int i=0; i<Q; i++) {
        int k, v;
        scanm(%d %d, &k, &v);
        v--;
        qL[i] = std::make_pair(k, v);
    }

    int *origOrder = new int[Q];
    for (int i=0; i<Q; i++) {
        origOrder[i] = i;
    }

    std::sort(origOrder, origOrder+Q, [qL](int a, int b){return qL[a]>qL[b];});
    std::sort(qL, qL+Q, [](ipair a, ipair b){return a>b;});

    ipair *forest = new ipair[N];
    for (int i=0; i<N; i++) {
        forest[i] = std::make_pair(i, 1);
    }

    int *ansL = new int[Q];
    for (int q=0; q<Q; q++) {
        int k = qL[q].first;
        int v = qL[q].second;

        while (!connections.empty() && connections.back().r >= k) {
            connection c = connections.back();
            connections.pop_back();
            int root1 = getRoot(c.v1, forest);
            int root2 = getRoot(c.v2, forest);
            forest[root1].second += forest[root2].second;
            forest[root2].first = root1;
        }

        int root = getRoot(v, forest);
        ansL[origOrder[q]] = forest[root].second-1;

        /*for (int i=0; i<N; i++) {
            printf("%d -> %d\n", i+1, forest[i].first+1);
        }
        printf("v: %d\n", v+1);
        printf("ans: %d\n", ansL[origOrder[q]]);
        printf("\n");*/
    }
    
    for (int i=0; i<Q; i++) {
        printf("%d\n", ansL[i]);
        fprintf(fileOut, "%d\n", ansL[i]);
    }
}

int getRoot(int node, ipair *forest) {
    while (forest[node].first != node) {
        node = forest[node].first;
    }
    return node;
}
