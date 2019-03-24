//Harry Zhou
//45 min
//This time the code is pretty hard to understand, I think
//I realized what I was doing wouldn't work part way through
//And I made quite a few changes in plan on the spot
//Here's what's going on with *possBad
//Originally, I was going just set the index of every bad milk to one
//but then I looked at the problem and realized that all three sick people had to drink the milk for it to be possibly bad
//So I changed it from possBad[drinks[j].m] = 1 to possBad[drinks[j].m]++; so that it represents the number of sick people who drank it
//That, of course, still doesn't work because in the loop, it's possible for the same milk to be incremented twice from a sick person drinking the same milk twice
//So I was considering completely restructuring my program, but then I thought I could just do a bitmap, representing the different sick people who drank that milk
//And that works
//The comparator represents the bitmap corresponding to all the sick people drinking the milk
#include <cstdio>
#include <algorithm>
#include <set>

struct drink {
    int p;
    int m;
    int t;
};

struct sick {
    int p;
    int t;
};

int main() {
    FILE *fileIn = fopen("badmilk.in", "r");
    FILE *fileOut = fopen("badmilk.out", "w");

    int N, M, D, S;
    fscanf(fileIn, "%d %d %d %d", &N, &M, &D, &S);
    
    drink *drinks = new drink[D];
    for (int i=0; i<D; i++) {
        int p,m,t;
        fscanf(fileIn, "%d %d %d", &p, &m, &t);
        drinks[i].p = p-1;
        drinks[i].m = m-1;
        drinks[i].t = t;
    }
    
    sick *sicks = new sick[S];
    for (int i=0; i<S; i++) {
        int p,t;
        fscanf(fileIn, "%d %d", &p, &t);
        sicks[i].p = p-1;
        sicks[i].t = t;
    }
    
    uint64_t *possBad = new uint64_t[M];
    for (int i=0; i<M; i++) {
        possBad[i] = 0;
    }
    for (int i=0; i<S; i++) {
        for (int j=0; j<D; j++) {
            //printf("%d %d\n", sicks[i].p, drinks[j].p);
            if (sicks[i].p==drinks[j].p && sicks[i].t > drinks[j].t) {
                possBad[drinks[j].m] |= (1<<drinks[j].p);
            }
        }
    }
    
    uint64_t comparator = 0;
    for (int i=0; i<S; i++) {
        comparator |= (1<<sicks[i].p);
    }
    std::set<int> badSet;
    for (int i=0; i<M; i++) {
        if (possBad[i] == comparator) {
            badSet.insert(i);
        }
    }
    
    int *possSick = new int[N];
    for (int i=0; i<N; i++) {
        possSick[i] = 0;
    }
    for (int i=0; i<D; i++) {
        if (badSet.count(drinks[i].m)) {
            possSick[drinks[i].p]++;
        }
    }

    int numSick = 0;
    for (int i=0; i<N; i++) {
        if (possSick[i]) {
            numSick++;
        }
    }

    printf("%d\n", numSick);
    fprintf(fileOut, "%d\n", numSick);
}
