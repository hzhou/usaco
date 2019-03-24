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

int main() {
    FILE *fileIn = fopen("hayfeast.in", "r");
    FILE *fileOut = fopen("hayfeast.out", "w");

    int N;
    int64_t M;
    scanm(%d %ld, &N, &M);
    int *bflavor = new int[N];
    int *bspice = new int[N];
    scanmA(N, %d %d, bflavor+i, bspice+i);

    int minSpice = INT_MAX;

    std::multiset<int> spices;
    int64_t flavor = 0;
    int b = 0;
    for (int a=0; a<N; a++) {
        while (flavor<M) {
            if (b==N) {
                goto exit;
            }
            spices.insert(bspice[b]);
            flavor += bflavor[b];
            b++;
        }

        int spice = *(spices.rbegin());
        if (spice < minSpice) {
            minSpice = spice;
        }

        /*printf("%d: ", spice);
        for (auto itr = spices.begin(); itr != spices.end(); itr++) {
            printf("%d ", *itr);
        }
        printf("\n");*/

        spices.erase(spices.find(bspice[a]));
        flavor -= bflavor[a];
    }
exit:

    printf("%d\n", minSpice);
    fprintf(fileOut, "%d\n", minSpice);
}
