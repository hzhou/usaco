#include <cstdio>
#include <algorithm>
#include <limits.h>
#include <set>

int main() {
    FILE *fileIn = fopen("cbarn.in", "r");
    FILE *fileOut = fopen("cbarn.out", "w");

    int N;
    fscanf(fileIn, "%d", &N);

    std::multiset<int> *roomSets = new std::multiset<int>[N];
    for (int i=0; i<N; i++) {
        int cows;
        fscanf(fileIn, "%d", &cows);
        for (int j=0; j<cows; j++) {
            roomSets[i].insert(0);
        }
    }

    int totalDistance = 0;
    int hasEmptyCells = 1;
    while (hasEmptyCells) {
        hasEmptyCells = 0;

        for (int i = 0; i<N; i++) {
            if (roomSets[i].empty()) {
                hasEmptyCells = 1;

                auto *leftRoom = &roomSets[(i+N-1) % N];
                if (leftRoom->empty()) {
                    continue;
                }

                auto minLeftDist = leftRoom->begin();
                totalDistance += 2 * (*minLeftDist) + 1;
                roomSets[i].insert(*minLeftDist+1);
                roomSets[(i+N-1) % N].erase(minLeftDist);
            }
        }
    }

    printf("%d\n", totalDistance);
    fprintf(fileOut, "%d\n", totalDistance);
}
