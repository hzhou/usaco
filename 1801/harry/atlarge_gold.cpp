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
#include <vector>
#include <stack>
#include <set>

struct barn {
    int parent;
    int level;
    std::vector<int> paths;
    std::vector<int> farmers;
    int merge;
};

int main() {
    FILE *fileIn = fopen("atlarge.in", "r");
    FILE *fileOut = fopen("atlarge.out", "w");

    int N, K;
    scanm(%d %d, &N, &K);
    K--;

    barn *barns = new barn[N];
    for (int i=0; i<N-1; i++) {
        int b1, b2;
        scanm(%d %d, &b1, &b2);
        b1--; b2--;
        barns[b1].paths.push_back(b2);
        barns[b2].paths.push_back(b1);
    }

    for (int i=0; i<N; i++) {
        barns[i].parent = -1;
    }

    int maxLevel = 0;
    std::stack<int> barnStack;
    barns[K].parent = K;
    barns[K].level = 0;
    barnStack.push(K);
    while (!barnStack.empty()) {
        int barn = barnStack.top();
        barnStack.pop();

        if (barns[barn].level > maxLevel) {
            maxLevel = barns[barn].level;
        }
        for (auto itr = barns[barn].paths.begin(); itr != barns[barn].paths.end(); itr++) {
            if (barns[*itr].parent == -1) {
                barns[*itr].parent = barn;
                barns[*itr].level = barns[barn].level + 1;
                barnStack.push(*itr);
            }
        }
    }
    
    //printf("maxLevel: %d\n", maxLevel);

    /*for (int i=0; i<N; i++) {
        printf("%d -> %d (%d)\n", i+1, barns[i].parent+1, barns[i].level);
    }*/

    std::set<int> activeBarns;
    for (int i=0; i<N; i++) {
        barns[i].merge = 0;
        if (barns[i].paths.size() == 1) {
            barns[i].farmers.push_back(0);
            //printf("%d\n", i+1);
            activeBarns.insert(i);
        }
    }

    while (maxLevel != 1) {
        std::vector<int> temp;
        for (auto bitr = activeBarns.begin(); bitr != activeBarns.end(); bitr++) {
            int parent = barns[*bitr].parent;

            if (parent == K || barns[*bitr].level != maxLevel) {
                temp.push_back(*bitr);
                //printf("excluded: %d\n", *bitr+1);
                continue;
            }

            //printf("barn: %d\n", *bitr+1);
            for (auto fitr = barns[*bitr].farmers.begin(); fitr != barns[*bitr].farmers.end(); fitr++) {
                barns[parent].farmers.push_back(*fitr+1);
                if (*fitr+1 <= barns[parent].level) {
                    barns[parent].merge = 1;
                }
            }
            barns[*bitr].farmers.clear();
            temp.push_back(parent);
        }
        
        activeBarns.clear();
        for (auto itr = temp.begin(); itr != temp.end(); itr++) {
            activeBarns.insert(*itr);
        }
        
        for (auto bitr = activeBarns.begin(); bitr != activeBarns.end(); bitr++) {
            if (barns[*bitr].merge) {
                //printf("%d\n", *bitr+1);
                int min = INT_MAX;
                for (auto fitr = barns[*bitr].farmers.begin(); fitr != barns[*bitr].farmers.end(); fitr++) {
                    if (*fitr < min) {
                        min = *fitr;
                    }
                }
                barns[*bitr].farmers.clear();
                barns[*bitr].farmers.push_back(min);
            }
        }

        maxLevel--;
    }

    int numFarmers = 0;
    for (int i=0; i<N; i++) {
        for (auto fitr = barns[i].farmers.begin(); fitr != barns[i].farmers.end(); fitr++) {
            numFarmers++;
        }
    }

    printf("%d\n", numFarmers);
    fprintf(fileOut, "%d\n", numFarmers);
}
