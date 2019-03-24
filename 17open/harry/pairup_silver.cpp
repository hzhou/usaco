//Harry Zhou
//15 mins
//forgot to initialize maxPair
#include <cstdio>
#include <algorithm>
#include <map>

int main() {
    FILE *fileIn = fopen("pairup.in", "r");
    FILE *fileOut = fopen("pairup.out", "w");

    int N;
    fscanf(fileIn, "%d", &N);

    std::map<int,int> cows;
    for (int i=0; i<N; i++) {
        int numCows;
        int output;
        fscanf(fileIn, "%d %d", &numCows, &output);
        if (!cows.count(output)) {
            cows[output] = 0;
        }
        cows[output] += numCows;
    }
    auto itr1 = cows.begin();
    auto itr2 = --cows.end();

    int maxPair = 0;
    while (itr1->first <= itr2->first) {
        int time = itr1->first + itr2->first;
        if (time > maxPair) {
            maxPair = time;
        }

        int pairNum = std::min(itr1->second, itr2->second);
        itr1->second-=pairNum;
        itr2->second-=pairNum;

        if (itr1->second <= 0) {
            itr1++;
        }
        if (itr2->second <= 0) {
            itr2--;
        }
    }

    printf("%d\n", maxPair);
    fprintf(fileOut, "%d\n", maxPair);
}
