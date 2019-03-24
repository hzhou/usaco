//Harry Zhou
//40 mins
//Mixed up i and j
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
#include <limits.h>
#include <unordered_set>
#include <vector>

struct pair {
    int x;
    int y;
    int operations;
};

int main() {
    FILE *fileIn = fopen("pails.in", "r");
    FILE *fileOut = fopen("pails.out", "w");

    int X, Y, K, M;
    fscanf(fileIn, "%d %d %d %d", &X, &Y, &K, &M);

    std::vector<pair> pairs;
    pair first_pair;
    first_pair.x = 0;
    first_pair.y = 0;
    first_pair.operations = 0;
    pairs.push_back(first_pair);

    std::unordered_set<int> existingPairs;
    existingPairs.insert(0);

    int minError = INT_MAX;
    int i = 0;
    while (i < pairs.size()) {
        
        int total = pairs[i].x + pairs[i].y;
        if (abs(M - total) < minError) {
            minError = abs(M-total);
        }

        //printf("operations: %d\n", pairs[i].operations);
        //printf("x: %d\n", pairs[i].x);
        //printf("y: %d\n", pairs[i].y);
        if (pairs[i].operations == K) {
            i++;
            continue;
        }

        pair op[6];
        op[0].x = X;
        op[0].y = pairs[i].y;

        op[1].x = pairs[i].x;
        op[1].y = Y;

        op[2].x = pairs[i].x;
        op[2].y = 0;

        op[3].x = 0;
        op[3].y = pairs[i].y;

        int dif = std::min(Y-pairs[i].y, pairs[i].x);
        op[4].x = pairs[i].x - dif;
        op[4].y = pairs[i].y + dif;

        dif = std::min(X-pairs[i].x, pairs[i].y);
        op[5].x = pairs[i].x + dif;
        op[5].y = pairs[i].y - dif;

        for (int j=0; j<6; j++) {
            op[j].operations = pairs[i].operations+1;
        }

        for (int j=0; j<6; j++) {
            int hash = op[j].y * 500 + op[j].x;
            //printf("%d\n", hash);
            if (!existingPairs.count(hash)) {
                pairs.push_back(op[j]);
                existingPairs.insert(hash);
            }
        }

        i++;
    }

    printf("%d\n", minError);
    fprintf(fileOut, "%d\n", minError);
}
