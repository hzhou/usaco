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
#include <queue>
#include <iterator>

struct pie {
    int myT;
    int yourT;

    int cost;

    int originalIndex;
    //int visited;

    pie() {}
    pie(int myT, int yourT, int originalIndex) {
        this->myT = myT;
        this->yourT = yourT;
        this->originalIndex = originalIndex;
        cost = INT_MAX;
        //visited = 0;
    }

    bool operator<(const pie &other) const {
        return yourT < other.yourT;
    }
    bool operator<(const int &other) const {
        return yourT < other;
    }
};

bool operator<(const int &i, const pie &p) {
    return i<p.yourT;
}

int N, D;
pie *bPies;
pie *ePies;

int main() {
    FILE *fileIn = fopen("piepie.in", "r");
    FILE *fileOut = fopen("piepie.out", "w");

    fscanf(fileIn, "%d %d", &N, &D);

    bPies = new pie[N];
    ePies = new pie[N];
    for (int i=0; i<N; i++) {
        int b, e;
        fscanf(fileIn, "%d %d", &b, &e);
        bPies[i] = pie(b, e, i);
    }
    for (int i=0; i<N; i++) {
        int b, e;
        fscanf(fileIn, "%d %d", &b, &e);
        ePies[i] = pie(e, b, i);
    }
    std::sort(bPies, bPies+N);
    std::sort(ePies, ePies+N);

    /*printf("\nBessie:\n");
    for (int i=0; i<N; i++) {
        printf("%d %d\n", bPies[i].myT, bPies[i].yourT);
    }
    printf("\nElsie:\n");
    for (int i=0; i<N; i++) {
        printf("%d %d\n", ePies[i].myT, ePies[i].yourT);
    }
    printf("\n");*/

    typedef std::pair<int, int> iPair;
    std::priority_queue< iPair, std::vector<iPair>, std::greater<iPair> > pieQueue;

    for (int idx = 0; idx < 2*N; idx++) {
        int arr_i = idx % N;
        int arr_side = idx / N;

        if (arr_side == 0) {
            if (bPies[arr_i].yourT != 0) {
                continue;
            }

            bPies[arr_i].cost = 1;
            pieQueue.push(std::make_pair(bPies[arr_i].cost, idx));
        }
        else {
            if (ePies[arr_i].yourT != 0) {
                continue;
            }

            ePies[arr_i].cost = 1;
            pieQueue.push(std::make_pair(ePies[arr_i].cost, idx));
        }
    }

    //for (int idx = 0; idx < 2*N; idx++) {
        while (!pieQueue.empty()) {
            auto top = pieQueue.top().second;
            pieQueue.pop();

            int i = top % N;
            int side = top / N;
            int cost;

            pie *begin;
            pie *end;
            if (side == 0) {
                begin = std::lower_bound(ePies, ePies+N, bPies[i].myT - D);
                end = std::upper_bound(ePies, ePies+N, bPies[i].myT);
                cost = bPies[i].cost;
                //printf("%d %d\n", begin - ePies, end - ePies);
                for (auto itr = begin; itr != end; itr++) {
                    if (itr->cost > cost+1) {
                        itr->cost = cost+1;
                        pieQueue.push(std::make_pair(cost+1, itr - ePies + N));
                    }
                }
            }
            else {
                begin = std::lower_bound(bPies, bPies+N, ePies[i].myT - D);
                end = std::upper_bound(bPies, bPies+N, ePies[i].myT);
                cost = ePies[i].cost;
                //printf("%d %d\n", begin - bPies, end - bPies);
                for (auto itr = begin; itr != end; itr++) {
                    if (itr->cost > cost+1) {
                        itr->cost = cost+1;
                        pieQueue.push(std::make_pair(cost+1, itr - bPies));
                    }
                }
            }
            //printf("(i, side, cost): (%d, %d, %d)\n", i, side, cost);
        }
        //printf("\n");
    //}

    std::sort(bPies, bPies+N, [](pie a, pie b){return a.originalIndex<b.originalIndex;});
    for (int i=0; i<N; i++) {
        int cost = bPies[i].cost;
        if (cost == INT_MAX) {
            cost = -1;
        }
        //printf("%d\n", cost);
        fprintf(fileOut, "%d\n", cost);
    }
}
